
#ifndef textView_h
#define textView_h

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

class textView {
public:
    textView() {}
    ~textView() {}
    
    void displayWelcome() {
        string getContent;
        fstream openfile("WarTitle.txt");
        
        if (openfile.is_open()) {
            while (!openfile.eof()) {
                  getline(openfile, getContent);
                  std::cout << getContent << std::endl;
                }
                std::cin.ignore();
            std::cin.clear();
        }
        std::cout << std::endl << std::endl;
    }
    
    void askForRules() {
        char input;
        cout << "Would you like to display rules ? (Y/N): ";
        cin >> input;
        
        input = tolower(input);
        
        if (isalpha(input) && input == 'y') {
          displayRules();
        } else if (input != 'n') {
//          displayInputErrorMessage();
          askForRules();
        }
    }
    
    void displayRules() {
        string getContent;
        fstream openfile("warRules.txt");
        
        if (openfile.is_open()) {
            while (!openfile.eof()) {
                  getline(openfile, getContent);
                  std::cout << getContent << std::endl;
                }
            std::cout << "\n\n";
        }
    }
    
    std::vector<player*> configPlayers() {
        std::vector<player*> playerType;
        
        char input;
        std::cout << "Are 2 people playing, or one player versus an AI ?\n";
        std::cout << "(P for 2 players, A for 1 player and an NPC)\n";
        std::cout << "> ";
        std::cin >> input;
        input = tolower(input);
        
        do {
            if (input == 'p') {
                std::string p1name;
                std::string p2name;
                std::cout << "\nGreat, what is player 1's name ? : ";
                std::cin >> p1name;
                std::cout << "Player 2's name ? : ";
                std::cin >> p2name;
                player* p1 = new player;
                player* p2 = new player;
                p1->setName(p1name);
                p2->setName(p2name);
                playerType.push_back(p1);
                playerType.push_back(p2);
                break;
            } else if (input == 'a') {
                std::string playerName;
                std::cout << std::endl << "Playing against an NPC" << std::endl;
                std::cout << "Your name ? : ";
                std::cin >> playerName;
                player* p1 = new player;
                player* p2 = new player;
                p1->setName(playerName);
                p2->setName("NPC");
                playerType.push_back(p1);
                playerType.push_back(p2);
                break;
            } else {
                std::cout<< "Please enter valid input\n";
                std::cin >> input;
                input = tolower(input);

            }
        } while (input != 'p' || input != 'a');
        
        return playerType;
    }
    
    int howManyDecks() {
        int numOfDecks;
        std::cout<< "how many decks would you like to play with ? : ";
        std::cin >> numOfDecks;
        std::cout<< "\n\n";
        return numOfDecks;
    }
    
    char playerOptions(player* plyr) {
        char input;
        std::cout<< "O P T I O N S\n"
                 << plyr->getName() << " please pick one\n"
                 << "p: pull top card\n"
                 << "r: display rules\n"
                 << "e: End Game\n"
                 << "> ";
        std::cin >> input;
        input = tolower(input);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if (input != 'p' && input != 'r' && input != 'e') {
            std::cout << "Incorrect input\n";
            return playerOptions(plyr);
        }
        return input;
    }
    
    void displayCardsToUser(player* p1, player* p2, card* c1, card* c2) {
        std::cout << p1->getName() << " has a " << c1 << std::endl
                  << p2->getName() << " has a " << c2 << std::endl << std::endl;
    }
    
    void tellUserWar() {
        std::cout<< "It appears that the cards are matching. Ready up! we are going to war\n";
    }
    
    void tellUserHandSize(player* winner, player* loser) {
        std::cout << winner->getName() << " has " << winner->getHand()->getHandSize()
                << " cards left in hand\n\n";
        std::cout << loser->getName() << " has " << loser->getHand()->getHandSize()
                << " cards left in hand\n\n";
    }
    
    void tellUserNPCturn() {
        std::cout<< "It is now the NPC's turn please wait\n\n";
    }
    
    void displayWinner(player* winner) {
        std::cout << "C O N G R A D U L A T I O N S !\n" << winner->getName()
        << " HAS WON THE GAME\n";
    }
};

#endif /* textView_h */
