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
#include <SFML/Network.hpp>
using namespace std;
using namespace sf;

//Structure that will be exchanged between the user and the server
typedef struct userInteraction_struct{
    sf::Uint16 playerId;
    unsigned char operationType;
    string cards;
    sf::Uint16 cardsValue;
    unsigned char playerStatus;
    unsigned char playerMovement;
}userInteraction;

//userData struct Packet operation
sf::Packet& operator >>(sf::Packet& packet, userInteraction& packetData);
sf::Packet& operator <<(sf::Packet& packet, userInteraction& packetData);

//Recieve a Packet
void recvPacket(Packet packet, TcpSocket *socket);

//Send a Packet
void sendPacket(Packet packet, TcpSocket *socket);

//Socker Server Classs
class SocketServer{
    //Variables ************************
    TcpListener listener;
    TcpSocket client;
public:
    //Functions ************************
    //Init the server with contructor
    SocketServer(unsigned int port);
    TcpSocket*getClient(); //Return the direction memory of the client socket
};

//Socker Client(Player) Classs
class SocketClient{
    //Variables ************************
    TcpSocket socket;
public:
    SocketClient(sf::IpAddress ip, unsigned int port);
    TcpSocket*getServer(); //Return the direction memory of the server socket
};

#endif /* sockets_hpp */
