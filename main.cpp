#include "Field.h"

Field field;

int main()
{
	char showNextGeneration;
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

	return 0;
}
