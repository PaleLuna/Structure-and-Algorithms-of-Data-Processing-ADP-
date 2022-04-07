#include "Student.h"

unsigned Student::totalPoints()
{
	unsigned sum = 0;
	for (int i = 0; i < 3; i++)
	{
		if (task[i])
		{
			sum += (i + 1) * 10 * ((i > 0) ? i : 1);
		}
	}

	return sum;
}