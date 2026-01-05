#include "deck.hpp"
#include "cards.hpp"

const char* factNames[] = {
    "tarafsýz aq ",
    "Blob ",
    "Star ",
    "Mech ",
    "Fed "
};

std::vector<std::unique_ptr<card2>> deck = {};
std::vector<std::unique_ptr<card2>> starterdeck = {};
std::vector<std::unique_ptr<card2>> pazarDestesi = {};
std::vector<std::unique_ptr<card2>> currentMarket = {};