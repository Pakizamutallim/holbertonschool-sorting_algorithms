#include "sort.h"

/**
 * bubble_sort - sorting algorithm
 * @array: list of integers
 * @size: total integers
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (size >= 2)
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size - 1; j++)
			{
				if (j != size - 1 && array[j] > array[j + 1])
				{
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
					print_array(array, size);
				}
			}
		}
	}
}
