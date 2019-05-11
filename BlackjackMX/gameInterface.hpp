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
#include <SFML/System.hpp>
#include "sockets.hpp"
#include "blackjackRender.hpp"
#include "DEFINITIONS.hpp"
using namespace sf;
using namespace std;

class GameInterface{
    sf::Thread m_thread; //Thread variable
    sf::RenderWindow *gameWindow;
    sf::Texture bgTexture; //Background texture
    sf::Sprite bgSprite; //Background sprite
    SocketClient socketClient; //Socket with server connection variable (sockets.hpp)
    bool gameOpen;
    bool dataLoaded;
    
    //SFML Render props
    DealerRender dealer;
    PlayerRender player;
protected:
    void renderLoop();
    void waitConectionLoop();
public:
    //This constructor need to initialize here because the  thread option. We init the thread with waitConection() as entry point
    GameInterface(): m_thread(&GameInterface::waitConectionLoop, this){
        gameOpen = true; dataLoaded=false;
        gameWindow = new RenderWindow(VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Blackjack MX");
        gameWindow->setFramerateLimit(FRAME_RATE);
        //Set the initial textures and sprites
        bgTexture.loadFromFile(GAME_BACKGROUND_PATH);
        bgSprite.setTexture(bgTexture);
        
        // run the thread and start the
        m_thread.launch();
        renderLoop();
        m_thread.wait();
    }
};

#endif /* gameInterface_hpp */
