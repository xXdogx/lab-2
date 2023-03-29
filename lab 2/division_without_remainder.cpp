#include "division_without_remainder.h"

int array_without_remainder(int* array, size_t size)
{
	const int divider = 3;
	int count_without_remainder = 0;
	if (array && size)
	{
		for (long unsigned int i = 0; i <= size; i++)
		{
			if (array[i] % divider == 0)
			{
				count_without_remainder += 1;
			}
		}
	}
	return count_without_remainder;
}