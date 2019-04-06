//
//  main.cpp
//  BlackjackMX
//
//  Created by Antony Morales on 02/03/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#include <iostream>
#include <SFML/Network.hpp>
#include "sockets.hpp"

using namespace sf;
using namespace std;

int main(int argc, const char * argv[]) {
    sf::IpAddress ip = sf::IpAddress::getLocalAddress();
    
    SocketClient socketClient(ip,53000);
    
    //User recieve packet data and print
    sf::Packet packet;
    recvPacket(packet, socketClient.getServer());
    
    return 0;
}
