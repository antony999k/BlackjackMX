//
//  CODES.h
//  BlackjackMX
//
//  Created by Antony Morales and Esmeralda Magadaleno on 05/04/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#ifndef CODES_h
#define CODES_h

#include <SFML/Network.hpp>
#include "DEFINITIONS.hpp"
using namespace sf;
using namespace std;

// The different types of sockets operation available that asign to the header
typedef enum valid_operations {CREATE_USER, MOVEMENT, ERROR, EXIT} operation_t;

// The different types of game operations available
typedef enum valid_player_operations {SPLIT, DOUBLE, HIT, STAND, SURRENDER, NO_APPLY} player_operations_t;

//The diferent types of game server status
typedef enum valid_game_status {WAITING, MATCHMAKING} game_status_t;

//Structure that will be send between one user and client to create a player
typedef struct createUserChunck_struct{
    sf::Uint32 playerId;
    string name;
    //createUserChunck constructor
    createUserChunck_struct(){
        playerId = 0;
        name = "";
    }
}createUserChunck;

//Structure that will be exchanged between all users and the server when user curren play the game
typedef struct userChunk_struct{
    sf::Uint32 playerId;
    string username;
    sf::Uint32 cards[MAX_NUM_HAND]; //Max number of cards that user can have before reach 21 (only cards of two with 3 decks). x2 to save the card number and card type
    //std::string cards;
    sf::Uint32 cardsValue;
    sf::Uint32 playerMovement;
    sf::Uint32 playerStatus;
    //userChunk contructor to init properties
    userChunk_struct(){
        playerId = 0;
        username = "";
        cards[0] = '\0';
        cardsValue = 0;
        playerMovement = NO_APPLY;
    };
}userChunk;

//Structure that will be exchanged between the user and the server when user curren play the game
typedef struct dealerChunk_struct{
    sf::Uint32 cards[MAX_NUM_HAND]; //Max number of cards that user can have before reach 21 (only cards of two with 3 decks). x2 to save the card number and card type
    //std::string cards;
    sf::Uint32 cardsValue; //Sum of value of the hand
    sf::Uint32 numCards; //Number of cards in the hand
    dealerChunk_struct(){
        cards[0] = '\0';
        cardsValue = 0;
        numCards = 0;
    }
}dealerChunk;

//Final struct that will be exange between  server when user curren play the game
typedef struct gameChunk_struct{
    sf::Uint32 gameStatus; //WAITING, MATCHMAKING
    sf::Uint32 turnPlayerId;
    userChunk userData[MAX_NUM_PLAYERS];
    dealerChunk dealerData;
    gameChunk_struct(){
        gameStatus = WAITING;
        turnPlayerId = -1;
    }
}gameChunk;

#endif /* CODES_h */
