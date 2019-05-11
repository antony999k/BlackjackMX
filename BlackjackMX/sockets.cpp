//
//  sockets.cpp
//  BlackjackMX
//
//  Created by Antony Morales and Esmeralda Magadaleno on 04/04/19.
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
    return packet >> packetData.playerId >> packetData.username >> packetData.cards[0] >> packetData.cards[1] >> packetData.cards[2] >> packetData.cards[3] >> packetData.cards[4] >> packetData.cards[5] >> packetData.cards[6] >> packetData.cards[7] >> packetData.cards[8] >> packetData.cards[9] >> packetData.cards[10] >> packetData.cards[11] >> packetData.cards[12] >> packetData.cards[13] >> packetData.cards[14] >> packetData.cards[15] >> packetData.cards[16] >> packetData.cards[17] >> packetData.cards[18] >> packetData.cards[19] >> packetData.cards[20] >> packetData.cards[21] >> packetData.cards[22] >> packetData.cards[23] >> packetData.cardsValue >> packetData.playerMovement >> packetData.playerStatus >> packetData.numCards;
}

sf::Packet& operator <<(sf::Packet& packet, userChunk& packetData){
    return packet << packetData.playerId << packetData.username << packetData.cards[0] << packetData.cards[1] << packetData.cards[2] << packetData.cards[3] << packetData.cards[4] << packetData.cards[5] << packetData.cards[6] << packetData.cards[7] << packetData.cards[8] << packetData.cards[9] << packetData.cards[10] << packetData.cards[11] << packetData.cards[12] << packetData.cards[13] << packetData.cards[14] << packetData.cards[15] << packetData.cards[16] << packetData.cards[17] << packetData.cards[18] << packetData.cards[19] << packetData.cards[20] << packetData.cards[21] << packetData.cards[22] << packetData.cards[23] << packetData.cardsValue << packetData.playerMovement << packetData.playerStatus << packetData.numCards;
}

//dealerChunk struct Packet operation
sf::Packet& operator >>(sf::Packet& packet, dealerChunk& packetData){
    return packet >> packetData.cards[0] >> packetData.cards[1] >> packetData.cards[2] >> packetData.cards[3] >> packetData.cards[4] >> packetData.cards[5] >> packetData.cards[6] >> packetData.cards[7] >> packetData.cards[8] >> packetData.cards[9] >> packetData.cards[10] >> packetData.cards[11] >> packetData.cards[12] >> packetData.cards[13] >> packetData.cards[14] >> packetData.cards[15] >> packetData.cards[16] >> packetData.cards[17] >> packetData.cards[18] >> packetData.cards[19] >> packetData.cards[20] >> packetData.cards[21] >> packetData.cards[22] >> packetData.cards[23] >> packetData.cardsValue >> packetData.numCards;
}

sf::Packet& operator <<(sf::Packet& packet, dealerChunk& packetData){
    return packet << packetData.cards[0] << packetData.cards[1] << packetData.cards[2] << packetData.cards[3] << packetData.cards[4] << packetData.cards[5] << packetData.cards[6] << packetData.cards[7] << packetData.cards[8] << packetData.cards[9] << packetData.cards[10] << packetData.cards[11] << packetData.cards[12] << packetData.cards[13] << packetData.cards[14] << packetData.cards[15] << packetData.cards[16] << packetData.cards[17] << packetData.cards[18] << packetData.cards[19] << packetData.cards[20] << packetData.cards[21] << packetData.cards[22] << packetData.cards[23] << packetData.cardsValue << packetData.numCards;
}

//gameChunk struct Packet operation
sf::Packet& operator >>(sf::Packet& packet, gameChunk& packetData){
    return packet >> packetData.gameStatus >> packetData.turnPlayerId >> packetData.userData[0] >> packetData.userData[1] >> packetData.userData[2] >> packetData.userData[3] >> packetData.dealerData;
}

sf::Packet& operator <<(sf::Packet& packet, gameChunk& packetData){
    return packet << packetData.gameStatus << packetData.turnPlayerId << packetData.userData[0] << packetData.userData[1] << packetData.userData[2] << packetData.userData[3] << packetData.dealerData;
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

void GenericSocket::displayDataChunk(){
    int i2 = 0;
    cout << "************** GAME Data Chunk ******************" << endl;
    cout << "gameStatus: " << gameData.gameStatus << endl;
    cout << "turnPlayerId: " << gameData.turnPlayerId << endl;
    cout << "\tdealerData.cardsValue: " << gameData.dealerData.cardsValue << endl;
    cout << "\tdealerData.numCards: " << gameData.dealerData.numCards << endl;
    for(int i = 0; i<gameData.dealerData.numCards; i++){
        cout << "\tdealerData.card("<< i << "): " << gameData.dealerData.cards[i2] << "-" << gameData.dealerData.cards[i2+1] << endl;
        i2+=2;
    }
    cout << "----------------Players---------------------" << endl;
    for(int j = 0; j<MAX_NUM_PLAYERS; j++){
        cout << "\tuserData["<< j<<"].playerId: " << gameData.userData[j].playerId << endl;
        cout << "\tuserData["<< j<<"].cardsValue: " << gameData.userData[j].cardsValue << endl;
        cout << "\tuserData["<< j<<"].playerMovement: " << gameData.userData[j].playerMovement << endl;
        cout << "\tuserData["<< j<<"].playerStatus: " << gameData.userData[j].playerStatus << endl;
        cout << "\tuserData["<< j<<"].username: " << gameData.userData[j].username << endl;
        cout << "\tuserData["<< j<<"].numCards: " << gameData.userData[j].numCards << endl;
        i2=0;
        for(int k = 0; k<gameData.userData[j].numCards; k++){
            cout << "\t\tuserData["<< j<<"].card("<< k << "): " << gameData.userData[j].cards[i2] << "-" << gameData.userData[j].cards[i2+1] << endl;
            i2+=2;
        }
        if(j!=MAX_NUM_PLAYERS-1){
            cout << "--------------------------------------------" << endl;
        }
    }
    cout << "**************************************************" << endl;
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
    
    dataChanged = false; //If initial gama info is loaded
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
        if(header == CREATE_USER){
            saveUserPacket();
        }else{
            saveGamePacket();
            dataChanged = true;
        }
    }
}
