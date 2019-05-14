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
void CardRender::setSprite(sf::Uint32 value, sf::Uint32 suit){
    cardTexture.loadFromFile(GAME_CARD_ATLAS_PATH);
    cardBackTexture.loadFromFile(GAME_CARD_BACK);
    
    cardSprite.setTexture(cardTexture);
    cardSprite.setTextureRect(IntRect(CARD_WIDTH*(value-1), CARD_HEIGHT*suit, CARD_WIDTH, CARD_HEIGHT));
    
    cardBackSprite.setTexture(cardBackTexture);
    cardBackSprite.setTextureRect(IntRect(0, 0, CARD_WIDTH, CARD_HEIGHT));
}

void CardRender::setPosition(Vector2f position){
    cardSprite.scale(CARD_SCALE ,CARD_SCALE);
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
void StikerTotalValue::setText(sf::Uint32 total, Vector2f position){
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
/*
void GenericPlayerRender::setHandSpawn(sf::Uint32 deckSize, sf::Uint32 deck[MAX_NUM_HAND]){
    int j = 0;
    CardRender tCard;
    for (int i = 0; i<deckSize; i++){
        deckCards.push_back(tCard);
    }
    for (int k = 0; k<deckCards.size(); k++) {
        deckCards[k].setSprite(deck[j],deck[j+1]);
        j+=2;
    }
}
 */

void GenericPlayerRender::addCard(sf::Uint32 value, sf::Uint32 suit){
    deckCards.push_back(CardRender());
    deckCards[deckCards.size() - 1].setSprite(value, suit);
}

void GenericPlayerRender::setHandPosition(Vector2f positionInit){
    int xDisp = 0;
    for (int k = 0; k<deckCards.size(); k++) {
        deckCards[k].setPosition({positionInit.x + xDisp, positionInit.y});
        xDisp += (CARD_WIDTH*CARD_SCALE)/3.3;
    }
}


Text GenericPlayerRender::getText(){
    return stikerTotalValue.getText();
}

/* PlayerRender functions
 *****************************************************************/
void PlayerRender::setSpawn(sf::Uint32 playerNum, sf::Uint32 deckSize, sf::Uint32 deck[MAX_NUM_HAND],  sf::Uint32 cardsValue){
    /*
    stikerTotalValue.setTotalVal(getTotalValue());
     */
    switch (playerNum) {
        case 0:
            setHandPosition({PLAYER_0_X_POSITION,PLAYER_0_Y_POSITION});
            stikerTotalValue.setText(cardsValue, {PLAYER_0_X_POSITION-20,PLAYER_0_Y_POSITION-20});
            break;
        case 1:
            setHandPosition({PLAYER_1_X_POSITION,PLAYER_1_Y_POSITION});
            stikerTotalValue.setText(cardsValue, {PLAYER_1_X_POSITION-20,PLAYER_1_Y_POSITION-20});
            break;
        case 2:
            setHandPosition({PLAYER_2_X_POSITION,PLAYER_2_Y_POSITION});
            stikerTotalValue.setText(cardsValue, {PLAYER_2_X_POSITION-20,PLAYER_2_Y_POSITION-20});
            break;
        case 3:
            setHandPosition({PLAYER_3_X_POSITION,PLAYER_3_Y_POSITION});
            stikerTotalValue.setText(cardsValue, {PLAYER_3_X_POSITION-20,PLAYER_3_Y_POSITION-20});
        default:
            break;
    }
    
}

/* DealerRender functions
 *****************************************************************/
void DealerRender::setSpawn(sf::Uint32 deckSize, sf::Uint32 deck[MAX_NUM_HAND],  sf::Uint32 cardsValue){
    setHandPosition({DEALER_X_POSITION,DEALER_Y_POSITION});
    stikerTotalValue.setText(cardsValue, {DEALER_X_POSITION-30,DEALER_Y_POSITION});
}

