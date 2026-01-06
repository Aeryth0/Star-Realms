#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "cards.hpp"

enum PlayerFlags {
    FLAG_TOPDECK = 1,
};

class player {
public:
    int hp = 50;
    int money=0;
    int flags = 0;
    std::string playername;
  
    std::vector<std::unique_ptr<card2>> hand;
    std::vector<std::unique_ptr<card2>> deck;
    std::vector<std::unique_ptr<card2>> discard;
    
    std::vector<std::unique_ptr<card2>> bases;

    player() {
        std::cout << "Player name: ";
        std::getline(std::cin, playername);
    }
};

extern std::vector<player> players;
