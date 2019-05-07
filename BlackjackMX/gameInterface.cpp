//
//  gameInterface.cpp
//  BlackjackMX
//
//  Created by Antony Morales on 06/04/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#include "gameInterface.hpp"
GameInterface::GameInterface(){
    gameWindow = new RenderWindow(VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Blackjack MX");
    gameWindow->setFramerateLimit(FRAME_RATE);
    //Set the initial textures and sprites
    bgTexture.loadFromFile(GAME_BACKGROUND_PATH);
    bgSprite.setTexture(bgTexture);
    
    renderLoop();
}

void GameInterface::renderLoop(){
    sf::IpAddress ip = sf::IpAddress::getLocalAddress();
    //Struct data for user interaction init
    userInteraction gameData;
    SocketClient socketClient(ip,53000);
    
    sf::Font font;
    font.loadFromFile(GAME_GLOBAL_FONT);
    sf::Text text;
    text.setFont(font);
    
    // run the program as long as the window is open
    while (gameWindow->isOpen()){
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (gameWindow->pollEvent(event)){
            switch (event.type) {
                case Event::Closed:
                    gameWindow->close();
                    break;
                case Event::KeyPressed:
                    if(Keyboard::isKeyPressed(Keyboard::Q)){
                        socketClient.setPacket(gameData, CREATE_USER);
                        socketClient.sendPacketToServer();
                    }
                    break;
            }
        }
        
        // clear the window with black color
        gameWindow->clear(sf::Color::Black);
        gameWindow->draw(bgSprite);//Render the background
        
        socketClient.waitForConnections();
        text.setString(to_string(socketClient.gameData.playerId));
        text.setCharacterSize(24);
        gameWindow->draw(text);
        
        // end the current frame
        gameWindow->display();
    }

}
