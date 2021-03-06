//
//  main.cpp
//  BlackjackMX_Server
//
//  Created by Antony Morales and Esmeralda Magadaleno on 04/04/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#include <iostream>
#include <string.h>
#include "socketsServer.hpp"
#include "blackjack.hpp"
using namespace std;

// FUNCTION DECLARATIONS
void instructions(string program);

int main(int argc, const char * argv[]) {
    
    // Check the correct arguments
    if(argv[1]==NULL){
        instructions(argv[0]);
    }
    SocketServer socketServer(stoi(argv[1]));
    socketServer.waitForConnections();
    
    return 0;
}

//Explanation to the user of the parameters required to run the program
void instructions(string program){
    cout << "Usage:" << endl;
    cout << "\t" << program << "{port_number}" << endl;
    exit(EXIT_FAILURE);
}
