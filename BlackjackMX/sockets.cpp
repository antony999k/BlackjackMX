//
//  sockets.cpp
//  BlackjackMX
//
//  Created by Antony Morales on 04/04/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#include "sockets.hpp"

//userData struct Packet operation
sf::Packet& operator >>(sf::Packet& packet, userData& packetData){
    return packet >> packetData.type >> packetData.name >> packetData.d2;
}

sf::Packet& operator <<(sf::Packet& packet, userData& packetData){
    return packet << packetData.type << packetData.name << packetData.d2;
}
