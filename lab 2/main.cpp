#include <exception>
#include <iostream>
#include <cstddef>
#include <fstream>
#include "division_without_remainder.h"
#include "maximum_even.h"

int main(int argc, char* argv[])
{
	int static_array[] = {-5, 24, 14, -7, 33, 12, 90};
	std::cout << array_without_remainder(static_array, 7) << "\n";
	std::cout << maximum_even(static_array, 7) << "\n";
	size_t x;
	std::cin >> x;
	if (!std::cin)
	{
		std::cout << "You didn't enter a value " << "\n";
		return 1;
	}
  std::srand(time(nullptr));
	if (x > 0)
	{
		int* dynamic_array = new int[x];
		for (size_t i = 0; i < x; i++)
		{
			dynamic_array[i] = std::rand();
		}
		std::cout << maximum_even(dynamic_array, x) << "\n";
		std::cout << array_without_remainder(dynamic_array, x) << "\n";
		delete[] dynamic_array;
	}
  else
  {
    std::cout << "The number of element couldn't be zero \n";
  }
  if (argc == 1)
  {
    std::cout << "File is not correct";
    return 1;
  }
  if (argc > 2)
  {
    std::cout << "Parameters are not correct";
    return 1;
  }
  std::ifstream file(argv[1]);
  if (!file.is_open())
  {
    std::cout << "Error while opening file";
    return 1;
  }
  while (!file.eof())
  {
    size_t reading_array_size = 0;
    file >> reading_array_size;
    if (!file)
    {
      std::cout << "Error";
      return 1;
    }
    int* reading_array = new int[reading_array_size];
    for (size_t i = 0; i < reading_array_size; i++)
    {
      file >> reading_array[i];
      if (!file)
      {
        std::cout << "Error";
        delete[] reading_array;
        return 1;
      }
    }
    try
    {
      std::cout << maximum_even(reading_array, reading_array_size) << " ";
      std::cout << array_without_remainder(reading_array, reading_array_size) << " ";
    }
    catch (const std::overflow_error& e)
    {
      std::cout << e.what();
      delete[] reading_array;
      return 2;
    }
    delete[] reading_array;
  }
  return 0;
}