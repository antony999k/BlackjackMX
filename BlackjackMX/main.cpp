//
//  main.cpp
//  BlackjackMX
//
//  Created by Antony Morales on 02/03/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "game.hpp"

using namespace sf;
using namespace std;

int main(int argc, const char * argv[]) {
    char buffer[1000];
    std::size_t recieved;
    
    cout << "Client init\n";
    sf::TcpSocket socket;
    sf::IpAddress ip = sf::IpAddress::getLocalAddress();
    
    socket.connect(ip, 53000);
    socket.receive(buffer, sizeof(buffer), recieved);
    cout << "data: " << buffer << endl;
    
    //Game game;
    return 0;
}
