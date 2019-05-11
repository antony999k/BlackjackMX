//
//  socketsServer.cpp
//  BlackjackMX_Server
//
//  Created by Antony Morales on 10/05/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#include "socketsServer.hpp"

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

/* Wait for conection in a loop
 *****************************************************************/
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
                    cout << tag << " Conection established with: " << client->getRemoteAddress() << ":" << client->getRemotePort() << endl;
                }else{
                    // Error, we won't get a new connection, delete the socket
                    delete client;
                    cout << tag << " Error: Client conection was rejected";
                }
            }else{
                // The listener socket is not ready, test all other sockets (the clients)
                sf::Uint32 itUserId = 1;
                for (std::vector<sf::TcpSocket*>::iterator it = clients.begin(); it != clients.end(); ++it){
                    sf::TcpSocket& client = **it;
                    if (selector.isReady(client)){
                        // The client has sent some data, we can receive it
                        if (client.receive(packet) == sf::Socket::Done){
                            saveHeader();
                            switch (header) {
                                case 0:
                                    saveUserPacket();
                                    //Set a random username and a port to the player in the game
                                    game.setPlayer("Usuario" + to_string(1 + rand() % 1000), to_string(client.getRemotePort()), game.setGetPlayerId(itUserId, client.getRemotePort()));
                                    setUserPacket(game.getUserData(), CREATE_USER); //CREATE_USER, MOVEMENT, ERROR, EXIT
                                    sendPacketToClient(itUserId);
                                    break;
                                case 1:
                                    saveUserPacket();
                                    game.playerMovement(userData.playerId, userData.playerMovement);
                                    break;
                                default:
                                    break;
                            }
                        }
                    }
                    itUserId++;
                }
                if(clients.size() >= 2){
                    cout << "###### GAME START ########" << endl;;
                    game.initGame();
                    setGamePacket(game.getGameData(), MOVEMENT);  //CREATE_USER, MOVEMENT, ERROR, EXIT
                    sendPacketToAllClient();
                }
            }
        }
    }
}

void SocketServer::sendPacketToClient(unsigned short int numClient){
    clients[numClient - 1]->send(packet);
    packet.clear();
}

void SocketServer::sendPacketToAllClient(){
    for (std::vector<sf::TcpSocket*>::iterator it = clients.begin(); it != clients.end(); ++it){
        sf::TcpSocket& client = **it;
        client.send(packet);
    }
    packet.clear();
}
