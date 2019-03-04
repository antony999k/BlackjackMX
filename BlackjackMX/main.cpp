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

using namespace sf;
using namespace std;

int main(int argc, const char * argv[]) {
    //Render Window
    RenderWindow window(VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Blackjack MX");
    window.setFramerateLimit(30);
    
    int x,y,width=140,height=190;
    
    Texture cardTexture,bgTexture;
    cardTexture.loadFromFile(GAME_BACKGROUND_PATH);
    bgTexture.loadFromFile(GAME_CARD_ATLAS_PATH);
    
    Sprite cardSprite(cardTexture);
    Sprite bgSprite(bgTexture);
    cardSprite.scale(0.5, 0.5);
    
    Deck deck;
    deck.populate();
    deck.shuffle();
    deck.consoleDisplay();
    
    Hand player_hand;
    deck.dealToHand(player_hand);
    deck.dealToHand(player_hand);
    cout << endl << "Player:";
    player_hand.consoleDisplay();
    cout << endl;
    
    deck.consoleDisplay();
    cout << endl << "Player:";
    cout << endl;
    
    cout << endl << "Player:";
    player_hand.consoleDisplay();
    cout << endl;
    
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
        
        int i;
        for (i = 0; i<2; i++) {
            cardSprite.setTextureRect(IntRect(width*i,0,width,height));
            cardSprite.setPosition((width*i)/2, 0);
            window.draw(cardSprite);
        }
    
        //cardSprite.setTextureRect(IntRect(0,0,width,height));
        //cardSprite.setPosition(0, 0);
        
        window.display();
    }
    return 0;
}
