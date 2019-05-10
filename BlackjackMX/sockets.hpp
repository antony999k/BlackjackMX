//
//  sockets.hpp
//  BlackjackMX
//
//  Created by Antony Morales on 04/04/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#ifndef sockets_hpp
#define sockets_hpp

#include <iostream>
#include <string.h>
#include <vector>
#include <SFML/Network.hpp>
#include "CODES.hpp"
#include "game.hpp"
using namespace std;
using namespace sf;

//userData struct Packet operation
sf::Packet& operator >>(sf::Packet& packet, userChunk& packetData);
sf::Packet& operator <<(sf::Packet& packet, userChunk& packetData);

class GenericSocket{
protected:
    //Variables ************************
    sf::Packet packet;
    sf::Uint32 header;
    string tag;
public:
    userChunk gameData;
    void setPacket(userChunk _gameData, sf::Uint32 _header); //set package data in local class variables
    void setHeader(sf::Uint32 _header); //The the variable header
    void savePacket();
    sf::Packet*getPacket();
};

//Socker Server Classs
class SocketServer : public GenericSocket{
    //Variables ************************
    TcpListener listener;
    vector<sf::TcpSocket*> clients;
public:
    //Functions ************************
    SocketServer(unsigned int port); //Init the server with constructor
    void sendPacketToAllClient();
    void sendPacketToClient(unsigned short int numClient);
    void waitForConnections();
};

//Socker Client(Player) Classs
class SocketClient : public GenericSocket{
    TcpSocket socket;
public:
    SocketClient(sf::IpAddress ip, unsigned int port); //Init the client with constructor
    void sendPacketToServer(); //Send a Packet to a server
    TcpSocket*getServerSocket(); //Return the direction memory of the server socket
    void waitForConnections();
};

#endif /* sockets_hpp */
