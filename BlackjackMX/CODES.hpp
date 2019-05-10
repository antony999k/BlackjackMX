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

//Structure that will be exchanged between the user and the server when user curren play the game
typedef struct userChunk_struct{
    sf::Uint32 playerId;
    char username[30];
    char cards[24]; //Max number of cards that user can have before reach 21 (only cards of two with 3 decks). x2 to save the card number and card type
    //std::string cards;
    sf::Uint32 cardsValue;
    sf::Uint32 playerMovement;
    sf::Uint32 playerStatus;
}userChunk;

//Structure that will be exchanged between the user and the server when user curren play the game
typedef struct dealerChunk_struct{
    char cards[24]; //Max number of cards that user can have before reach 21 (only cards of two with 3 decks). x2 to save the card number and card type
    //std::string cards;
    sf::Uint32 cardsValue;
}dealerChunk;

//Final struct that will be exange between  server when user curren play the game
typedef struct gameChunk_struct{
    sf::Uint32 turnPlayerId;
    sf::Uint32 gameStatus;
    userChunk userData[4];
    dealerChunk dealerData;
}gameChunk;

// The different types of sockets operation available that asign to the header
typedef enum valid_operations {CREATE_USER, MOVEMENT, ERROR, EXIT} operation_t;

// The different types of game operations available
typedef enum valid_game_operations {SPLIT, DOUBLE, HIT, STAND, SURRENDER, NO_APPLY} game_operation_t;

//The diferent types of player sttus
typedef enum valid_player_status {DEAD, PLAYING} player_status_t;

#endif /* CODES_h */
