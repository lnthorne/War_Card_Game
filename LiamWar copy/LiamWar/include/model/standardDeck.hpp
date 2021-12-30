
#ifndef standardDeck_h
#define standardDeck_h

#include "deckModel.hpp"

class standardDeck : public deck {
public:
//    default constructor
    standardDeck() {}
    
//    destructor
    ~standardDeck() {}
    
//    creates the deck using the array of strings
    void setDeck(int numOfDecks) override;
};

#endif /* standardDeck_h */
