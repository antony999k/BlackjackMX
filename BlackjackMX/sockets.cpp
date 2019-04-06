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
    return packet >> packetData.playerId >> packetData.operationType >> packetData.cards >> packetData.cardsValue >> packetData.playerStatus >> packetData.playerMovement;
}

sf::Packet& operator <<(sf::Packet& packet, userInteraction& packetData){
    return packet << packetData.playerId << packetData.operationType << packetData.cards << packetData.cardsValue << packetData.playerStatus << packetData.playerMovement;
}

void recvPacket(Packet packet, TcpSocket *socket){
    userInteraction packetData;
    if (socket->receive(packet) != sf::Socket::Done)
    {
        cout << "ERROR: Reciving data from the server" << endl;
    }else{
        packet >> packetData;
        cout << "data: " << packetData.playerId << endl;
    }
}

void sendPacket(Packet packet, TcpSocket *socket){
    //Send packet
    socket->send(packet);
}

/* Socket Server functions
 *****************************************************************/
SocketServer::SocketServer(unsigned int port){
    cout << "************ BlackjackMX Server ************\n";
    string tag = "[Server]";
    
    //Put the server start listen on a port
    if (listener.listen(port) != sf::Socket::Done)
    {
        cout << "\tError: Listening on port";
    }else{
        cout << tag << " Listening on port: " << port << endl;
    }
    
    // accept a new connection
    if (listener.accept(client) != sf::Socket::Done)
    {
        cout << "\tError: Client conection was rejected";
    }else{
        cout << tag << " Conection established with: " << client.getRemoteAddress() << " on port " << client.getRemotePort() << endl;
    }
}

TcpSocket* SocketServer::getClient(){
    return &client;
}

/* Socket client functions
 *****************************************************************/
SocketClient::SocketClient(sf::IpAddress ip, unsigned int port){
    sf::Socket::Status status = socket.connect(ip, port);
    if (status != sf::Socket::Done)
    {
        cout << "ERROR: Imposible conect to the server" << endl;
    }
}

TcpSocket* SocketClient::getServer(){
    return &socket;
}
