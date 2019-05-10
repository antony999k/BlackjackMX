//
//  blackjackRender.hpp
//  BlackjackMX
//
//  Created by Antony Morales on 09/05/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#ifndef blackjackRender_hpp
#define blackjackRender_hpp

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


class CardRender{
private:
    Texture cardTexture; //Texture includes all the cards in the deck
    Texture cardBackTexture; //Texture includes tha back texture of the card
    Sprite cardSprite; //Sprite of the card
    Sprite cardBackSprite; //Back sprite
protected:
    void setSprite(); //Set the texture and the sprite for the card, setCard() call this function
public:
    CardRender();
    CardRender(int, int, int, bool);
    void setSpritePos(Vector2f); //Set the position of a card in the window
    Sprite getSprite(); //Return the specific card sprite
};


class HandRender{
protected:
public:
    Sprite getSprite(int); //You give the number of card in the vector and return his sprite
};



 class StikerTotalValue{
 private:
     Font fontGlobal;
     Text totalValueText;
 public:
     StikerTotalValue();
     void setTotalVal(int=0);
     void setSpawn(Vector2f);
     Text getText();
 };
 

class GenericPlayerRender: public HandRender{
protected:
    StikerTotalValue stikerTotalValue;
    void setHandSpawn(Vector2f); //Set the position of the hand in the window and creates an x-offset fot the cards (called by setSpawn() function)
public:
    Text getText();
};



#endif /* blackjackRender_hpp */
