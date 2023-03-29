#include "maximum_even.h"

int maximum_even(int* array, size_t size)
{
	size_t maxEven = 0;
	int sz = size;
	if (array && size)
	{
		for (int i = 0; i < sz; i++)
		{
			if (array[i] % 2 == 0)
			{
				if (array[i] > maxEven)
				{
					maxEven = array[i];
				}
			}
		}
	}
	return maxEven;
}
