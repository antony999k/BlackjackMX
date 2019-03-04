//
//  blackjack.cpp
//  BlackjackMX
//
//  Created by Antony Morales on 03/03/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#include "blackjack.hpp"

//Play game function ************************************
Game::Game(){
    gameWindow = new RenderWindow(VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Blackjack MX");
    gameWindow->setFramerateLimit(FRAME_RATE);
    
    cardTexture = new Texture;
    bgTexture = new Texture;
    cardSprite = new Sprite;
    bgSprite = new Sprite;
    
    cardTexture->loadFromFile(GAME_BACKGROUND_PATH);
    bgTexture->loadFromFile(GAME_CARD_ATLAS_PATH);
    
    cardSprite->setTexture(*cardTexture);
    bgSprite->setTexture(*bgTexture);
    cardSprite->scale(0.5, 0.5);
    
    /*
    Deck gameDeck;
    Dealer dealer;
    vector<Player> players;
    
    Player tempPlayer;
    players.push_back(tempPlayer);
    
    gameDeck.populate();
    gameDeck.populate();
    gameDeck.shuffle();
    //gameDeck.consoleDisplay();
    
    gameDeck.dealToHand(dealer);
    gameDeck.dealToHand(players[0]);
    gameDeck.dealToHand(dealer);
    gameDeck.dealToHand(players[0]);
    dealer.flipFirstCard();
    
    dealer.consoleDisplay();
    players[0].consoleDisplay();
     */
    
    render();
}

void Game::render(){
    //Manage windows event
    while (gameWindow->isOpen()) {
        Event event;
        while (gameWindow->pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    gameWindow->close();
                    break;
            }
        }
        
        gameWindow->clear();
        //Draw Objects
        gameWindow->draw(*bgSprite);//Render the background
        /*
         for (int i = 0; i<player_hand.getNumberCards(); i++) {
         tempCard = player_hand.getCard(i);
         cardSprite.setTextureRect(IntRect(CARD_WIDTH*(tempCard->getValue()-1),CARD_HEIGHT*(tempCard->getSuit()),CARD_WIDTH,CARD_HEIGHT));
         cardSprite.setPosition((CARD_WIDTH*i)/2, (CARD_HEIGHT*0)/2);
         window.draw(cardSprite);
         }*/
        
        cardSprite->setTextureRect(IntRect(0,0,CARD_WIDTH,CARD_HEIGHT));
        cardSprite->setPosition(0, 0);
        gameWindow->draw(*cardSprite);
        gameWindow->display();
    }
}

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
