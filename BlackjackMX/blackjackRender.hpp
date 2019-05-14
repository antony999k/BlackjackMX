//
//  blackjackRender.hpp
//  BlackjackMX
//
//  Created by Antony Morales and Esmeralda Magadaleno on 09/05/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#ifndef blackjackRender_hpp
#define blackjackRender_hpp

#include <iostream>
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "CODES.hpp"

using namespace std;
using namespace sf;

class CardRender{
private:
    Texture cardTexture; //Texture includes all the cards in the deck
    Texture cardBackTexture; //Texture includes tha back texture of the card
    Sprite cardSprite; //Sprite of the card
    Sprite cardBackSprite; //Back sprite
protected:
public:
    void setSprite(sf::Uint32 value, sf::Uint32 suit); //Set the texture and the sprite for the card, setCard() call this function
    void setPosition(Vector2f position);
    Sprite getSprite(); //Return the specific card sprite
};

class HandRender{
protected:
public:
    Sprite getSprite(sf::Uint32); //You give the number of card in the vector and return his sprite
    vector<CardRender> deckCards;
};

 class StikerTotalValue{
 private:
     Font fontGlobal;
     Text totalValueText;
 public:
     void setText(sf::Uint32 total, Vector2f position);
     Text getText();
 };
 

class GenericPlayerRender:public HandRender{
protected:
    StikerTotalValue stikerTotalValue;
public:
    //void setHandSpawn(sf::Uint32 deckSize, sf::Uint32 deck[MAX_NUM_HAND]); //Set the position of the hand in the window and creates an x-offset fot the cards (called by setSpawn() function)
    void addCard(sf::Uint32 value, sf::Uint32 suit);
    void setHandPosition(Vector2f positionInit);
    Text getText();
};


class PlayerRender: public GenericPlayerRender{
public:
    void setSpawn(sf::Uint32 playerNum, sf::Uint32 deckSize, sf::Uint32 deck[MAX_NUM_HAND], sf::Uint32 cardsValue);
};

class DealerRender : public GenericPlayerRender{
public:
    void setSpawn( sf::Uint32 deckSize, sf::Uint32 deck[MAX_NUM_HAND], sf::Uint32 cardsValue);
};

#endif /* blackjackRender_hpp */
