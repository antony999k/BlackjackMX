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
using namespace std;
using namespace sf;

//Structure that will be exchanged between the user and the server
typedef struct userInteraction_struct{
    sf::Uint16 playerId;
    string cards;
    sf::Uint16 cardsValue;
    unsigned char playerStatus;
    unsigned char playerMovement;
}userInteraction;

//userData struct Packet operation
sf::Packet& operator >>(sf::Packet& packet, userInteraction& packetData);
sf::Packet& operator <<(sf::Packet& packet, userInteraction& packetData);

//Recieve a Packet
void recvPacket(TcpSocket *socket);

class GenericSocket{
protected:
    //Variables ************************
    TcpSocket socket;
    sf::Packet packet;
    userInteraction gameData;
    sf::Uint32 header;
    string tag;
public:
    //Send a Packet
    void sendPacket();
    void setPackage(userInteraction _gameData, sf::Uint32 _header); //set package data in local class variables
    void getPacket(sf::Packet _packet);
    void printHeader();
};

//Socker Server Classs
class SocketServer : public GenericSocket{
    //Variables ************************
    TcpListener listener;
    vector<sf::TcpSocket*> clients;
public:
    //Functions ************************
    SocketServer(unsigned int port); //Init the server with contructor
    void waitForConnections();
};

//Socker Client(Player) Classs
class SocketClient : public GenericSocket{
public:
    SocketClient(sf::IpAddress ip, unsigned int port); //Init the client with constructor
    TcpSocket*getServer(); //Return the direction memory of the server socket
};

#endif /* sockets_hpp */
