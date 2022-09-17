#include "Field.h"

Field field;

int main()
{
	field.firstGenerationSetup();
	field.fieldDisplay();

	while (true)
	{
		field.nextGenerationCalculation();
		field.fieldDisplay();
	}

	return 0;
}
