
//
//  gameInterface.cpp
//  BlackjackMX
//
//  Created by Antony Morales and Esmeralda Magadaleno on 06/04/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#include "gameInterface.hpp"
void GameInterface::renderLoop(){
    
    
    
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
        //text.setString("Game start: " + to_string(socketClient.gameData.gameStatus));
        text.setString("Game start: " + to_string(socketClient.gameData.dealerData.cards[1]));
        text.setCharacterSize(20);
        gameWindow->draw(text);
        if(dataLoaded){
            gameWindow->draw(dealer.getSprite(0));
            gameWindow->draw(dealer.getSprite(1));
            
            gameWindow->draw(player.getSprite(0));
            gameWindow->draw(player.getSprite(1));
        }
        
        // end the current frame
        gameWindow->display();
    }
    //Flag to tell thread that game is finish
    gameOpen = false;
}

void GameInterface::waitConectionLoop(){
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
        if(socketClient.dataChanged){
            socketClient.displayDataChunk();
            sf::Uint32 Acards[MAX_NUM_HAND] = {1,2,3,1};
            sf::Uint32 Acards2[MAX_NUM_HAND] = {6,2,8,3};
            dealer.setSpawn(2, Acards);
            player.setSpawn(0, 2, socketClient.gameData.userData[0].cards);
            socketClient.dataChanged = false;
            dataLoaded = true;
        }
    }
}

