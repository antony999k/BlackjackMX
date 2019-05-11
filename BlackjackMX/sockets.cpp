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

//createUserChunck struct Packet operation
sf::Packet& operator >>(sf::Packet& packet, createUserChunck& packetData){
    return packet >> packetData.playerId >> packetData.name;
}

sf::Packet& operator <<(sf::Packet& packet, createUserChunck& packetData){
    return packet << packetData.playerId << packetData.name;
}

//userChunk struct Packet operation
sf::Packet& operator >>(sf::Packet& packet, userChunk& packetData){
    return packet >> packetData.playerId >> packetData.username >> *packetData.cards >> packetData.cardsValue >> packetData.playerMovement >> packetData.playerStatus;
}

sf::Packet& operator <<(sf::Packet& packet, userChunk& packetData){
    return packet << packetData.playerId << packetData.username << *packetData.cards << packetData.cardsValue << packetData.playerMovement << packetData.playerStatus;
}

//dealerChunk struct Packet operation
sf::Packet& operator >>(sf::Packet& packet, dealerChunk& packetData){
    return packet >> *packetData.cards >> packetData.cardsValue;
}

sf::Packet& operator <<(sf::Packet& packet, dealerChunk& packetData){
    return packet << *packetData.cards << packetData.cardsValue;
}

//gameChunk struct Packet operation
sf::Packet& operator >>(sf::Packet& packet, gameChunk& packetData){
    return packet >> packetData.gameStatus >> packetData.turnPlayerId >> *packetData.userData >> packetData.dealerData;
}

sf::Packet& operator <<(sf::Packet& packet, gameChunk& packetData){
    return packet << packetData.gameStatus << packetData.turnPlayerId  << *packetData.userData << packetData.dealerData;
}


/* Generic Server functions
 *****************************************************************/
//set game package data in local class variables
void GenericSocket::setGamePacket(gameChunk _gameData, sf::Uint32 _header){
    gameData = _gameData;
    header = _header;
    packet << header;
    packet << gameData;
}

//set user package data in local class variables
void GenericSocket::setUserPacket(createUserChunck _userData, sf::Uint32 _header){
    userData = _userData;
    header = _header;
    packet << header;
    packet << userData;
}

//set game package data in local class variables
void GenericSocket::saveGamePacket(){
    packet >> gameData;
    cout << "(saveGamePacket) Total value: " << gameData.userData[0].cardsValue << endl;
    cout << "(saveGamePacket) Player id: " << gameData.userData[0].playerId << endl;
    packet.clear();
}


void GenericSocket::saveUserPacket(){
    packet >> userData;
    packet.clear();
}

void GenericSocket::saveHeader(){
    packet >> header;
}
/*
void GenericSocket::setHeader(sf::Uint32 _header){
    header = _header;
}
 */
    
sf::Packet* GenericSocket::getPacket(){
    return &packet;
}


/* Socket client functions
 *****************************************************************/
void SocketClient::connect(sf::IpAddress ip, unsigned int port){
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
        saveHeader();
        cout << "(waitForConnections) header: " << header << endl;
        //CREATE_USER, MOVEMENT, ERROR, EXIT
        if(header == CREATE_USER){
            saveUserPacket();
        }else{
            cout << "(waitForConnections) MOVEMENT!!!" << endl;
            saveGamePacket();
        }
    }
}
