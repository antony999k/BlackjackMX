//
//  blackjack.cpp
//  BlackjackMX
//
//  Created by Antony Morales on 03/03/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#include "blackjack.hpp"
using namespace std;

//Card functions ***************
Card::Card(int s, int v, int cs){
    suit = s;
    value = v;
    cardStatus = cs;
}

void Card::setCard(int s, int v){
    suit = s;
    value = v;
}

unsigned char Card::getSuit(){
    return suit;
}

int Card::getValue(){
    return value;
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

//Deck functions ***************
void Deck::populate(){
    int count = 0, i;
    for (i = 0; i<=3; i++) {
        for (int j=1; j<=13; j++) {
            deckCards[count] = Card(i,j,1);
            count++;
        }
    }
}

void Deck::dealToHand(Hand &h){
    
}

void Deck::consoleDisplay(){
    int i;
    for(i = 0; i<52; i++){
        if(i % 13 == 0){
            cout << endl;
        }
        deckCards[i].consoleDisplay();
    }
}
