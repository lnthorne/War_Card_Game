
#ifndef deckModel_h
#define deckModel_h

#include <vector>
#include "cardModel.hpp"

// Interface for creation of a deck
class deck {
public:
//    Default constructor
    deck() {}
    
//    virtual destructor
//    delete all card pointers from hand after instance
    virtual ~deck() {
        for (auto& it : _mainDeck) {
            delete it;
        }
    }
    
//    method that creates the actual deck
//    @param sets the number of decks created
    virtual void setDeck(int numOfDecks) = 0;
    
//    method that shuffles the deck
//    using the default random engine from cpp
    void shuffle();
    
//    deals 4 cards to player
//    adds 4 cards to temp vector
//    detetes from mainDeck
//    @return temp vector of 4 cards
    std::vector<card*> dealCards();
    
//    removes top card from deck
//    @return card* from mainDeck
    card* removeFromTop();
    
//    gets size of deck
//    @return integer
    int getSizeOfDeck();
    
protected:
    std::vector<card*> _mainDeck;
};

#endif /* deckModel_h */
