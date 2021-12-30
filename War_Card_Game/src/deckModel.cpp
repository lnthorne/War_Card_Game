
#include <stdio.h>
#include <random>
#include <algorithm>
#include "deckModel.hpp"
int SIZE_OF_HAND = 26;

void deck::shuffle() {
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(_mainDeck), std::end(_mainDeck), rng);
}

std::vector<card*> deck::dealCards() {
    std::vector<card*> tempHand;
    
    for (int i = 0; i < SIZE_OF_HAND; i++) {
        tempHand.push_back(_mainDeck[i]);
    }
    _mainDeck.erase(_mainDeck.begin(), _mainDeck.begin() + SIZE_OF_HAND);
    return tempHand;
}

card* deck::removeFromTop() {
    card* tempCard;
    tempCard = _mainDeck[0];
    _mainDeck.erase(_mainDeck.begin());
    
    return tempCard;
}

int deck::getSizeOfDeck() {
    return (int)_mainDeck.size();
}
