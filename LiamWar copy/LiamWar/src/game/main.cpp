
#include <iostream>
#include <curses.h>
#include <limits>
#include "deckModel.hpp"
#include "StandardDeck.hpp"
#include "cardModel.hpp"
#include "handModel.hpp"
#include "playerModel.hpp"
#include "gameController.hpp"
#include "textView.hpp"

int main(int argc, const char * argv[]) {
    
    deck* myDeck = new standardDeck();
    player* myPlayer = new player;
    textView* myView = new textView;
    gameControl warGame(myDeck, myPlayer, myView);
    warGame.gameSetup();
    
    return 0;
}
