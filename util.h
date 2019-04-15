//
// Created by admin on 2019/4/14.
//

#ifndef BLACKJACK_UTIL_H
#define BLACKJACK_UTIL_H

#include <vector>
#include <iostream>
#include "Card.h"
#include "dict.h"

/**
 * Shuffle Card Deck
 * @param d card vector
 */
void shuffle(std::vector<Card> &d) {
    Card temp;
    for (int i = 0; i < d.size(); i++) {
        int r = rand() % d.size();
        temp = d[i];
        d[i] = d[r];
        d[r] = temp;
    }
}

/**
 * Initialize The Decl
 * @param d Card Deck
 * @param player Player Hand
 * @param dealer Dealer Hand
 */
void initialize(std::vector<Card> &d,std::vector<Card> &player,std::vector<Card> &dealer) {
    //Clear the deck vector if is not empty
    if (!d.empty()) {
        d.clear();
    }
    if(!player.empty()){
        player.clear();
    }
    if(!dealer.empty()){
        dealer.clear();
    }

    // assigning rank and suit and value to each Card object in vector deck
    for (int i = 0; i < 52; i++) {
        Card temp;
        if (i % 13 == 0)
            temp.setValue(11);
        else if (i % 13 >= 9)
            temp.setValue(10);
        else
            temp.setValue(i % 13 + 1);
        temp.setRank(ranks[i % 13]);
        temp.setSuit(suites[i / 13]);
        d.push_back(temp);
    }
    shuffle(d);
}

/**
 * Deal A Card
 * @param d Deck/Hand
 * @return Card
 */
Card dealfrom(std::vector<Card> &d) {
    Card temp;
    temp = d[d.size() - 1];
    d.pop_back();
    return temp;
}

/**
 * Calculate the sum of the cards
 * @param cards Hand
 * @return Sum of Card
 */
int getCardSum(std::vector<Card> &cards) {
    int sum = 0;
    for (Card c: cards) {
        sum += c.getValue();
    }
    return sum;
}

/**
 * Print out the cards
 * @param cards vector
 */
void printCard(std::vector<Card> &cards) {
    for (Card c: cards) {
        if (c.getRank() == "Ace" && getCardSum(cards) > 10) {
            c.setValue(1);
        }
        c.display();
    }
    std::cout << " =" << getCardSum(cards);
    std::cout << std::endl;
}

/**
 * Print Out Pre-Dealer Card with a ? at the end to hide the last card
 * @param cards
 */
void printPreDealerCard(std::vector<Card> &cards) {
    for (int i = 0; i < cards.size(); i++) {
        if (cards.at(i).getRank() == "Ace" && getCardSum(cards) > 10) {
            cards.at(i).setValue(1);
        }
        if (i == cards.size() - 1)
            std::cout << "?";
        else
            cards.at(i).display();
        std::cout << "\t";
    }
    std::cout << std::endl;
}

/**
 * Prepare for a new game
 * @param player Player hand
 * @param dealer Dealer Hand
 * @param deck
 */
void prepareTable(std::vector<Card> &player, std::vector<Card> &dealer, std::vector<Card> &deck) {
    player.push_back(dealfrom(deck));
    player.push_back(dealfrom(deck));

    dealer.push_back(dealfrom(deck));
}

/**
 * Compare the end result
 * @param player Player Sum
 * @param dealer Dealer Sum
 * @return end result
 */
std::string compareResult(int player, int dealer) {
    if (player > 21) {
        return "Dealer Won";
    } else if (dealer > 21) {
        return "Player Won";
    } else {
        return "Push";
    }
}

#endif //BLACKJACK_UTIL_H
