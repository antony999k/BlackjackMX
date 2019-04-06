//
//  blackjack.cpp
//  BlackjackMX
//
//  Created by Antony Morales on 03/03/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#include "blackjack.hpp"

//Card functions ************************************
Card::Card(){
    suit = -1;
    value = 0;
    gameValue = 0;
    cardStatus = -1;
    faceUp = true;
}

Card::Card(int _suit, int _value, int _cardStatus, bool _faceUp){
    suit = _suit;
    value = _value;
    cardStatus = _cardStatus;
    faceUp = _faceUp;
    
    if (_value == 11 || _value == 12 || _value == 13) {
        gameValue = 10;
    }else{
        gameValue = _value;
    }
    setSprite();
}

int Card::getSuit(){
    return suit;
}

int Card::getValue(){
    return value;
}

int Card::getGameValue(){
    return gameValue;
}

bool Card::isFaceUp(){
    return faceUp;
}

void Card::flipCard(){
    faceUp = !faceUp;
}

void Card::consoleDisplay(){
    if(!faceUp){
        cout << "X";
    }else{
        switch (value) {
            case 1:
                cout << "A";
                break;
            case 11:
                cout << "J";
                break;
            case 12:
                cout << "Q";
                break;
            case 13:
                cout << "K";
                break;
            default:
                cout << value;
                break;
        }
        switch (suit) {
            case 0:
                cout << 'H';
                break;
            case 1:
                cout << 'D';
                break;
            case 2:
                cout << 'S';
                break;
            case 3:
                cout << 'C';
                break;
            default:
                cout << "ERROR_IN_SUIT_TYPE";
                break;
        }
    }
    cout << " ";
}
/*
//Set the 2 textures
void Card::setSprite(){
    cardTexture.loadFromFile(GAME_CARD_ATLAS_PATH);
    cardBackTexture.loadFromFile(GAME_CARD_BACK);
    
    cardSprite.setTexture(cardTexture);
    cardSprite.setTextureRect(IntRect(CARD_WIDTH*(value-1), CARD_HEIGHT*suit, CARD_WIDTH, CARD_HEIGHT));
    cardSprite.scale(CARD_SCALE ,CARD_SCALE);
    
    cardBackSprite.setTexture(cardBackTexture);
    cardBackSprite.setTextureRect(IntRect(0, 0, CARD_WIDTH, CARD_HEIGHT));
    cardBackSprite.scale(CARD_SCALE ,CARD_SCALE);
}

Sprite Card::getSprite(){
    if(faceUp){
      return cardSprite;
    }else{
        return cardBackSprite;
    }
}
 
void Card::setSpritePos(Vector2f position){
    cardBackSprite.setPosition(position.x, position.y);
    cardSprite.setPosition(position.x, position.y);
}
*/
//Hand functions ************************************
void Hand::clear(){
    deckCards.clear();
}

Card* Hand::getCard(int index){
    return &deckCards[index];
}

void Hand::deletLastCard(){
    deckCards.pop_back();
}

int Hand::getTotalValue(){
    int value = 0, i;
    for (i = 0; i<deckCards.size(); i++){
        if(deckCards[i].isFaceUp()){
            value += deckCards[i].getGameValue();
        }
    }
    return value;
}

int Hand::getNumberCards(){
    return (int)deckCards.size();
}

void Hand::addCard(Card *c){
    deckCards.push_back(*c);
}

void Hand::consoleDisplay(){
    int i;
    for (i = 0; i<deckCards.size(); i++){
        if(i % 13 == 0){
            cout << endl;
        }
        deckCards[i].consoleDisplay();
    }
}
/*
Sprite Hand::getSprite(int index){
    return deckCards[index].getSprite();
}
*/
//Deck functions ************************************
Deck::Deck(){
    shuffling = false;
}

void Deck::populate(){
    shuffling = true;
    int count = 0, i;
    Card *tempCard = NULL;
    for (i = 0; i<=3; i++) {
        for (int j=1; j<=13; j++) {
            tempCard = new Card(i,j,1, true);
            addCard(tempCard);
            count++;
        }
    }
    free(tempCard);
}

void Deck::shuffle(){
    srand(time(0));
    random_shuffle(begin(deckCards), end(deckCards));
    shuffling = false;
}

void Deck::dealToHand(Hand &_hand){
    int i = getNumberCards() - 1;
    _hand.addCard(getCard(i));
    deletLastCard();
    
    if(deckCards.empty()){
        populate();
        shuffle();
    }
}

//GenericPlayer functions ************************************
bool GenericPlayer::isBusted(){
    return busted;
}
/*
void GenericPlayer::setHandSpawn(Vector2f positionInit){
    int xDisp = 0;
    for (int i = 0; i<deckCards.size(); i++){
        deckCards[i].setSpritePos({positionInit.x + xDisp, positionInit.y});
        xDisp += (CARD_WIDTH*CARD_SCALE)/3.3;
    }
}

Text GenericPlayer::getText(){
    return stikerTotalValue.getText();
}

//StikerTotalValue functions ************************************
StikerTotalValue::StikerTotalValue(){
    fontGlobal.loadFromFile(GAME_GLOBAL_FONT);
    totalValueText.setFont(fontGlobal);
    totalValueText.setFillColor(Color::White);
}

void StikerTotalValue::setTotalVal(int total){
    totalValueText.setString(to_string(total));
}

void StikerTotalValue::setSpawn(Vector2f position){
    totalValueText.setPosition(position.x, position.y);
}

Text StikerTotalValue::getText(){
    return totalValueText;
}
*/


//Player functions ************************************
Player::Player(string _name, string _port, bool _busted, bool _playing, int _bank){
    name = _name;
    port = _port;
    busted = _busted;
    playing = _playing;
    bank = _bank;
}

int Player::getBank(){
    return bank;
}

void Player::bust(){
    busted = true;
}
/*
void Player::setSpawn(int playerNum){
    stikerTotalValue.setTotalVal(getTotalValue());
    switch (playerNum) {
        case 0:
            setHandSpawn({PLAYER_0_X_POSITION,PLAYER_0_Y_POSITION});
            stikerTotalValue.setSpawn({PLAYER_0_X_POSITION-20,PLAYER_0_Y_POSITION-20});
            break;
        case 1:
            setHandSpawn({PLAYER_1_X_POSITION,PLAYER_1_Y_POSITION});
            stikerTotalValue.setSpawn({PLAYER_1_X_POSITION-20,PLAYER_1_Y_POSITION-12});
            break;
        case 2:
            setHandSpawn({PLAYER_2_X_POSITION,PLAYER_2_Y_POSITION});
            stikerTotalValue.setSpawn({PLAYER_2_X_POSITION-20,PLAYER_2_Y_POSITION-20});
            break;
        default:
            break;
    }
}
*/
//Dealer functions ************************************
Dealer::Dealer(string _name, string _port, bool _busted, bool _playing){
    name = _name;
    port = _port;
    busted = _busted;
    playing = _playing;
}

void Dealer::flipFirstCard(){
    deckCards[0].flipCard();
}
/*
void Dealer::setSpawn(){
    setHandSpawn({DEALER_X_POSITION,DEALER_Y_POSITION});
    stikerTotalValue.setTotalVal(getTotalValue());
    stikerTotalValue.setSpawn({DEALER_X_POSITION-30,DEALER_Y_POSITION});
}
*/
