//
//  blackjack.hpp
//  BlackjackMX
//
//  Created by Antony Morales on 03/03/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#ifndef blackjack_hpp
#define blackjack_hpp

#include <stdio.h>
#include <iostream>
#include <ctime>

class Card{
private:
    unsigned char suit; //Hearts, Diamonds, Spades, Clubs
    int value; //Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King
    int cardStatus; //1)In Deck 2) In play 3) Out of the game
public:
    Card(unsigned char = ' ', int = 0, int = 0);
    void setCard(unsigned char, int);
};

class Deck{
private:
    Card cards[52];
    int numCards;
};

class Hand{
private:
    Card cards[11]; //Max cards that you can have before overcome 21
    int numCards;
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
};

#endif /* blackjack_hpp */
