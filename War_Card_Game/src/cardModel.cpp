
#include <stdio.h>
#include "cardModel.hpp"

bool card::operator == (card* compare) const {
    if (_rank == (*compare)._rank)
        return true;
    return false;
}

bool card::operator != (card* compare) const {
    if (_rank == (*compare)._rank)
        return false;
    return true;
}

bool card::operator > (card* comapre) const {
    if (_rank > (*comapre)._rank)
        return true;
    return false;
}

std::string card::getSuit() const {
    return _suit;
}

std::string card::getValue() const {
    return _value;
}

int card::getRank() const {
    return _rank;
}

std::ostream& operator << (std::ostream& out, card* c) {
    out << (*c)._value << " of " << (*c)._suit;
    return out;
}
