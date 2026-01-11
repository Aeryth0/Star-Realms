#include "create_deck.hpp"
#include "cards.hpp"
#include "deck.hpp"
#include "round.hpp"
#include "myshuffle.hpp"
#include "player.hpp"

std::vector<player> players(2);

int main() {
	int first = 0;
	int turn = turndecide();
	setupGame();

	int gamerollson = 1;

	while (gamerollson == 1) {	
		// başlangıç ve oynama fonksiyonları buraya gelecek
		drawcards(turn % 2, first);
		playround(turn % 2, first);

	   if (players[0].hp <= 0 || players[1].hp <= 0) {

		   if (players[0].hp <= 0) {
			   std::cout << players[0].playername<<	"Has Won!" << std::endl;
		   }
		   else {
			   std::cout << players[1].playername<< "Has Won!" << std::endl;
		   }
		   gamerollson = 0;
	   }

	   turn++;
	}
   
	return 0;
	
}
