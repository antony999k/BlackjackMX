//
//  blackjack.hpp
//  BlackjackMX
//
//  Created by Antony Morales on 03/03/19.
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

class Card{
private:
    int suit; //0)Hearts, 1)Diamonds, 2)Spades, 3)Clubs
    int value; //Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King
    int cardStatus; //1)In Deck 2) In play 3) Out of the game
    bool faceUp;
public:
    Card(int = -1, int = 0, int = -1, bool = true);
    void setCard(int, int);
    void swap(Card&);
    int getSuit();
    int getValue();
    bool isFaceUp(); //Indicates if the card is face up
    void flipCard(); //If the card is face down becomes face up and viceversa
    void consoleDisplay(); //Diplay a card in console for Debug and testing
};

class Hand{
protected:
    vector<Card> deckCards;
public:
    Card*getCard(int);
    void deletLastCard();
    void clear();
    int getTotalValue();
    void addCard(class Card *);
    int getNumberCards();
    void consoleDisplay(); //Diplay a deck in console for Debug and testing
};

class Deck: public Hand{
public:
    void populate(); //Creata a 52 cards deck
    void shuffle(); //Shuffle the created deck
    void dealToHand(Hand&);
};

class GenericPlayer: public Hand{
protected:
    string name;
    string port;
    bool busted;
    bool playing; //Indicates if is the player turn
public:
    GenericPlayer(string = "", string = "", bool = false, bool = false);
    void setPlayer(string, string);
    bool isPlaying();
    bool isBusted(); //Indicate if the player is out of cards
    void push(); //It sends when a player push one card
};

class Player: public GenericPlayer{
public:
    void win(); //It sends when a player win
    void tie(); ////It sends when a player tie
    void bust(); //It sends when a player is busted
};

class Dealer: public GenericPlayer{
public:
    void flipFirstCard(); //Dealer flip the first card
};

class Game{
    int numPlayers;
public:
    void play(); //A blackjack round
};

#endif /* blackjack_hpp */
