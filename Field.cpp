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

		if (aliveCellRow >= field.size() or aliveCellRow < 0)
		{
			cout << "There's no such cell!" << endl;
			continue;
		}

		cout << "Column number of position of alive cell: ";
		cin >> aliveCellColumn;
		aliveCellColumn--;

		if (aliveCellColumn >= field[0].size() or aliveCellColumn < 0)
		{
			cout << "There's no such cell!" << endl;
			continue;
		}

		field[aliveCellRow][aliveCellColumn].cellState = 'o';

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
	for (int i = 0; i < field.size(); ++i)
	{

		for (int j = 0; j < field[0].size(); ++j)
		{

			for (int k = i-1; k <= i+1; ++k)
			{

				for (int m = j-1; m <= j+1; ++m)
				{
					if (k >= 0 and k < field.size() and m >= 0 and m < field[0].size())
					{
						if (field[k][m].cellState == 'o')
						{
							++aliveNeighboursCounter;
						}
					}
				}
			}

			if (field[i][j].cellState == 'o')
			{
				--aliveNeighboursCounter;

				if (aliveNeighboursCounter != 2 and aliveNeighboursCounter != 3)
				{
					field[i][j].cellState = '.';
				}
			}

			else
			{
				if (aliveNeighboursCounter == 3)
				{
					field[i][j].cellState == 'o';
				}
			}
		}
	}
}

void Field::fieldDisplay()
{
	cout << "\t ---------------------\n";

	for (int i = 0; i < field.size(); ++i)
	{
		cout << "\t| ";

		for (int j = 0; j < field[0].size(); ++j)
		{
			cout << field[i][j].cellState << ' ';
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
