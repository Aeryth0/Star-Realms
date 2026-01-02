#include "round.hpp"
#include "myshuffle.hpp"
#include "create_deck.hpp"
#include "deck.hpp"
#include "player.hpp"
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <memory>
#include <iostream>
#include <ctime>   
#include <Windows.h>

int turndecide() {
	std::srand(std::time(0));

	int turn = std::rand() % 2; 

	if (turn == 0) {
		std::cout << "Player 1 will start!" << std::endl;
	}
	else {
		
		std::cout << "Player 2 will start!" << std::endl;
	}
	
	return turn;
}

void gamestart(int turn) {
	std::cout << "Game Is Starting!" << std::endl;
	for (int i = 0; i < 3; ++i) {
		players[turn].hand.push_back(std::move(players[turn].deck.back()));
		players[turn].deck.pop_back();
	}
	for (int i = 0; i < players[turn].hand.size(); i++) {
		card2* x = players[turn].hand[i].get();
		std::cout << x->getname() << std::endl;
	}
}

void setupGame() {
	for (size_t i = 0; i < players.size(); i++) {
		players[i].deck = createStarterDeck();
		myshuffle(players[i].deck);
	}

	pazarDestesi = createUniverseDeck();
	myshuffle(pazarDestesi);
}

void drawcards(int turn) {
	int i = 0;

	// Add hand to discard
	while (players[turn].hand.size()) {
		players[turn].discard.push_back(std::move(players[turn].hand.back()));
		players[turn].hand.pop_back();
	}

	// Move discard to deck if deck is fully empty.
	if (players[turn].deck.size() == 0) {
		for (int j = 0; j < players[turn].discard.size(); j++) {
			players[turn].deck.push_back(std::move(players[turn].discard.back()));
			players[turn].discard.pop_back();
		}
		myshuffle(players[turn].deck);
	}

	// If not empty but less than 5, move discard back to deck and add remaining cards to top.
	if (players[turn].deck.size() < 5) {
		// Temporaily save deck to hand
		players[turn].hand = std::move(players[turn].deck);
		// Restore discard back to hand
		myshuffle(players[turn].discard);
		players[turn].deck = std::move(players[turn].discard);
		players[turn].discard.clear();
		// Restore temporary cards back to deck
		while (players[turn].hand.size()) {
			players[turn].deck.insert(players[turn].deck.begin(), std::move(players[turn].hand.back()));
			players[turn].hand.pop_back();
		}
	}

	// Draw cards from deck to hand.
	for (i; i < 5; ++i) {
		players[turn].hand.push_back(std::move(players[turn].deck.back()));
		players[turn].deck.pop_back();
	}
}

void givedamage(int turn, int totaldamage) {
	if (players[(turn + 1) % 2].bases.size()) {
		abort();
	}
	else {
		players[(turn + 1) % 2].hp -= totaldamage;
	}
}

void drawadditionalcards(int turn) {
	// Move discard to deck if deck is fully empty.
	if (players[turn].deck.size() == 0) {
		for (int j = 0; j < players[turn].discard.size(); j++) {
			players[turn].deck.push_back(std::move(players[turn].discard.back()));
			players[turn].discard.pop_back();
		}
		myshuffle(players[turn].deck);
	}

	// Draw one card from deck to hand.
	players[turn].hand.push_back(std::move(players[turn].deck.back()));
	players[turn].deck.pop_back();
}

void discardchoice(int turn) {
	int choice = 0;
	player& p = players[turn];

	std::cout << "Player " << turn << " should discard a card of their choice." << std::endl;
	for (size_t j = 0; j < p.deck.size(); j++) {
		card2* c = p.deck[j].get();
		std::cout << "(" << j << ") " << c->getname() << std::endl;
	}
	std::cin >> choice;
	while (choice > p.deck.size() && choice < 0) {
		std::cout << "Invalid choice!" << std::endl;
		std::cin >> choice;
	}
	p.discard.push_back(std::move(p.deck[choice]));
	p.deck.erase(p.deck.begin() + choice);
}

void junkchoice(int turn) {
	int choice = 0;
	player& p = players[turn];

	std::cout << "You can junk a card if you want. Do you want to? (0/1): "; std::cin >> choice;
	if (!choice) return;

	std::cout << "Cards on deck:" << std::endl;
	size_t j = 0, decksize = p.deck.size();
	for (j = 0; j < p.deck.size(); j++) {
		card2* c = p.deck[j].get();
		std::cout << "(" << j << ") " << c->getname() << std::endl;
	}
	std::cout << std::endl << "Cards on discard:" << std::endl;
	for (; j < p.discard.size()+decksize; j++) {
		card2* c = p.deck[j-decksize].get();
		std::cout << "(" << j << ") " << c->getname() << std::endl;
	}

	std::cout << "Select a card to junk:" << std::endl;
	std::cin >> choice;
	while (choice > j && choice < 0) {
		std::cout << "Invalid choice!" << std::endl;
		std::cin >> choice;
	}
	if (choice < decksize) {
		p.deck.erase(p.deck.begin() + choice);
	}
	else {
		choice -= decksize;
		p.discard.erase(p.discard.begin() + choice);
	}
}

