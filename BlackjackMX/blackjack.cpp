//
//  blackjack.cpp
//  BlackjackMX_Server
//
//  Created by Antony Morales and Esmeralda Magadaleno on 10/05/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#include "blackjack.hpp"

/* Card functions
 ***********************************************************************************************/
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
    cout << " \n";
}

/* Hand functions
***********************************************************************************************/
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

/* Deck functions
 ***********************************************************************************************/
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

/* GenericPlayer functions
 ***********************************************************************************************/
bool GenericPlayer::isBusted(){
    return busted;
}


vector<Card> GenericPlayer::getDeck(){
    return deckCards;
}

/* Player functions
 ***********************************************************************************************/
Player::Player(){
    name = "Usuario" + to_string(1 + rand() % 1000);
    port = "0";
    playerId = 0;
    busted = false;
    playing = false;
    bank = 1000;
}

Player::Player(string _name, string _port, unsigned int _playerId){
    name = _name;
    port = _port;
    playerId = _playerId;
    busted = false;
    playing = false;
    bank = 1000;
}

int Player::getBank(){
    return bank;
}

void Player::bust(){
    busted = true;
}

unsigned int Player::getPlayerId(){
    return playerId;
}

string Player::getUsername(){
    return name;
}

/* Player functions
 ***********************************************************************************************/
Dealer::Dealer(){
    name = "Dealer";
    port = "0";
    busted = false;
    playing = false;
}

Dealer::Dealer(string _name, string _port){
    name = _name;
    port = _port;
    busted = false;
    playing = false;
}

void Dealer::flipFirstCard(){
    deckCards[0].flipCard();
}

