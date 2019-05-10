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
#include <SFML/Network.hpp>

using namespace sf;

/* Game
 *****************************************************************************************/
//Manage all the game in the Server
class Game{
private:
    unsigned int gameStatus; //WAITING, MATCHMAKING
    unsigned int turnPlayerId; // Id of the player who has the turn
    bool activePlayers[MAX_NUM_PLAYERS]; //Bool that know if player exists
    Deck deck; //Deck of cards in the game
    Dealer dealer_hand;
    vector<Player> player_hand; //Vector of players of the game
    
    createUserChunck createUserChunckServer;
    gameChunk gameChunkServer;
public:
    Game();
    //Set the userId based on player position (0 to 3) that are max player position + player port
    unsigned int setGetPlayerId(unsigned int _playerPosition, unsigned int _playerPort);
    //Set a new player in the game
    void setPlayer(string _name, string _port, unsigned int _playerId);
    //Init the basics of th game
    void initGame();
    
    //Udate the game data ready to be send to clients
    gameChunk getGameData();
};

#endif /* game_hpp */
