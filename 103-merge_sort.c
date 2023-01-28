#include "sort.h"

/**
 * TopDownMerge - compare splits
 * @array: array to sort
 * @start: start index
 * @stop: stop index
 * @new: merged array
 * Return: void
 */
void TopDownMerge(int *array, size_t start, size_t stop, int *new)
{
	size_t i = start, j, k, mid;

	j = mid = (start + stop) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, stop - mid);
	for (k = start; k < stop; k++)
		if (i < mid && (j >= stop || array[i] <= array[j]))
		{
			new[k] = array[i++];
		}
		else
		{
			new[k] = array[j++];
		}
	printf("[Done]: ");
	print_array(new + start, stop - start);
}

/**
 * TopDownSplit - split array
 * @array: array to sort
 * @start: start index
 * @stop: stop index
 * @new: output array
 * Return: void
 */
void TopDownSplit(int *array, size_t start, size_t stop, int *new)
{
	size_t mid;

	mid = (start + stop) / 2;
	if (stop - start < 2)
	{
		return;
	}
	TopDownSplit(new, start, mid, array);
	TopDownSplit(new, mid, stop, array);
	TopDownMerge(new, start, stop, array);
}

/**
 * merge_sort - Merge Sort algorithm
 * @array: array to srot
 * @size: size of the array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *new;
	size_t i;

	if (!array || size < 2)
		return;

	new = malloc(sizeof(int) * size);
	if (!new)
		return;
	for (i = 0; i < size; i++)
		new[i] = array[i];
	TopDownSplit(array, 0, size, new);
	free(new);
}
