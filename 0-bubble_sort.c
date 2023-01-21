#include "sort.h"

/**
 * bubble_sort - Bubble sort algorith
 * @array: Array to sort
 * @size: Size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	i = 0;
	while (array && size && i < size)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
		i++;
	}
}
