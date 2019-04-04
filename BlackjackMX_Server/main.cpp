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
using namespace std;
using namespace sf;

void server();

int main(int argc, const char * argv[]) {
    cout << "BlackjackMX Serveron\n";
    server();
    return 0;
}

void server(){
    TcpListener listener;
    TcpSocket client;
    
    listener.listen(53000);
    listener.accept(client);

    
    string data = "This is a string sended from the server";
    client.send(data.c_str(), data.length() + 1);
}
