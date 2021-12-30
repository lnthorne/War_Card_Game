
#include <stdio.h>
#include "gameController.hpp"
#include "cardModel.hpp"
#include "deckModel.hpp"
#include "StandardDeck.hpp"
#include "handModel.hpp"

void gameControl::gameSetup() {
//    display welcome sign
    welcomeScreen();
//    sets type of player
    initializePlayers();
//    create deck and shuffle
    initializeDeck();
//     self
    dealCards();
//    contains the game logic
    gameLoop();
}

void gameControl::welcomeScreen() {
    _view->displayWelcome();
    _view->askForRules();
}

void gameControl::initializePlayers() {
    _playerTurns = _view->configPlayers();
}

void gameControl::initializeDeck() {
    _deckType->setDeck(_view->howManyDecks());
    _deckType->shuffle();
}

void gameControl::dealCards() {
//    iterate through players
//    deal cards returns 26 cards
//    adds it to players hand
    for (auto& it : _playerTurns) {
        hand* pHand = new hand;
        pHand->setHand(_deckType->dealCards());
        it->setHand(pHand);
    }
}

bool gameControl::isWinner(int numOfCards) {
    for (auto& it : _playerTurns) {
        if (it->getHand()->getHandSize() == numOfCards){
            return true;
        }
    }
    return false;
}

player* gameControl::compareCards(player *p1, player *p2) {
    card* ourCard = p1->getHand()->getCard(); // returns "top" card in hand
    card* otherCard = p2->getHand()->getCard();
    std::vector<card*> matching; // if cards have same rank push into here
    player* winner;
    
    
//    call view to show each persons card
    _view->displayCardsToUser(p1, p2, ourCard, otherCard);
    
    if (ourCard == otherCard) {
        bool isEqual = true;
        
        matching.push_back(ourCard);
        matching.push_back(ourCard);
        
//        inform user that war has begun
        _view->tellUserWar();
        
//        while cards are same rank
        while (isEqual) {
            card* ourCard = p1->getHand()->getCard();
            card* otherCard = p2->getHand()->getCard();
            matching.push_back(ourCard);
            matching.push_back(ourCard);
            
            if(ourCard != otherCard) {
                isEqual = false;
                winner = (ourCard > otherCard) ? p1 : p2;
                winner->getHand()->addToHand(matching);
            }
        }
    } else if (ourCard > otherCard) {
        std::cout<< ourCard->getRank() << " ourCard\n" << otherCard->getRank() << " other card\n";
        winner = p1;
        winner->getHand()->addToHand(ourCard);
        winner->getHand()->addToHand(otherCard);
    } else {
        winner = p2;
        winner->getHand()->addToHand(otherCard);
        winner->getHand()->addToHand(ourCard);
    }
    return winner;
}

void gameControl::gameLoop() {
    int turn = 0;
    int numOfCards = _deckType->getSizeOfDeck();
    _gameIsOver = false;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

//     while loop checks for winninh state
    while (!_gameIsOver) {
        _gameIsOver = isWinner(numOfCards);
        turnLogic(turn);
    }
    _view->displayWinner(_playerTurns[turn]);
}


void gameControl::turnLogic(int &turn) {
    player* curPlayer = _playerTurns[turn];
    player* otherPlayer = (turn == 1) ? _playerTurns[0] : _playerTurns[1];
    
//    real user turn
    if (curPlayer->getName() != "NPC") {
        char input = _view->playerOptions(curPlayer);
    
        switch (input) {
            case 'p': {
                std::cout << compareCards(curPlayer, otherPlayer)->getName() << " has won this round\n\n";
                _view->tellUserHandSize(curPlayer, otherPlayer);
                std::cout<< "Please press enter to end turn\n\n";
                std::cin.clear();
                std::cin.ignore();
                turn = (turn == 1) ? 0 : 1;
                break;
            } case 'r': {
                _view->displayRules();
                return;
                break;
            } case 'e': {
                _gameIsOver = true;
                return;
            }
        }
    } else {
        _view->tellUserNPCturn();
        std::cout << compareCards(curPlayer, otherPlayer)->getName() << " has won this round\n\n";
        _view->tellUserHandSize(curPlayer, otherPlayer);
        turn = (turn == 1) ? 0 : 1;
    }
    
}
