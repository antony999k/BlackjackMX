//
//  sockets.cpp
//  BlackjackMX
//
//  Created by Antony Morales on 04/04/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#include "sockets.hpp"
/* General functions
 *****************************************************************/

//userData struct Packet operation
sf::Packet& operator >>(sf::Packet& packet, userInteraction& packetData){
    return packet >> packetData.playerId >> packetData.cards >> packetData.cardsValue >> packetData.playerStatus >> packetData.playerMovement;
}

sf::Packet& operator <<(sf::Packet& packet, userInteraction& packetData){
    return packet << packetData.playerId << packetData.cards << packetData.cardsValue << packetData.playerStatus << packetData.playerMovement;
}

/* Generic Server functions
 *****************************************************************/
void GenericSocket::setPacket(userInteraction _gameData, sf::Uint32 _header){
    gameData = _gameData;
    header = _header;
    packet << header;
    packet << gameData;
}

void GenericSocket::savePacket(){
    packet >> header;
    packet >> gameData;
    packet.clear();
}

void GenericSocket::setHeader(sf::Uint32 _header){
    header = _header;
}

sf::Packet* GenericSocket::getPacket(){
    return &packet;
}

/* Socket Server functions
 *****************************************************************/
SocketServer::SocketServer(unsigned int port){
    cout << "************ BlackjackMX Server ************\n";
    tag = "[Server]";
    
    //Put the server start listen on a port
    if (listener.listen(port) != sf::Socket::Done)
    {
        cout << "\tError: Listening on port";
    }else{
        cout << tag << " Listening on port: " << port << endl;
    }
}


void SocketServer::waitForConnections(){
    sf::SocketSelector selector;
    // Add the listener to the selector
    selector.add(listener);
    
    while (1) {
        // Make the selector wait for data on any socket
        if (selector.wait()){
            // Test the listener
            if (selector.isReady(listener)){
                sf::TcpSocket* client = new sf::TcpSocket;
                if (listener.accept(*client) == sf::Socket::Done){
                    // Add the new client to the clients list
                    client->setBlocking(false);
                    clients.push_back(client);
                    // Add the new client to the selector so that we will be notified when he sends something
                    selector.add(*client);
                    cout << tag << " Conection established with: " << client->getRemoteAddress() << " on port " << client->getRemotePort() << endl;
                }else{
                    // Error, we won't get a new connection, delete the socket
                    delete client;
                    cout << tag << " Error: Client conection was rejected";
                }
            }else{
                // The listener socket is not ready, test all other sockets (the clients)
                sf::Uint32 i =0;
                for (std::vector<sf::TcpSocket*>::iterator it = clients.begin(); it != clients.end(); ++it){
                    sf::TcpSocket& client = **it;
                    if (selector.isReady(client)){
                        // The client has sent some data, we can receive it
                        if (client.receive(packet) == sf::Socket::Done)
                        {
                            savePacket();
                            setPacket(gameData, CREATE_USER);
                            sendPacketToClient(i);
                        }
                    }
                    i++;
                }
            }
        }
    }
}

void SocketServer::sendPacketToClient(unsigned short int numClient){
    clients[numClient]->send(packet);
    packet.clear();
}

void SocketServer::sendPacketToAllClient(){
    for (std::vector<sf::TcpSocket*>::iterator it = clients.begin(); it != clients.end(); ++it){
        sf::TcpSocket& client = **it;
        client.send(packet);
    }
    packet.clear();
}

/* Socket client functions
 *****************************************************************/
SocketClient::SocketClient(sf::IpAddress ip, unsigned int port){
    sf::Socket::Status status = socket.connect(ip, port);
    if (status != sf::Socket::Done)
    {
        cout << "ERROR: Imposible conect to the server" << endl;
    }
    socket.setBlocking(false);
    
    //Init game data empty
    gameData.playerId = NULL;
    gameData.cardsValue = 0;
    gameData.playerMovement = NULL;
    gameData.playerStatus = NULL;
    gameData.cards = "";
}

TcpSocket* SocketClient::getServerSocket(){
    return &socket;
}

void SocketClient::sendPacketToServer(){
    socket.send(packet);
    packet.clear();
}

void SocketClient::waitForConnections(){
    if (socket.receive(packet) == sf::Socket::Done)
    {
        savePacket();
    }
}
