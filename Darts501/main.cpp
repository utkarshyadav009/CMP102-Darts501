#include<iostream>
using namespace std;
#include"PlayDarts.h"
#include"Player.h"
#include<ctime>
#include<cstdlib>

void main()
{

	srand(time(NULL));
	
	int draws = 0;
	bool sidfirst = true;
	int joesetwin = 0;
	int sidsetwin = 0;
	int sim71 = 0, sim72 = 0, sim73 = 0, sim74 = 0, sim75 = 0, sim76 = 0, sim67 = 0,sim57 =0, sim47 = 0, sim37 = 0, sim27 = 0, sim17 = 0, sim66 = 0,sim07=0,sim70 = 0 ;//different variables for different simulation  outcomes 
	PlayDarts Joe;
	PlayDarts Sid;
	for (int i = 0; i < 10000; i++)//10,000 championship simulations 
	{

		for (int sets = 0; sets < 13; sets++) //13 sets in a championship 
		{
			for (int games = 0; games < 5; games++)//5 games for each set 
			{
				//	cout << "WOW";
				while (Sid.getScore() != 0 && Joe.getScore() != 0)//loops going to run until joe or sid score's zero 
				{
					if (sidfirst == true)//sid goes first 
					{
						Sid.startGame();
						if (Sid.getScore() != 0)//checing if sid's score is zero after the throws 
						{
							Joe.startGame();
						}
					}
					else if (sidfirst == false)//joe goes first
					{
						Joe.startGame();
						if (Joe.getScore() != 0)//checing if joe's score is zero after the throws 
						{
							Sid.startGame();
						}
					}

				}
				if (Sid.getScore() == 0)
				{
					sidfirst = false;
				}
				else if (Joe.getScore() == 0)
				{
					sidfirst = true;
				}
				if (Sid.getWins() == 3)//if game wins is equal to 3 break the games loop and increment sidsetwin  
				{
					sidsetwin++;
					break;
				}
				if (Joe.getWins() == 3)//if game wins is equal to 3 break the games loop and increment joesetwin
				{
					joesetwin++;
					break;
				}


				Sid.setDarts501();//setting score zero 
				Joe.setDarts501();

			}
			//cout << endl;
			if (sidsetwin == 7)
			{
				//cout << "Sid won the chapionship" << endl;
				break;
			}
			if (joesetwin == 7)
			{
				//cout << "Joe won the chapionship" << endl;
				break;
			}
			Sid.setDarts501();//setting score zero 
			Joe.setDarts501();
			Sid.setWins();//setting wins zero 
			Joe.setWins();

		}
		//checking of eaach possible outcome
		if(sidsetwin==7&&joesetwin == 1)
		{
			sim71++;
			
		}
		if (sidsetwin == 6 && joesetwin == 7)
		{
			sim67++;
			
		}
		if (sidsetwin == 7 && joesetwin == 6)
		{
			sim76++;
			
		}
		if (sidsetwin == 7 && joesetwin == 5)
		{
			sim75++;
			
		}
		if (sidsetwin == 7 && joesetwin == 4)
		{
			sim74++;
			
		}
		if (sidsetwin == 7 && joesetwin == 3)
		{
			sim73++;
			
		}
		if (sidsetwin == 7 && joesetwin == 2)
		{
			sim72++;
			
		}
		if (sidsetwin == 5 && joesetwin == 7)
		{
			sim57++;

		}
		if (sidsetwin == 4 && joesetwin == 7)
		{
			sim47++;

		}
		if (sidsetwin == 3 && joesetwin == 7)
		{
			sim37++;

		}
		if (sidsetwin == 2 && joesetwin == 7)
		{
			sim27++;

		}
		if (sidsetwin == 1 && joesetwin == 7)
		{
			sim17++;

		}
		if (sidsetwin == 6 && joesetwin == 6)
		{
			sim66++;

		}
		if (sidsetwin == 0 && joesetwin == 7)
		{
			sim07++;

		}
		if (sidsetwin == 7 && joesetwin == 0)
		{
			sim70++;

		}
		
		
		joesetwin = 0;
		sidsetwin = 0;

	}

	//return 0;
	//displaying everything
	cout << "Joe : Sid" << endl;
	cout << " 6  :  7   " << ((float)sim76 / 10000) * 100 <<"%"<< endl;
	cout << " 5  :  7   " << ((float)sim75/10000)*100 << "%" << endl;
	cout << " 4  :  7   " << ((float)sim74 / 10000) * 100 << "%" << endl;
	cout << " 3  :  7   " << ((float)sim73 / 10000) * 100 << "%" << endl;
	cout << " 2  :  7   " << ((float)sim72 / 10000) * 100 << "%" << endl;
	cout << " 1  :  7   " << ((float)sim71 / 10000) * 100 << "%" << endl;
	cout << " 7  :  6   " << ((float)sim67 / 10000) * 100 << "%" << endl;
	cout << " 7  :  5   " << ((float)sim57 / 10000) * 100 << "%" << endl;
	cout << " 7  :  4   " << ((float)sim47 / 10000) * 100 << "%" << endl;
	cout << " 7  :  3   " << ((float)sim37 / 10000) * 100 << "%" << endl;
	cout << " 7  :  2   " << ((float)sim27 / 10000) * 100 << "%" << endl;
	cout << " 7  :  1   " << ((float)sim17 / 10000) * 100 << "%" << endl;
	cout << " 6  :  6   " << ((float)sim66 / 10000) * 100 << "%" << endl;
	cout << " 7 :   0   " << ((float)sim07 / 10000) * 100 << "%" << endl;
	cout << " 0  :  7   " << ((float)sim70 / 10000) * 100 << "%" << endl;
	system("pause");

}
