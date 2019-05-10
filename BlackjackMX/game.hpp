//
//  game.hpp
//  BlackjackMX_Server
//
//  Created by Antony Morales on 10/05/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include <iostream>
#include "blackjack.hpp"
#include "CODES.hpp"

/* Game
 *****************************************************************************************/
//Manage all the game in the Server
class Game{
private:
    int gameStatus; //WAITING, MATCHMAKING
    int turnPlayerId; // id of the player who has the turn
    bool activePlayers[MAX_NUM_PLAYERS]; //Bool that know if player exists
    Deck deck; //Deck of cards in the game
    Dealer dealer_hand;
    vector<Player> player_hand; //Vector of players of the game
    
    gameChunk gameChunkServer;
public:
    Game();
    //Set a new player in the game
    void setPlayer(string _name, string _port);
    //Init the basics of th game
    void initGame();
    
    //Udate the game data ready to be send to clients
    gameChunk getGameData();
};

#endif /* game_hpp */
