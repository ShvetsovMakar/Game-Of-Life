#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Field
{
private:

	class Cell
	{
		
	public:
		char cellState = '.';
	};

	vector <vector <Cell>> field;
			
	char newAliveCell;
	int aliveNeighboursCounter = 0;
	int aliveCellRow = 0;
	int aliveCellColumn = 0;

public:
	void firstGenerationSetup();
	void nextGenerationCalculation();
	void fieldDisplay();
};

