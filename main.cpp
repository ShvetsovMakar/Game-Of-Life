#include "Field.h"

Field field;

int main()
{
	char showNextGeneration;
	char closeTab;
	field.firstGenerationSetup();
	field.fieldDisplay();

	while (true)
	{
		field.nextGenerationCalculation();
		field.fieldDisplay();
		
		cout << "Do you want to see next generation? Type + if you do: ";
		cin >> showNextGeneration;
		
		if (showNextGeneration != '+')
		{
			break;
		}	
	}
	while (true)
	{
		cout << "Do you want to leave the game? Type + if you do: ";
		cin >> closeTab;
		
		if (closeTab == '+')
		{
			break;
		}
	}
	return 0;
}
