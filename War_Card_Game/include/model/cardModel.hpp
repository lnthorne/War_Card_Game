
#ifndef cardModel_h
#define cardModel_h

#include <string>
#include <iostream>

class card {
public:
//    default constructor
//    @param suit, suit of the card
//    @param val, value of the card
    card(std::string suit, std::string val, int rank) : _suit{suit}, _value{val}, _rank{rank} {}
    
//    destructor
    ~card() {}
    
//    operator (==) overload to compare two cards
//    @param card object to compare
//    @return bool, true if a == b
    bool operator == (card*) const;
    
//    operator (!=) overload to compare two cards
//    @param Card object
//    @return BOOLEAN
    bool operator != (card*) const;
    
//    operator (>) overload to compare two cards
//    @param card pointer
//    @return boolean: true if >
    bool operator > (card*) const;
    
//    ostream (<<) overload to print the cards
    friend std::ostream& operator << (std::ostream&, card*);
    
//    returns the suit
    std::string getSuit() const;
    
//    returns the value
    std::string getValue() const;
    
//    returns an integer of the rank of card
    int getRank() const;

private:
    std::string _suit;
    std::string _value;
    int _rank;
};
#endif /* cardModel_h */
