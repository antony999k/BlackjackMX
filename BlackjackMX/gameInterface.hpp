//
//  gameInterface.hpp
//  BlackjackMX
//
//  Created by Antony Morales on 06/04/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#ifndef gameInterface_hpp
#define gameInterface_hpp

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "sockets.hpp"
#include "blackjackRender.hpp"
#include "DEFINITIONS.hpp"
using namespace sf;
using namespace std;

class GameInterface{
    sf::RenderWindow *gameWindow;
    sf::Texture bgTexture; //Background texture
    sf::Sprite bgSprite; //Background sprite
protected:
    void renderLoop();
public:
    GameInterface();
};

#endif /* gameInterface_hpp */
