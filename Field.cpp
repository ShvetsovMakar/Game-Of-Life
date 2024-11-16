#include "Field.h"

// class Field
// functions

void Field::firstGenerationSetup()
{
	while (true)
	{
		cout << "Row number of position of alive cell: ";
		cin >> aliveCellRow;
		aliveCellRow--;

		if (aliveCellRow >= currentGenerationField.size() or aliveCellRow < 0)
		{
			cout << "There's no such cell!" << endl;
			continue;
		}

		cout << "Column number of position of alive cell: ";
		cin >> aliveCellColumn;
		aliveCellColumn--;

		if (aliveCellColumn >= currentGenerationField[0].size() or aliveCellColumn < 0)
		{
			cout << "There's no such cell!" << endl;
			continue;
		}

		currentGenerationField[aliveCellRow][aliveCellColumn].cellState = 'o';

		cout << "Do you want to create another alive cell? Type + if you do: ";

		cin >> newAliveCell;

		if (newAliveCell != '+')
		{
			break;
		}
	}
}

void Field::nextGenerationCalculation()
{
	for (int i = 0; i < currentGenerationField.size(); ++i)
	{

		for (int j = 0; j < currentGenerationField[0].size(); ++j)
		{
			aliveNeighboursCounter = 0;

			for (int k = i-1; k <= i+1; ++k)
			{

				for (int m = j-1; m <= j+1; ++m)
				{
					if (k >= 0 and k < currentGenerationField.size() and m >= 0 and m < currentGenerationField[0].size())
					{
						if (currentGenerationField[k][m].cellState == 'o')
						{
							++aliveNeighboursCounter;
						}
					}
				}
			}

			if (currentGenerationField[i][j].cellState == 'o')
			{
				--aliveNeighboursCounter;

				if (aliveNeighboursCounter != 2 and aliveNeighboursCounter != 3)
				{
					newGenerationField[i][j].cellState = '.';
				}
				else 
				{
					newGenerationField[i][j].cellState = 'o';
				}
			}

			else
			{
				if (aliveNeighboursCounter == 3)
				{
					newGenerationField[i][j].cellState = 'o';
				}
				else 
				{
					newGenerationField[i][j].cellState = '.';
				}
			}
		}
	}
	for (int i = 0; i < currentGenerationField.size(); i++) {
		for (int j = 0; j < currentGenerationField[0].size(); j++) {
			currentGenerationField[i][j] = newGenerationField[i][j];
		}
	}
}

void Field::fieldDisplay()
{
	cout << "\t ---------------------\n";

	for (int i = 0; i < currentGenerationField.size(); ++i)
	{
		cout << "\t| ";

		for (int j = 0; j < currentGenerationField[0].size(); ++j)
		{
			cout << currentGenerationField[i][j].cellState << ' ';
		}

		cout << "|\n";
	}

	cout << "\t ---------------------\n";
}

// class Cell
// class constructor

Field::Cell::Cell(char cellState)
{
	this->cellState = cellState;
}
