//
//  main.cpp
//  BlackjackMX
//
//  Created by Antony Morales on 02/03/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#include <iostream>
#include <unistd.h>
#include <SFML/Network.hpp>
#include "sockets.hpp"
#include "CODES.hpp"

using namespace sf;
using namespace std;

int main(int argc, const char * argv[]) {
    sf::IpAddress ip = sf::IpAddress::getLocalAddress();
    
    userInteraction gameData;
    sf::Uint32 _header = 6;
    
    SocketClient socketClient(ip,53000);
    socketClient.setPackage(gameData, 9);
    socketClient.sendPacket();
    
    cout << "Go to bed\n";
    sleep(5);
    socketClient.setPackage(gameData, 5);
    socketClient.printHeader();
    socketClient.sendPacket();
    
    cout << "Bye :)\n";

    return 0;
}
