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
#include <ctime>
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"

using namespace std;
using namespace sf;

class Card{
private:
    int suit; //0)Hearts, 1)Diamonds, 2)Spades, 3)Clubs
    int value; //Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King
    int cardStatus; //1)In Deck 2) In play 3) Out of the game
    bool faceUp;
    Texture cardTexture; //Texture includes all the cards in the deck
    Sprite cardSprite; //Sprite of the card
protected:
    void setSprite(); //Set the texture and the sprite for the card, setCard() call this function
public:
    Card();
    Card(int, int, int, bool);
    void setCard(int, int);
    int getSuit();
    int getValue();
    bool isFaceUp(); //Indicates if the card is face up
    void flipCard(); //If the card is face down becomes face up and viceversa
    void consoleDisplay(); //Diplay a card in console for Debug and testing
    Sprite getSprite(); //Return the specific card sprite
};


class Hand{
protected:
    vector<Card> deckCards;
public:
    Card*getCard(int);
    void deletLastCard(); //Delete the last card of the hand
    void clear(); //It takes away all the cards
    int getTotalValue(); //Get the total value of the cards
    void addCard(class Card *); //Add a card in the hand
    int getNumberCards(); //Return the total number of cards in the hand
    void consoleDisplay(); //Diplay a deck in console for Debug and testing
    Sprite getSprite(int); //Give the umber of card in the vector and return his sprite
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
private:
    int bank;
public:
    Player(int = 1000); //Init the credit amount and the player slot in the game
    void win(); //It sends when a player win
    void tie(); ////It sends when a player tie
    void bust(); //It sends when a player is busted
};

class Dealer: public GenericPlayer{
public:
    void flipFirstCard(); //Dealer flip the first card
};

#endif /* blackjack_hpp */
