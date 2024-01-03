#include "logic.h"
#include "ctime"
#include "cstdlib"

int logic::com_choice() {
	srand(time(NULL));
	int random = rand() % 3 + 1;
	return random;
}

int logic::round(int com_cho, int player_cho, int& com_score, int& player_score) {
	if (com_cho == 1) {
		if (player_cho == 1) return 0;
		if (player_cho == 2) {
			player_score++;
			return 1;
		}
		if (player_cho == 3) {
			com_score++;
			return 2;
		}
	}else if (com_cho == 2) {
		if (player_cho == 2) return 0;
		if (player_cho == 3) {
			player_score++;
			return 1;
		}
		if (player_cho == 1) {
			com_score++;
			return 2;
		}
	}else if (com_cho == 3) {
		if (player_cho == 3) return 0;
		if (player_cho == 1) {
			player_score++;
			return 1;
		}
		if (player_cho == 2) {
			com_score++;
			return 2;
		}
	}
}

