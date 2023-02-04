#include "PlayDarts.h"
PlayDarts::PlayDarts()
{
	score = 501;
	bullseye = 0;
	throws = 0;
	wins = 0;
	discounted = false;
}
void PlayDarts::setScore(int a)//sets the score after the dart is thrown 
{
	score = score - a;
}
void PlayDarts::setDiscountedScore(int temp)//if discounted is true goes back to the score before the dart was thrown 
{
	score = temp;
}
void PlayDarts::setThrows()//sets throws to zero 
{
	throws = 0;
}

bool PlayDarts::winCheck()//checks for win
{
	if (getScore() == 0)
		return true;
}
void PlayDarts::SetscoreDiscounted(bool input)//if score goes below zero or 1 it sets the value of discounted to true 
{
	discounted = input;
}
bool PlayDarts::GetscoreDiscounted()//returns discounted 
{
		return discounted;
}
void PlayDarts::CheckscoreDiscounted(int temp)//checks if score is below zero or equals to 1 
{
	if (getScore() < 0 || getScore() == 1 ||GetscoreDiscounted())
	{
		setDiscountedScore(temp);
		SetscoreDiscounted(true);
	}
}
int PlayDarts::throwDart()
{

	if (getScore() == 0)
	{
		return 0;
	}
	else
	{
		for (int i = 1; i >= 0; i--)//rotation between columns of the board array in dart board class 
		{
			for (int aim = 20; aim >= 0; aim--)//choosing a number to aim 
			{
				if (getScore() - player.BullsEye == 0)//if bullseye ends the game go for bullsye 
				{
					dscore = player.throwBullseye(player.accuracy);
					setScore(dscore);
					return 0;
				}
				else if (getScore() - ((board.board[i][aim]) * 2) == 0)//if a double ends the game go for double 
				{
					dscore = player.throwDouble(board.board[i][aim]);
					setScore(dscore);
					return 0;
				}
				else if (getScore() - (aim * 3) >= 2)//if a treble would reduce greater than or equal to 2
				{
					dscore = player.throwTreble(aim, player.accuracy);
					setScore(dscore);
					return 0;
				}
				else if (getScore() - (aim * 2) >= 2)//if a double would reduce greater than or equal to 2
				{
					dscore = player.throwDouble(aim);
					setScore(dscore);
					return 0;
				}
				else if ((getScore() - aim) >= 2  )//if a single would reduce greater than or equal to 2
				{
				dscore = player.throwSingle(aim);
					setScore(dscore);
					return 0;
				}

			}
		}
		return 0;
	}
}
void PlayDarts::startGame()
{


		for (int i = 0; i < 3; i++)//for throwing three darts 
		{
			throws++;

			if (GetscoreDiscounted() != true)//checking if the score is not discounted 
			{
				int tempScore = getScore();//storing score in a tmep in case of score discounting
				throwDart();//throwing a dart 
				CheckscoreDiscounted(tempScore);//checking if the score is discounted
				if (winCheck() == true)//checking if score is zero if it is break the loop
				{
					wins++;
					break;
				}
			}

			SetscoreDiscounted(false);//setting it to false for a new dart throw
			
		}
}


