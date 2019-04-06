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
#include "CODES.hpp"

using namespace sf;
using namespace std;

int main(int argc, const char * argv[]) {
    sf::IpAddress ip = sf::IpAddress::getLocalAddress();
    
    userInteraction gameData;
    sf::Uint32 _header = CREATE;
    
    SocketClient socketClient(ip,53000);
    socketClient.setPackage(gameData, _header);
    socketClient.sendPacket();

    return 0;
}
