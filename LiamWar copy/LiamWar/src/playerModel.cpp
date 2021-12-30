
#include <stdio.h>
#include <string>
#include "playerModel.hpp"

void player::setName(std::string name) {
    _playerName = name;
}

std::string player::getName() const {
    return _playerName;
}

void player::setHand(hand* playerHand) {
    _pHand = playerHand;
}

hand* player::getHand() const {
    return _pHand;
}

void player::addToScore(int newScore) {
    _score = newScore;
}

int player::getScore() const {
    return _score;
}

void player::addToPlayerCompare(card* c) {
    compare.push_back(c);
}

std::vector<card*> player::getPlayerCompare() {
    return compare;
}
