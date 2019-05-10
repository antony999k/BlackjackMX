//
//  socketsServer.hpp
//  BlackjackMX_Server
//
//  Created by Antony Morales on 10/05/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#ifndef socketsServer_hpp
#define socketsServer_hpp

#include "sockets.hpp"
#include "game.hpp"

//Socker Server Classs
class SocketServer : public GenericSocket{
private:
    //Variables ************************
    TcpListener listener;
    Game game;
    vector<sf::TcpSocket*> clients;
public:
    //Functions ************************
    SocketServer(unsigned int port); //Init the server with constructor
    void sendPacketToAllClient();
    void sendPacketToClient(unsigned short int numClient);
    void waitForConnections();
};

#endif /* socketsServer_hpp */
