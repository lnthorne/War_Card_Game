
#ifndef hand_h
#define hand_h

#include "deckModel.hpp"
#include "cardModel.hpp"

class hand {
public:
//    default constructor
    hand() {}
    
//    destructor
    ~hand() {
        for (auto& it : _handOfCards) {
            delete it;
        }
    }
    
//    adds card to hand
//    @param the card that will be added to hand
    void addToHand(card* aCard);
    
//    adds a vector of cards to current hand 
    void addToHand(std::vector<card*> add);
    
//     @param vector of cards that will initialize the hand
    void setHand(std::vector<card*>);
    
//    returns and deletes card from hand
    card* getCard();
    
//    return size of hand
    int getHandSize();
    
private:
    std::vector<card*> _handOfCards;
};

#endif /* hand_h */
