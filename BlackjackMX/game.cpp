//
//  game.cpp
//  BlackjackMX_Server
//
//  Created by Antony Morales on 10/05/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#include "game.hpp"


/* Game functions
 ***********************************************************************************************/
Game::Game(){
    gameStatus = WAITING;
    turnPlayerId = -1;
    for(int i=0; i<MAX_NUM_PLAYERS; i++){
        activePlayers[i] = false;
    }
}

//Set a new player in the game
void Game::setPlayer(string _name, string _port){
    player_hand.push_back(Player(_name, _port));
    cout << "New pleyer " << _name << " port " << _port << endl;
    
}

//Init the basics of th game
void Game::initGame(){
    //Init the deck, populate and shuffle
    deck.populate();
    deck.shuffle();
    //Two cards to the dealer
    deck.dealToHand(dealer_hand);
    deck.dealToHand(dealer_hand);
    
    //Gives two cards to each player in the game
    for(int i=0; i<player_hand.size(); i++){
        deck.dealToHand(player_hand[i]);
        deck.dealToHand(player_hand[i]);
    }
    
}

gameChunk Game::getGameData(){
    gameChunkServer.gameStatus = gameStatus;
    gameChunkServer.turnPlayerId = turnPlayerId;
    return gameChunkServer;
}
