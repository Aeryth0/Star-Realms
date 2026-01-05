#include "create_deck.hpp"
#include "cards.hpp"
#include "deck.hpp"
#include "round.hpp"
#include "myshuffle.hpp"
#include "player.hpp"

std::vector<player> players(2);

int main() {
	int turn = turndecide();
	setupGame();

	std::cout << "Oyun Yuklendi! Destede " << pazarDestesi.size() << " kart var." << std::endl;
	for (int i = 0; i < pazarDestesi.size(); i++) {
		card2* x = pazarDestesi[i].get();
		std::cout << x->getname() << std::endl;

	}
	int gamerollson = 1;

	for (size_t i = 0; i < players.size(); i++) {
		std::cout << "Starting Deck Of  " << players[i].playername << std::endl;
		std::cout << "------------------------------------" << std::endl;
		for (size_t j = 0; j < players[i].deck.size(); j++) {
			card2* x = players[i].deck[j].get();
			std::cout << x->getname() << std::endl;
		}
	}
	
	gamestart(turn);
	playround(turn); turn++;
	
	while (gamerollson == 1) {	
		// başlangıç ve oynama fonksiyonları buraya gelecek
		drawcards(turn % 2);
		playround(turn % 2);

	   if (players[0].hp <= 0 || players[1].hp <= 0) {

		   if (players[0].hp <= 0) {
			   std::cout << "Player 2 Has Won!!" << std::endl;
		   }
		   else {
			   std::cout << "Player 1 Has Won!" << std::endl;
		   }
		   gamerollson = 0;
	   }

	   turn++;
	}
   
	return 0;
	
}
