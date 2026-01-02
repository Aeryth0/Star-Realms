#ifndef CREATE_DECK_HPP
#define CREATE_DECK_HPP

#include <vector>
#include <memory>
#include "cards.hpp"

std::vector<std::unique_ptr<card2>> createUniverseDeck();
std::vector<std::unique_ptr<card2>> createStarterDeck();

#endif