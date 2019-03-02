//
//  main.cpp
//  BlackjackMX
//
//  Created by Antony Morales on 02/03/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

int main(int argc, const char * argv[]) {
    RenderWindow window(sf::VideoMode(600,600), "Blackjack MX");
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    window.close();
                    break;
            }
        }
        
        window.clear(Color::White);
        //Draw Objects
        window.display();
    }
}
