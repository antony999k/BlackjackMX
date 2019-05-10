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

//userChunk struct Packet operation
sf::Packet& operator >>(sf::Packet& packet, userChunk& packetData){
    return packet >> packetData.playerId >> packetData.username >> packetData.cards >> packetData.cardsValue >> packetData.playerMovement >> packetData.playerStatus;
}

sf::Packet& operator <<(sf::Packet& packet, userChunk& packetData){
    return packet << packetData.playerId << packetData.username << packetData.cards << packetData.cardsValue << packetData.playerMovement << packetData.playerStatus;
}

//dealerChunk struct Packet operation
sf::Packet& operator >>(sf::Packet& packet, dealerChunk& packetData){
    return packet >> packetData.cardsValue >> packetData.cards;
}

sf::Packet& operator <<(sf::Packet& packet, dealerChunk& packetData){
    return packet << packetData.cardsValue << packetData.cards;
}

//gameChunk struct Packet operation
sf::Packet& operator >>(sf::Packet& packet, gameChunk& packetData){
    return packet >> packetData.turnPlayerId >> packetData.gameStatus >> *packetData.userData >> packetData.dealerData;
}

sf::Packet& operator <<(sf::Packet& packet, gameChunk& packetData){
    return packet << packetData.turnPlayerId << packetData.gameStatus << *packetData.userData << packetData.dealerData;
}


/* Generic Server functions
 *****************************************************************/
void GenericSocket::setPacket(gameChunk _gameData, sf::Uint32 _header){
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
    gameData.turnPlayerId = NULL;
    gameData.gameStatus =NULL;
    /*
    gameData.playerId = NULL;
    gameData.cardsValue = 0;
    gameData.playerMovement = NULL;
    gameData.playerStatus = NULL;
     */
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
