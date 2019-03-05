//
//  game.cpp
//  BlackjackMX
//
//  Created by Antony Morales on 04/03/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#include "game.hpp"
#include "blackjack.hpp"

//Play game function ************************************
Game::Game(){
    gameWindow = new RenderWindow(VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Blackjack MX");
    gameWindow->setFramerateLimit(FRAME_RATE);
    //Init the texture and sprite
    bgTexture = new Texture;
    bgSprite = new Sprite;
    
    bgTexture->loadFromFile(GAME_CARD_ATLAS_PATH);
    bgSprite->setTexture(*bgTexture);
    render();
}

void Game::render(){
    Card pruebaCard;
    pruebaCard.setCard(1, 6);
    //Manage windows event
    while (gameWindow->isOpen()) {
        Event event;
        while (gameWindow->pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    gameWindow->close();
                    break;
                case Event::KeyPressed:
                    if(Keyboard::isKeyPressed(Keyboard::A)){
                        exit(0);
                    }
                    break;
            }
        }
        
        gameWindow->clear();
        gameWindow->draw(*bgSprite);//Render the background
        
        /*
         for (int i = 0; i<players[0].getNumberCards(); i++) {
         tempCard = *players[0].getCard(i);
         cardSprite->setTextureRect(IntRect(CARD_WIDTH*(tempCard.getValue()-1),CARD_HEIGHT*(tempCard.getSuit()),CARD_WIDTH,CARD_HEIGHT));
         cardSprite->setPosition((CARD_WIDTH*i)/2, (CARD_HEIGHT*0)/2);
         gameWindow->draw(*cardSprite);
         }
         */
        gameWindow->draw(pruebaCard.getSprite());
        gameWindow->display();
    }
}
