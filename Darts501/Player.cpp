#include "Player.h"
Player::Player()
{
}



int Player::throwBullseye(int accuraccy)
{
	//return result of throwing of a double with accuracy 80%
	int r = rand() % 100;

	if (r < (accuracy - 20))
	{
		
		return BullsEye;
	}
	else if (r < 85)
		return OuterBullsEye;
	else
		return 1 + rand() % 20;
}

int Player::throwOuterBull()
{
	//return result of throwing of a double with accuracy 80%
	int r = rand() % 100 + 1;
	if (r < 80)
		return OuterBullsEye;
	else if (r > 80 && r <= 90)
		return BullsEye;
	else {
		int randscore = rand() % 20 + 1;
		return randscore;
	}

}



int Player::throwSingle(int aim)
{
	//  return result of throwing for single aim with accuracy 88% (or 80% for the outer)
	int r = rand() % 100 + 1;

	if (aim == BullsEye)
	{
		throwBullseye(accuracy);
	}
	if (aim == OuterBullsEye)
	{
		throwOuterBull();
	}
	else
		if (r < 88)
			return aim;
		else if (r >88 && r < 92)
			return board[0][aim];
		else if (r > 92 && r < 96)
			return board[1][aim];
		else if (r > 96 && r < 98)
			return 3 * aim;
		else 
			return 2 * aim;
}
int Player::throwDouble(int aim)
{
	//  return result of throwing for double aim with accuracy 80%

	int r = rand() % 100;
	if (aim == BullsEye)
	{
		throwBullseye(accuracy);
	}
	if (aim == OuterBullsEye)
	{
		throwOuterBull();
	}

	if (r < 80)
		return 2 * aim;

	else if (r > 85 && r < 90)
		return aim;
	else if (r > 90 && r < 93)
		return 2 * board[0][aim];
	else if (r > 93 && r < 96)
		return 2 * board[1][aim];
	else if (r > 96 && r < 98)
		return board[0][aim];
	else
		return board[1][aim];
}
int Player::throwTreble(int aim,int accuracy)
{
		//  return result of throwing for treble aim with accuracy 80%  (o<90)

		int r = rand() % 100;
		if (aim == BullsEye)
		{
			throwBullseye(accuracy);
		}
		if (aim == OuterBullsEye)
		{
			throwOuterBull();
		}
			
		if (r < accuracy)
			return 3 * aim;
		else if (r < 90)
			return aim;
		else if (r > 90 && r < 93)
			return 3 * board[0][aim];
		else if (r > 93 && r < 96)
			return 3 * board[1][aim];
		else if (r > 96 && r < 98)
			return board[0][aim];
		else
			return board[1][aim];
}




