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
    cardStatus = -1;
    faceUp = true;
    setSprite();
}

Card::Card(int _suit, int _value, int _cardStatus, bool _faceUp){
    suit = _suit;
    value = _value;
    cardStatus = _cardStatus;
    faceUp = _faceUp;
    setSprite();
}

void Card::setCard(int _suit, int _value){
    suit = _suit;
    value = _value;
    setSprite();
}

int Card::getSuit(){
    return suit;
}

int Card::getValue(){
    return value;
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

void Card::setSprite(){
    cardTexture.loadFromFile(GAME_CARD_ATLAS_PATH);
    cardSprite.setTexture(cardTexture);
    cardSprite.scale(CARD_SCALE ,CARD_SCALE);
    cardSprite.setTextureRect(IntRect(CARD_WIDTH*(value-1), CARD_HEIGHT*suit, CARD_WIDTH, CARD_HEIGHT));
}

Sprite Card::getSprite(){
    return cardSprite;
}

void Card::setSpritePos(Vector2f position){
    cardSprite.setPosition(position.x, position.y);
}

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
        value += deckCards[i].getValue();
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

Sprite Hand::getSprite(int index){
    return deckCards[index].getSprite();
}

//Deck functions ************************************
void Deck::populate(){
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
    std::random_shuffle(begin(deckCards), end(deckCards));
}

void Deck::dealToHand(Hand &_hand){
    int i = getNumberCards() - 1;
    _hand.addCard(getCard(i));
    deletLastCard();
}

//GenericPlayer functions ************************************
bool GenericPlayer::isBusted(){
    return busted;
}

void GenericPlayer::setTableHand(Vector2f positionInit){
    int xDisp = 0;
    for (int i = 0; i<deckCards.size(); i++){
        deckCards[i].setSpritePos({positionInit.x + xDisp, positionInit.y});
        xDisp += (CARD_WIDTH*CARD_SCALE)/3.3;
    }
}


//Player functions ************************************
Player::Player(string _name, string _port, bool _busted, bool _playing, int _bank){
    name = _name;
    port = _port;
    busted = _busted;
    playing = _playing;
    bank = _bank;
}

void Player::bust(){
    busted = true;
}

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
