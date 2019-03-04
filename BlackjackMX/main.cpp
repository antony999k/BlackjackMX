//
//  main.cpp
//  BlackjackMX
//
//  Created by Antony Morales on 02/03/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include "DEFINITIONS.hpp"
#include "blackjack.hpp"
#include <ctime>

using namespace sf;
using namespace std;

int main(int argc, const char * argv[]) {
    //Render Window
    RenderWindow window(VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Blackjack MX");
    window.setFramerateLimit(30);
    
    Texture cardTexture,bgTexture;
    cardTexture.loadFromFile(GAME_BACKGROUND_PATH);
    bgTexture.loadFromFile(GAME_CARD_ATLAS_PATH);
    
    Sprite cardSprite(cardTexture);
    Sprite bgSprite(bgTexture);
    cardSprite.scale(0.5, 0.5);
    
    Game game;
    game.play();
    
    //Manage windows event
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    window.close();
                    break;
            }
        }
        
        window.clear();
        //Draw Objects
        window.draw(bgSprite); //Render the background
        /*
        for (int i = 0; i<player_hand.getNumberCards(); i++) {
            tempCard = player_hand.getCard(i);
            cardSprite.setTextureRect(IntRect(CARD_WIDTH*(tempCard->getValue()-1),CARD_HEIGHT*(tempCard->getSuit()),CARD_WIDTH,CARD_HEIGHT));
            cardSprite.setPosition((CARD_WIDTH*i)/2, (CARD_HEIGHT*0)/2);
            window.draw(cardSprite);
        }*/
    
        cardSprite.setTextureRect(IntRect(0,0,CARD_WIDTH,CARD_HEIGHT));
        cardSprite.setPosition(0, 0);
        window.draw(cardSprite);
        window.display();
    }
    return 0;
}