void junkmarket(int turn, bool ask) {
	int choice = 0;
	for (size_t i = 0; i < 5; i++) {
		std::cout << "(" << i << ") " << currentMarket[i].get()->getname() << std::endl;
	}
	if (ask) {
		std::cout << "Do you want to junk a card from current market(0/1): "; std::cin >> choice;
		while (choice > 1 && choice < 0) {
			std::cout << "Invalid choice!" << std::endl;
			std::cin >> choice;
		}
		if (choice == 0) return;
	}
	std::cout << "Select a card from current market to junk: "; std::cin >> choice;
	while (choice > 4 && choice < 0) {
		std::cout << "Invalid choice!" << std::endl;
		std::cin >> choice;
	}
	currentMarket.erase(currentMarket.begin() + choice);
	currentMarket.push_back(std::move(pazarDestesi[pazarDestesi.size()-1]));
	pazarDestesi.pop_back();
}

void destroybase(int turn) {
	player& p = players[turn];
	if (p.bases.size() == 0) return;

	int choice = 0;
	std::cout << "Select a base from player " << turn << "to destroy: " << std::endl;
	for (size_t i = 0; i < p.bases.size(); i++) {
		card2* c = p.bases[i].get();
		std::cout << c->getname() << std::endl;
	}

	std::cin >> choice;
	while (choice > p.bases.size() && choice < 0) {
		std::cout << "Invalid choice!" << std::endl;
		std::cin >> choice;
	}
	p.discard.push_back(std::move(p.bases[choice]));
	p.bases.erase(p.bases.begin() + choice);
}
void actions(int turn, int cond, int param,  card2* c, player& p, int i, int& totaldamage, int& totalheal, int& totalmoney) {
	switch (cond) {
		case COND_CHOICE: {
		int choice = 0;
		std::cout << "Select either of two: ";
		switch (param) {
		case 1:
			std::cout << "(1) " << c->coin << " coins or (2) " << c->heal << "healing :";
			std::cin >> choice;
			if (choice == 1)
				totalmoney += c->coin;
			else
				totalheal += c->heal;
			break;
		case 2:
			std::cout << "(1) " << c->coin << " coins or (2) " << c->heal << "damage :";
			std::cin >> choice;
			if (choice == 1)
				totalmoney += c->coin;
			else
				totaldamage += c->damage;
			break;
		case 3:
			std::cout << "(1) " << c->coin << " healing or (2) " << c->heal << "damage :";
			std::cin >> choice;
			if (choice == 1)
				totalheal += c->heal;
			else
				totaldamage += c->heal;
			break;
		}
		break;
	}
		case COND_DRAW1: drawadditionalcards(turn); break;
		case COND_DRAW2: drawadditionalcards(turn); drawadditionalcards(turn); break;
		case COND_DRAW1_AND_DESTROYBASE: drawadditionalcards(turn); destroybase((turn + 1) % 2); break;
		case COND_DISCARD1: discardchoice((turn + 1) % 2); break;
		case COND_JUNKOWN1: junkchoice(turn); break;
		case COND_JUNKMARKET: junkmarket(turn, 0); break;
		case COND_JUNKMARKETASK: junkmarket(turn, 1); break;
		case COND_DESTROYBASE: destroybase((turn + 1) % 2); break;
		case COND_DESTROYBASEORJUNKMARKET: {
		int choice = 0;
		std::cout << "Do you want to junk a card from current market or destroy a base of the opponent? (0/1): ";
		std::cin >> choice;
		while (choice > 1 && choice < 0) {
			std::cout << "Invalid choice!" << std::endl;
			std::cin >> choice;
		}
		if (choice == 0) junkmarket(turn, 0);
		else destroybase((turn + 1) % 2);
	}
		case COND_DISCARD02:
		case COND_JUNK02: {
		int amount = 0;
		std::cout << "Enter amount of cards you want to junk and draw (0-2): ";
		std::cin >> amount;
		while (amount > 2 && amount < 0) {
			std::cout << "Invalid choice!" << std::endl;
			std::cin >> amount;
		}
		while (amount) {
			junkchoice(turn);
			drawcards(turn);
			amount--;
		}
		break;
	}
		case COND_DRAW2CARDSIF2BASES: {
		if (players[turn].bases.size() >= 2) {
			drawcards(turn);
			drawcards(turn);
		}
	}
		case COND_FREECARD: {
		int choice = 0;
		for (size_t i = 0; i < 5; i++) {
			std::cout << "(" << i << ") " << currentMarket[i].get()->getname() << std::endl;
		}
		std::cout << "Select a card from current market to get for free: "; std::cin >> choice;
		while (choice > 4 && choice < 0) {
			std::cout << "Invalid choice!" << std::endl;
			std::cin >> choice;
		}
		players[turn].discard.push_back(std::move(currentMarket[choice]));
		currentMarket.erase(currentMarket.begin() + choice);
		currentMarket.push_back(std::move(pazarDestesi[pazarDestesi.size() - 1]));
		pazarDestesi.pop_back();
	}
		case COND_FREECARD_AND_TOPDECK: {
			int choice = 0;
			for (size_t i = 0; i < 5; i++) {
				std::cout << "(" << i << ") " << currentMarket[i].get()->getname() << std::endl;
			}
			std::cout << "Select a card from current market to get for free: "; std::cin >> choice;
			while (choice > 4 && choice < 0) {
				std::cout << "Invalid choice!" << std::endl;
				std::cin >> choice;
			}
			players[turn].deck.insert(p.deck.begin(),std::move(currentMarket[choice]));
			currentMarket.erase(currentMarket.begin() + choice);
			currentMarket.push_back(std::move(pazarDestesi[pazarDestesi.size() - 1]));
			pazarDestesi.pop_back();
		}
		case COND_ADDHEALTH: totalheal += param; break;
		case COND_ADDMONEY: totalmoney += param; break;
		case COND_ADDDAMAGE: totaldamage += param; break;
		case COND_DAMAGEPERSHIP: {
			// Only execute this if the card is the last card.
			if (i == p.hand.size() - 1) {
				for (size_t i = 0; i < p.hand.size(); i++) {
					if (p.hand[i].get()->flags ^ 1 << FLAG_BASE) {
						totaldamage++;
					}
				}
			}
			// else move this card to the end.
			else {
				std::unique_ptr<card2> temp = std::move(p.hand[i]);
				p.hand.erase(p.hand.begin() + i);
				p.hand.push_back(std::move(temp));
				i--; return;
			}
			break;
		}
		case COND_DRAWANDJUNK: {
		int choice = 0;
		drawcards(turn);
		std::cout << "You should junk a card from your hand." << std::endl;
		std::cout << "Cards on hand:" << std::endl;
		for (int j = 0; j < p.hand.size(); j++) {
			card2* c = p.hand[j].get();
			std::cout << "(" << j << ") " << c->getname() << std::endl;
		}
		std::cout << "Select a card to junk:" << std::endl;
		std::cin >> choice;
		while (choice > p.hand.size() && choice < 0) {
			std::cout << "Invalid choice!" << std::endl;
			std::cin >> choice;
		}

		p.hand.erase(p.hand.begin() + choice);
		break;
	}
		case COND_DRAWPERBLOB:
		{
			int sz = p.hand.size();
			int choice = 0;
			std::cout << "Do you want to get 5 damage or draw a car per each current BLOB cards? (0/1): ";
			std::cin >> choice;
			while (choice > 1 && choice < 0) {
				std::cout << "Invalid choice!" << std::endl;
				std::cin >> choice;
			}
			if (choice == 0) {
				totaldamage += 5; return;
			}

			for (size_t j = 0; j < sz; j++) {
				if (p.hand[j].get()->faction == FACT_BLOB) {
					drawcards(turn);
				}
			}
			break;
		}

		default:
			break;
		}
}

void playround(int turn) {
	player& p = players[turn];

	// Print cards
	for (size_t i = 0; i < p.hand.size(); i++) {
		card2* x = players[turn].hand[i].get();
		std::cout << x->getname() << std::endl;
	}

	// Play cards
	for (size_t i = 0; i < p.hand.size(); i++) {
		card2* c = p.hand[i].get();
		int totalmoney = 0, totaldamage = 0, totalheal = 0;
		if (c->conditions) {
			actions(turn, c->conditions, c->condParams, c, p, i, totaldamage, totalheal, totalmoney);
		}
		
			if (c->conditions != COND_CHOICE) {
			totalheal += c->heal;
			totalmoney += c->coin;
			totaldamage += c->damage;
			}

		for (size_t j = 0; j < p.hand.size(); j++) {
			if (j != i && c->faction == p.hand[j].get()->faction) {
				actions(turn, c->factConditions, c->factParams, c, p, i, totaldamage, totalheal, totalmoney);
				break;
			}
		}

		// Add coins, hp, damage...
		p.hp += totalheal;
		p.money += totalmoney;
		givedamage(turn, totaldamage);
	}
	return;
}

