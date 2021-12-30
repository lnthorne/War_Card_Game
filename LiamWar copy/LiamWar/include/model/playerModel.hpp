
#ifndef playerModel_h
#define playerModel_h

#include "handModel.hpp"

class player {
public:
//   default constructor
    explicit player() {}
    
//    virtual destructor
    virtual ~player() {}
    
//    set the name of the player
    void setName(std::string name);
    
//    @return player name
    std::string getName() const;
    
//    set the players hand
    void setHand(hand*);
    
//    @return players hand
    hand* getHand() const;
    
//    add to score
    void addToScore(int score);
    
//    @return the players score 
    int getScore() const;
    
//    add card to compare
    void addToPlayerCompare(card*);
    
//    gets comapre hand
    std::vector<card*> getPlayerCompare();
    
protected:
    std::string _playerName;
    hand* _pHand;
    int _score = 0;
    std::vector<card*> compare;
    
};
#endif /* playerModel_h */
