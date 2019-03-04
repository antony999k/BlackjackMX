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
public:
    Card(int = -1, int = 0, int = -1);
    void setCard(int, int);
    void swap(Card&);
    unsigned char getSuit();
    int getValue();
    bool isFaceUp(); //Indicates if the card is face up
    void flipCard(); //If the card is face down becomes face up and viceversa
    void consoleDisplay(); //Diplay a card in console for Debug and testing
};

class Hand{
private:
    Card cards[11]; //Max cards that you can have before overcome 21
    int numCards;
public:
    bool addCard(Card *);
    void clear();
    int totalValue();
};

class Deck{
private:
    vector<Card> deckCards;
    int numCards;
public:
    void populate(); //Creata a 52 cards deck
    void shuffle(); //Shuffle the created deck
    void dealToHand(Hand&);
    void consoleDisplay(); //Diplay a deck in console for Debug and testing
};

class Player{
private:
    Hand playerHand;
};

class Dealer{
private:
    Hand dealerHand;
};

class Game{
    Deck deck;
    Player *players;
    int numPlayers;
    Dealer gameDealer;
public:
    void play(); //A blackjack round
    void flipFirstCard();
};

#endif /* blackjack_hpp */
