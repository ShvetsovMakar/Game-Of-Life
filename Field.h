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
	for (int i = 0; i < 10; ++i)
	{
		field.push_back(vector <Cell>);
		for (int j = 0; j < 10; ++)
		{
			field[i].push_back(Cell);
		}
	}
			
	char newAliveCell;
	int aliveNeighboursCounter = 0;
	int aliveCellRow = 0;
	int aliveCellColumn = 0;

public:
	void firstGenerationSetup();
	void nextGenerationCalculation();
	void fieldDisplay();
};

