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
#include <SFML/Network.hpp>
using namespace std;

//Structure that will be exchanged between the user and the server
typedef struct userData_struct{
    sf::Uint8 type;
    std::string name;
    float d2;
}userData;

//userData struct Packet operation
sf::Packet& operator >>(sf::Packet& packet, userData& packetData);
sf::Packet& operator <<(sf::Packet& packet, userData& packetData);

#endif /* sockets_hpp */
