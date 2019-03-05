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
    
    bgTexture->loadFromFile(GAME_BACKGROUND_PATH);
    bgSprite->setTexture(*bgTexture);
    render();
}

void Game::render(){
    Deck deck;
    Dealer dealer_hand("Dealer", "192.192.21.12", false, true);
    Player player_hand("Juan", "192.192.31.12", false, true);
    //dealer_hand.setTablaPlace(*dealer_hand.getSprite(0));
    
    deck.populate();
    deck.shuffle();
    
    deck.dealToHand(player_hand);
    deck.dealToHand(player_hand);
    deck.dealToHand(dealer_hand);
    dealer_hand.flipFirstCard();
    deck.dealToHand(dealer_hand);
    
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
                        deck.dealToHand(player_hand);
                    }
                    if(Keyboard::isKeyPressed(Keyboard::S)){
                        player_hand.clear();
                    }
                    break;
            }
        }
        gameWindow->clear();
        gameWindow->draw(*bgSprite);//Render the background
        for (int i = 0; i<deck.getNumberCards(); i++) {
            gameWindow->draw(deck.getSprite(i));

        }
        
        for (int i = 0; i<dealer_hand.getNumberCards(); i++) {
            gameWindow->draw(dealer_hand.getSprite(i));
            dealer_hand.setSpawn();
        }
        
        for (int i = 0; i<player_hand.getNumberCards(); i++) {
            gameWindow->draw(player_hand.getSprite(i));
            player_hand.setSpawn(1);
        }
        
        gameWindow->display();
    }
}
