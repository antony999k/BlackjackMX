
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
                        //Detect if its your turn
                        if(socketClient.gameData.turnPlayerId == socketClient.userData.playerId){
                            cout << "INPUTTT" << endl;
                            isUserInput = true;
                            userInput = HIT; //(SPLIT, DOUBLE, HIT, STAND, SURRENDER, NO_APPLY)
                        }
                    }
                    break;
            }
        }
        // clear the window with black color
        gameWindow->clear(sf::Color::Black);
        gameWindow->draw(bgSprite);//Render the background
        
        string displayText = "";
        if(socketClient.gameData.gameStatus == WAITING){
            displayText = "Waiting";
        }else{
            displayText = "Matchmaking";
        }
        text.setString("Game Status: " + displayText);
        text.setCharacterSize(20);
        gameWindow->draw(text);
        
        //Load this part when the first chunk of data arrives to the client
        if(dataLoaded){
            
            for (int i = 0; i<socketClient.gameData.dealerData.numCards; i++) {
                gameWindow->draw(dealer.getSprite(i));
                gameWindow->draw(dealer.getText());
            }
            
            //Loads the players info and his cards
            for(int i = 0; i<MAX_NUM_PLAYERS; i++){
                for(int j = 0; j<socketClient.gameData.userData[i].numCards;j++){
                    gameWindow->draw(player[i].getSprite(j));
                    gameWindow->draw(player[i].getText());
                }
            }
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
    
    //Temporal data
    createUserChunck newUserData;
    
    //Send inital data to the server
    socketClient.setUserPacket(newUserData, CREATE_USER); //CREATE_USER, MOVEMENT, ERROR, EXIT
    socketClient.sendPacketToServer();
    
    while (gameOpen) {
        socketClient.waitForConnections();
        
        //Detects when comes new chunk data from the server
        if(socketClient.dataChanged){
            socketClient.displayDataChunk();
            
            cout << "My player ID: " << socketClient.userData.playerId << endl;
            
            dealer.setSpawn(socketClient.gameData.dealerData.numCards, socketClient.gameData.dealerData.cards, socketClient.gameData.dealerData.cardsValue);
            for(int i = 0; i<MAX_NUM_PLAYERS; i++){
                if(socketClient.gameData.userData[i].playerId != 0){
                    player[i].setSpawn(i, socketClient.gameData.userData[i].numCards, socketClient.gameData.userData[i].cards, socketClient.gameData.userData[i].cardsValue);
                }
            }
            socketClient.dataChanged = false;
            dataLoaded = true;
        }
        //Detects the user input and send to server
        else if(isUserInput){
            socketClient.pushUserInput(userInput);
            isUserInput = false;
        }
    }
}

