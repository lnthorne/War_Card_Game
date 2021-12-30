
#include <stdio.h>
#include <string>
#include <vector>
#include "standardDeck.hpp"

void standardDeck::setDeck(int numOfDecks) {
    int counter = 0;
    //string arrays that hold values and suits
      std::string Suit[] = { "Heart", "Diamond", "Club", "Spade" };

      std::string Value[] = {
      "Two", "Three", "Four", "Five", "Six", "Seven",
       "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"
       };
    
    while (counter <= numOfDecks) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                card* Card = new card(Suit[i], Value[j], j);
                _mainDeck.push_back(Card);
            }
        }
        counter++;
    }
}
