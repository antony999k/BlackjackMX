
//
//  gameInterface.cpp
//  BlackjackMX
//
//  Created by Antony Morales on 06/04/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#include "gameInterface.hpp"
void GameInterface::renderLoop(){
    //Tempolal data
    gameChunk newGameData;
    createUserChunck newUserData;
    
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
                        socketClient.setGamePacket(newGameData, MOVEMENT);
                        socketClient.sendPacketToServer();
                    }
                    break;
            }
        }
        // clear the window with black color
        gameWindow->clear(sf::Color::Black);
        gameWindow->draw(bgSprite);//Render the background
        
        string displayText = "";
        if(socketClient.gameData.gameStatus == WAITING){
            displayText = "False";
        }else{
            displayText = "True";
        }
        text.setString("Game start: " + displayText);
        text.setCharacterSize(20);
        gameWindow->draw(text);
        
        // end the current frame
        gameWindow->display();
    }
    //Flag to tell thread that game is finish
    gameOpen = false;
}

void GameInterface::waitConection(){
    //Init the socket connection with the server
    sf::IpAddress ip = sf::IpAddress::getLocalAddress();
    socketClient.connect(ip,53000);
    
    
    //Tempolal data
    gameChunk newGameData;
    createUserChunck newUserData;
    
    //Send inital data to the server
    //socketClient.setGamePacket(newGameData, MOVEMENT); //CREATE_USER, MOVEMENT, ERROR, EXIT
    socketClient.setUserPacket(newUserData, CREATE_USER); //CREATE_USER, MOVEMENT, ERROR, EXIT
    socketClient.sendPacketToServer();
    
    while (gameOpen) {
        socketClient.waitForConnections();
    }
    cout << "Acaba waitConection" << endl;
}

