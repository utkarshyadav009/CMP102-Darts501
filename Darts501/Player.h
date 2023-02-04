#pragma once
#include "DartBoard.h"
#include<iostream>

class Player: public DartBoard 
{

public:
	Player();
	int accuracy = 80;
	int throwSingle(int aim);
	int throwDouble(int aim);
	int throwTreble(int aim,int accuracy);
	int throwBullseye(int accuracy);
	int throwOuterBull();
	
};

