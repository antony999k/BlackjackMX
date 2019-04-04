//
//  main.cpp
//  BlackjackMX_Server
//
//  Created by Antony Morales on 04/04/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <vector>
#include <SFML/Network.hpp>
using namespace std;
using namespace sf;

///// FUNCTION DECLARATIONS
void instructions(string program);
void server(unsigned int port);

int main(int argc, const char * argv[]) {
    // Check the correct arguments
    if(argv[1]==NULL){
        instructions(argv[0]);
    }
    cout << "************ BlackjackMX Server ************\n";
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
    
    //listener.accept(client);
    if (listener.accept(client) != sf::Socket::Done)
    {
        cout << "\tError: Client conection was rejected";
    }else{
        cout << tag << " Conection established with: " << client.getRemoteAddress() << " on port " << client.getRemotePort() << endl;
    }

    
    string data = "This is a string sended from the server";
    client.send(data.c_str(), data.length() + 1);
}


//Explanation to the user of the parameters required to run the program
void instructions(string program){
    cout << "Usage:" << endl;
    cout << "\t" << program << "{port_number}" << endl;
    exit(EXIT_FAILURE);
}
