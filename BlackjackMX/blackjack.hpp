//
//  blackjack.hpp
//  BlackjackMX_Server
//
//  Created by Antony Morales on 10/05/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#ifndef blackjack_hpp
#define blackjack_hpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "DEFINITIONS.hpp"

using namespace std;

/* Card
 *****************************************************************************************/
class Card{
private:
    int suit; //0)Hearts, 1)Diamonds, 2)Spades, 3)Clubs
    int value; //0, 1 ,2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
    int gameValue; //Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King
    int cardStatus; //1)In Deck 2) In play 3) Out of the game
    bool faceUp;
protected:
    void setSprite(); //Set the texture and the sprite for the card, setCard() call this function
public:
    Card();
    Card(int, int, int, bool);
    int getSuit();//Return the in value of the suit, 0)Hearts, 1)Diamonds, 2)Spades, 3)Clubs
    int getValue();//Return the int value of the cards to print in screen
    int getGameValue(); //Return the int value of the cards to manage the game
    bool isFaceUp(); //Indicates if the card is face up
    void flipCard(); //If the card is face down becomes face up and viceversa
    void consoleDisplay(); //Diplay a card in console for Debug and testing
};

/* Hand
*****************************************************************************************/
class Hand{
protected:
    vector<Card> deckCards;
public:
    Card*getCard(int); //Return a pointer of a card in the hand
    void deletLastCard(); //Delete the last card of the hand
    void clear(); //It takes away all the cards
    int getTotalValue(); //Get the total value of the cards
    void addCard(class Card *); //Add a card in the hand
    int getNumberCards(); //Return the total number of cards in the hand
    void consoleDisplay(); //Diplay a deck in console for Debug and testing
};

/* Deck
 *****************************************************************************************/
class Deck: public Hand{
private:
    bool shuffling;
public:
    Deck();
    void populate(); //Creata a 52 cards deck
    void shuffle(); //Shuffle the created deck
    void dealToHand(Hand&);
};

/* GenericPlayer
 *****************************************************************************************/
class GenericPlayer: public Hand{
protected:
    string name;
    string port;
    bool busted;
    bool playing; //Indicates if is the player turn
public:
    bool isPlaying(); //Creates a pure vitual function, GenericPlayer class is only a skeleton for Player an dealer and can´t create an instance
    bool isBusted(); //Indicate if the player is out of cards
    void push(); //It sends when a player push one card
};

/* Player
 *****************************************************************************************/
class Player: public GenericPlayer{
private:
    int bank;
    unsigned int playerId;
public:
    Player(); //Init the credit amount and the player slot in the game
    Player(string _name, string _port, unsigned int _playerId);
    void win(); //It sends when a player win
    void tie(); ////It sends when a player tie
    void bust(); //It sends when a player is busted
    void setSpawn(int); //Spawns in diferent paces depens player number
    int getBank(); //Get the player total amoun of credits
};

/* Dealer
 *****************************************************************************************/
class Dealer : public GenericPlayer{
public:
    Dealer();
    Dealer(string _name, string _port);
    void flipFirstCard(); //Dealer flip the first card
    void setSpawn();
};


#endif /* blackjack_hpp */
