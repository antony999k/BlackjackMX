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
Game::Game(void){
    cout << "Game constructor" << endl;
    gameStatus = WAITING;
    turnPlayerId = 0;
    for(int i=0; i<MAX_NUM_PLAYERS; i++){
        activePlayers[i] = false;
    }
}

//Set the userId based on player position (0 to 3) that are max player position + player port
unsigned int Game::setGetPlayerId(unsigned int _playerPosition, unsigned int _playerPort){
    string sPlayerId = to_string(_playerPosition) + to_string(_playerPort);
    return stoi(sPlayerId);
}

//Set a new player in the game
void Game::setPlayer(string _name, string _port,  unsigned int _playerId){
    player_hand.push_back(Player(_name, _port, _playerId));
    userData.name = _name;
    userData.playerId = _playerId;
    cout << "New player " << _name << ", port:" << _port << ", PlayerId:" << _playerId <<  endl;
}

//Init the basics of th game
void Game::initGame(){
    //The matchmaking flag indicates that the game start
    gameStatus = MATCHMAKING;
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
        player_hand[i].consoleDisplay();
    }
    
    
    
}

gameChunk Game::getGameData(){
    gameData.gameStatus = gameStatus;
    gameData.turnPlayerId = turnPlayerId;
    int deckCounter = 0;
    for (int i =0; i<player_hand.size(); i++) {
        //vector<Card> tempDeck= player_hand[i].getDeck();
        for (int j = 0; j < player_hand[i].getDeck().size(); j++) {
            //cout << "CHECKER: " << player_hand[i].getDeck()[j].getValue() << endl;
            gameData.userData[i].cards[deckCounter] = player_hand[i].getDeck()[j].getValue();
            gameData.userData[i].cards[deckCounter+1] = player_hand[i].getDeck()[j].getSuit();
            //cout << "Saved: " << gameData.userData[i].cards[deckCounter] << " - " << gameData.userData[i].cards[deckCounter+1]  << endl;
            deckCounter += 2;
        }
        gameData.userData[i].playerId = player_hand[i].getPlayerId();
        gameData.userData[i].cardsValue = player_hand[i].getTotalValue();
        gameData.userData[i].playerMovement = NO_APPLY;
        gameData.userData[i].playerStatus = player_hand[i].isBusted();
        gameData.userData[i].username = player_hand[i].getUsername();
    }
    deckCounter = 0;
    for(int k = 0; k<dealer_hand.getDeck().size(); k++){
        gameData.dealerData.cards[deckCounter] = dealer_hand.getDeck()[k].getValue();
        gameData.dealerData.cards[deckCounter+1] = dealer_hand.getDeck()[k].getSuit();
        deckCounter += 2;
    }
    //gameChunkServer.turnPlayerId= 87;
    cout << "(Game) gameStatus: " << gameData.gameStatus << endl;
    return gameData;
}

createUserChunck Game::getUserData(){
    return userData;
}
