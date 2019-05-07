//
//  CODES.h
//  BlackjackMX
//
//  Created by Antony Morales on 05/04/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#ifndef CODES_h
#define CODES_h

#include <SFML/Network.hpp>

//Structure that will be exchanged between the user and the server
typedef struct userInteraction_struct{
    sf::Uint16 playerId;
    std::string cards;
    sf::Uint16 cardsValue;
    unsigned char playerStatus;
    unsigned char playerMovement;
}userInteraction;

// The different types of sockets operation available
typedef enum valid_operations {CREATE_USER, MOVEMENT, ERROR, EXIT} operation_t;

// The different types of game operations available
typedef enum valid_game_operations {SPLIT, DOUBLE, HIT, STAND, SURRENDER} game_operation_t;

#endif /* CODES_h */
