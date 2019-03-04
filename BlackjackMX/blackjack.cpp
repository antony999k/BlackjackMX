//
//  blackjack.cpp
//  BlackjackMX
//
//  Created by Antony Morales on 03/03/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#include "blackjack.hpp"

//Card functions ************************************
Card::Card(int s, int v, int cs, bool _faceUp){
    suit = s;
    value = v;
    cardStatus = cs;
    faceUp = _faceUp;
}

void Card::setCard(int s, int v){
    suit = s;
    value = v;
}

void Card::swap(Card &c){
    Card temp;
    temp.suit = c.suit;
    temp.value = c.value;
    temp.cardStatus = c.cardStatus;
    
    c.suit = this->suit;
    c.value = this->value;
    c.cardStatus = this->cardStatus;
    
    this->suit = temp.suit;
    this->value = temp.suit;
    this->cardStatus = temp.cardStatus;
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
    cout << " ";
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
    return deckCards.size();
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
    auto rng = default_random_engine {};
    std::shuffle(begin(deckCards), end(deckCards), rng);
}

void Deck::dealToHand(Hand& h){
    int i = getNumberCards() - 1;
    h.addCard(getCard(i));
    deletLastCard();
}


