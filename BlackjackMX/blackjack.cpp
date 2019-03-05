//
//  blackjack.cpp
//  BlackjackMX
//
//  Created by Antony Morales on 03/03/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#include "blackjack.hpp"

//Card functions ************************************
Card::Card(int _suit, int _value, int _cardStatus, bool _faceUp){
    suit = _suit;
    value = _value;
    cardStatus = _cardStatus;
    faceUp = _faceUp;
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
    cardTexture.loadFromFile(GAME_BACKGROUND_PATH);
    cardSprite.setTexture(cardTexture);
    cardSprite.scale(0.5, 0.5);
    cardSprite.setTextureRect(IntRect(CARD_WIDTH*(value-1), CARD_HEIGHT*suit, CARD_WIDTH, CARD_HEIGHT));
}

Sprite Card::getSprite(){
    return cardSprite;
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

//Deck functions ************************************
void Deck::populate(){
    int count = 0, i;
    for (i = 0; i<=3; i++) {
        for (int j=1; j<=13; j++) {
            deckCards.push_back(Card(i,j,1));
            count++;
        }
    }
}

void Deck::shuffle(){
    std::random_shuffle(begin(deckCards), end(deckCards));
}

void Deck::dealToHand(Hand& _hand){
    int i = getNumberCards() - 1;
    _hand.addCard(getCard(i));
    deletLastCard();
}

//GenericPlayer functions ************************************
GenericPlayer::GenericPlayer(string _name, string _port, bool _busted, bool _playing){
    name = _name;
    port = _port;
    busted = _busted;
    playing = _playing;
}

bool GenericPlayer::isBusted(){
    return busted;
}

void GenericPlayer::setPlayer(string _name, string _port){
    name = _name;
    port = _port;
}

//Player functions ************************************
Player::Player(int _bank){
    bank = _bank;
}

void Player::bust(){
    busted = true;
}

//Dealer functions ************************************
void Dealer::flipFirstCard(){
    deckCards[0].flipCard();
}
