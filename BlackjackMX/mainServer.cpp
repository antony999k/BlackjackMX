//
//  main.cpp
//  BlackjackMX_Server
//
//  Created by Antony Morales on 04/04/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <SFML/Network.hpp>
#include "sockets.hpp"
using namespace std;
using namespace sf;


// FUNCTION DECLARATIONS
void instructions(string program);
void server(unsigned int port);

int main(int argc, const char * argv[]) {
    // Check the correct arguments
    if(argv[1]==NULL){
        instructions(argv[0]);
    }
    cout << "************ BlackjackMX Server ************\n";
    //printTest();
    server(stoi(argv[1]));
    return 0;
}

void server(unsigned int port){
    TcpListener listener;
    TcpSocket client;
    string tag = "[Server]";
    
    //Put the server start listen on a port
    if (listener.listen(port) != sf::Socket::Done)
    {
        cout << "\tError: Listening on port";
    }else{
        cout << tag << " Listening on port: " << port << endl;
    }
    
    // accept a new connection
    if (listener.accept(client) != sf::Socket::Done)
    {
        cout << "\tError: Client conection was rejected";
    }else{
        cout << tag << " Conection established with: " << client.getRemoteAddress() << " on port " << client.getRemotePort() << endl;
    }
    
    //Prepare packet to send
    userData packetData;
    packetData.name = "Antony999kk";
    //Init packet and asign struct
    sf::Packet packet;
    packet << packetData;
    
    //Send packet
    client.send(packet);
}


//Explanation to the user of the parameters required to run the program
void instructions(string program){
    cout << "Usage:" << endl;
    cout << "\t" << program << "{port_number}" << endl;
    exit(EXIT_FAILURE);
}
