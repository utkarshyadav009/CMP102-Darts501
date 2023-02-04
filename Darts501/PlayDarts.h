#pragma once
#include "Player.h"
#include"DartBoard.h"
class PlayDarts

{
	int throws;//to record number of throws 
	int bullseye ;//for recording number of bullseyes 
	int wins ;//for number of wins 
	unsigned int score;//for score 
	bool discounted;//check if score is 1 or -ve 
public:
	PlayDarts();
	Player player;
	DartBoard board;
	int dscore=0;
	int getScore() { return score; }
	void setThrows();
	void setScore(int a);
	void setDiscountedScore(int a);
	bool winCheck();
	void SetscoreDiscounted(bool discounted);
	bool GetscoreDiscounted();
	void CheckscoreDiscounted(int temp);
	int getThrows() { return throws; }
	int getWins() { return wins; }
	void setWins() { wins = 0; }
	int getBullseyes() { return bullseye; }
	void startGame();
	int throwDart();
	void setDarts501() { score = 501; }
		
};

