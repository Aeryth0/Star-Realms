#ifndef ROUND_HPP
#define ROUND_HPP

#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include "cards.hpp"

int turndecide();
void gamestart(int turn);
void setupGame();
void drawcards(int turn);
void playround(int turn);
#endif