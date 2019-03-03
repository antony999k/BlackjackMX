//
//  main.cpp
//  BlackjackMX
//
//  Created by Antony Morales on 02/03/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
using namespace sf;
using namespace std;

int main(int argc, const char * argv[]) {
    //Render Window
    RenderWindow window(VideoMode(600,600), "Blackjack MX");
    
    Texture cardTexture;
    cardTexture.loadFromFile("Resources/Images/playingCards.png");
    
    Sprite cardSprite(cardTexture);
    
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
        
        window.clear(Color::White);
        //Draw Objects
        window.draw(cardSprite);
        window.display();
    }
}
