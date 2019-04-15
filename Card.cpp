#include <utility>

//
// Created by admin on 2019/4/8.
//
#include "Card.h"

/**
 * Set Card Rank
 * @param newRank New Rank
 */
void Card::setRank(std::string newRank) {
    rank = std::move(newRank);
}

/**
 * Set Card Suit
 * @param newSuit New Suit
 */
void Card::setSuit(std::string newSuit) {
    suit = std::move(newSuit);
}

/**
 * Set Card Value
 * @param newValue New Value
 */
void Card::setValue(int newValue) {
    this->value = newValue;
}

/**
 * Get Card Rank
 * @return string
 */
std::string Card::getRank() {
    return this->rank;
}

/**
 * Get Card Suit
 * @return string
 */
std::string Card::getSuit() {
    return this->suit;
}

/**
 * Get Card Value
 * @return
 */
int Card::getValue() {
    return this->value;
}

/**
 * Display Card String
 */
void Card::display() {
    std::cout << rank << " of "<< suit;
}

