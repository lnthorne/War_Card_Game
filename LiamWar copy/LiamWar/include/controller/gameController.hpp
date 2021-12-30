
#ifndef gameController_h
#define gameController_h

#include "deckModel.hpp"
#include "standardDeck.hpp"
#include "playerModel.hpp"
#include "textView.hpp"

class gameControl {
public:
//    constructor
//    use of constructor injection for models
    gameControl(deck* dType, player* pType, textView* tv) : _deckType{dType}, _playerType{pType},
    _view{tv} {};
    
//    destructor
    ~gameControl() {
        for (auto& it : _playerTurns) {
            delete it;
        }
        delete _view;
        delete _deckType;
        delete _playerType;
    }
    
//    setup the game
//    initializes deck
//    initializes players
//    calls welcome view
    void gameSetup();
    
//    calls the correct welcome screen
    void welcomeScreen();
    
//    initialize what player is playing
    void initializePlayers();
    
//    initalize deck
    void initializeDeck();
    
    void dealCards();
    
//    checks if one player has all the cards
    bool isWinner(int numOfCards);
    
    
    player* compareCards(player* p1, player* p2);
    
//    gameLoop
//    calls the the setup
//    places player into the game loop
    void gameLoop();
    
//    takes care of the turn logic
    void turnLogic(int& turn);
        
private:
    deck* _deckType;
    player* _playerType;
    textView* _view;
    std::vector<player*> _playerTurns;
    bool _gameIsOver;
};

#endif /* gameController_h */
