//
//  blackjackRender.cpp
//  BlackjackMX
//
//  Created by Antony Morales and Esmeralda Magadaleno on 09/05/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#include "blackjackRender.hpp"

/* CardRender functions
 *****************************************************************/
//Set the 2 textures
void CardRender::setSprite(sf::Uint32 value, sf::Uint32 suit, Vector2f position){
    cardTexture.loadFromFile(GAME_CARD_ATLAS_PATH);
    cardBackTexture.loadFromFile(GAME_CARD_BACK);
    
    cardSprite.setTexture(cardTexture);
    cardSprite.setTextureRect(IntRect(CARD_WIDTH*(value-1), CARD_HEIGHT*suit, CARD_WIDTH, CARD_HEIGHT));
    cardSprite.scale(CARD_SCALE ,CARD_SCALE);
    
    cardBackSprite.setTexture(cardBackTexture);
    cardBackSprite.setTextureRect(IntRect(0, 0, CARD_WIDTH, CARD_HEIGHT));
    cardBackSprite.scale(CARD_SCALE ,CARD_SCALE);
    
    cardBackSprite.setPosition(position.x, position.y);
    cardSprite.setPosition(position.x, position.y);
}

/*
Sprite CardRender::getSprite(){
    if(faceUp){
        return cardSprite;
    }else{
        return cardBackSprite;
    }
}
 */

Sprite CardRender::getSprite(){
    return cardSprite;
}

/* HandRender functions
 *****************************************************************/
Sprite HandRender::getSprite(sf::Uint32 index){
    return deckCards[index].getSprite();
}

/* StikerTotalValue functions
 *****************************************************************/
void StikerTotalValue::setSprite(sf::Uint32 total, Vector2f position){
    fontGlobal.loadFromFile(GAME_GLOBAL_FONT);
    totalValueText.setFont(fontGlobal);
    totalValueText.setFillColor(Color::White);
    
    totalValueText.setString(to_string(total));
    
    totalValueText.setPosition(position.x, position.y);
}

Text StikerTotalValue::getText(){
    return totalValueText;
}

/* GenericPlayerRender functions
 *****************************************************************/
void GenericPlayerRender::setHandSpawn(Vector2f positionInit, sf::Uint32 deckSize, sf::Uint32 deck[MAX_NUM_HAND]){
    int xDisp = 0;
    int j = 0;
    CardRender tCard;
    for (int i = 0; i<deckSize; i++){
        deckCards.push_back(tCard);
    }
    for (int k = 0; k<deckCards.size(); k++) {
        deckCards[k].setSprite(deck[j],deck[j+1],{positionInit.x + xDisp, positionInit.y});
        xDisp += (CARD_WIDTH*CARD_SCALE)/3.3;
        j+=2;
    }
}

Text GenericPlayerRender::getText(){
    return stikerTotalValue.getText();
}

/* PlayerRender functions
 *****************************************************************/
void PlayerRender::setSpawn(sf::Uint32 playerNum, sf::Uint32 deckSize, sf::Uint32 deck[MAX_NUM_HAND]){
    /*
    stikerTotalValue.setTotalVal(getTotalValue());
     */
    switch (playerNum) {
        case 0:
            setHandSpawn({PLAYER_0_X_POSITION,PLAYER_0_Y_POSITION}, deckSize, deck);
            //stikerTotalValue.setSpawn({PLAYER_0_X_POSITION-20,PLAYER_0_Y_POSITION-20});
            break;
        case 1:
            setHandSpawn({PLAYER_1_X_POSITION,PLAYER_1_Y_POSITION},deckSize, deck);
            //stikerTotalValue.setSpawn({PLAYER_1_X_POSITION-20,PLAYER_1_Y_POSITION-12});
            break;
        case 2:
            setHandSpawn({PLAYER_2_X_POSITION,PLAYER_2_Y_POSITION},deckSize, deck);
            //stikerTotalValue.setSpawn({PLAYER_2_X_POSITION-20,PLAYER_2_Y_POSITION-20});
            break;
        default:
            break;
    }
    
}

/* DealerRender functions
 *****************************************************************/
void DealerRender::setSpawn(sf::Uint32 deckSize, sf::Uint32 deck[MAX_NUM_HAND]){
    setHandSpawn({DEALER_X_POSITION,DEALER_Y_POSITION}, deckSize, deck);
    /*
    setHandSpawn({DEALER_X_POSITION,DEALER_Y_POSITION});
    stikerTotalValue.setTotalVal(getTotalValue());
    stikerTotalValue.setSpawn({DEALER_X_POSITION-30,DEALER_Y_POSITION});
     */
}

