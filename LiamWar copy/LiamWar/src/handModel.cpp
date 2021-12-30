
#include "handModel.hpp"
#include "cardModel.hpp"

void hand::addToHand(card* aCard) {
    _handOfCards.push_back(aCard);
}

void hand::addToHand(std::vector<card *> add) {
    for (int i = 0; i < add.size(); i++) {
        _handOfCards.push_back(add[i]);
    }
}

void hand::setHand(std::vector<card *> initialize) {
    _handOfCards = initialize;
}

card* hand::getCard() {
    card* temp = _handOfCards[0];
    _handOfCards.erase(_handOfCards.begin());
    return temp;
}

int hand::getHandSize() {
    return (int)_handOfCards.size();
}
