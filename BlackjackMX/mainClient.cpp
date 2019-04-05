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
#include "sockets.hpp"

using namespace sf;
using namespace std;

int main(int argc, const char * argv[]) {
    /*
    char buffer[1000];
    std::size_t recieved;
    
    cout << "Client init\n";
    sf::TcpSocket socket;
    sf::IpAddress ip = sf::IpAddress::getLocalAddress();
    
    sf::Socket::Status status = socket.connect(ip, 53000);
    if (status != sf::Socket::Done)
    {
        cout << "ERROR: Imposible conect to the server" << endl;
    }
    
    //User recieve packet data and print
    sf::Packet packet;
    userData packetData;
    if (socket.receive(packet) != sf::Socket::Done)
    {
        cout << "ERROR: Reciving data from the server" << endl;
    }else{
        packet >> packetData;
        cout << "data: " << packetData.name << ", " << endl;
    }*/
    
    Game game;
    return 0;
}
