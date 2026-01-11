#ifndef ROUND_HPP
#define ROUND_HPP

#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include "cards.hpp"

int first;
int turndecide();
void gamestart(int turn);
void setupGame();
void drawcards(int turn, int first);
void playround(int turn, int first);
#endif