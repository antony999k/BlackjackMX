//
//  blackjack.cpp
//  BlackjackMX
//
//  Created by Antony Morales on 03/03/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#include "blackjack.hpp"

//Card constructor
Card::Card(unsigned char s, int v, int cs){
    suit = s;
    value = v;
    cardStatus = cs;
}

void Card::setCard(unsigned char s, int v){
    suit = s;
    value = v;
}
