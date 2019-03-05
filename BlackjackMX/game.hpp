//
//  game.hpp
//  BlackjackMX
//
//  Created by Antony Morales on 04/03/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include <SFML/Graphics.hpp>

using namespace sf;

class Game{
    int numPlayers;
    bool slot[5];
    RenderWindow * gameWindow;
public:
    Game(); //A blackjack round, manage the round game
    void render(); //Loop the game and render the components
    Texture *bgTexture; //Background texture
    Sprite *bgSprite; //Background sprite
};

#endif /* game_hpp */
