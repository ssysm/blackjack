//
// Created by admin on 2019/4/8.
//

#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

#include <iostream>

class Card {
private:
    std::string rank, suit;
    int value;

public:

    void setRank(std::string newRank);

    void setSuit(std::string newSuit);

    void setValue(int newValue);

    std::string getRank();

    std::string getSuit();

    int getValue();

    void display();

};


#endif //BLACKJACK_CARD_H
