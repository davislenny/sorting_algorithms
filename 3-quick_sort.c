#include "sort.h"

/**
 * _swap - swaps two elements
 * @arr: array having the elements
 * @size: size of the array
 * @a: 1st element
 * @b: 2nd element
 * Return: void
 */
void _swap(int *arr, size_t size, int *a, int *b)
{
	int t;

	if (*a != *b)
	{
		t = *a;
		*a = *b;
		*b = t;
		print_array((const int *)arr, size);
	}
}

/**
 * partition - partitions the array
 * @arr: the array to partition
 * @size: array size
 * @low: low index
 * @high: pivot
 * Return: void
 */
size_t partition(int *arr, size_t size, ssize_t low, ssize_t high)
{
	int pivot = arr[high];
	int i = (low - 1);
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			_swap(arr, size, &arr[i], &arr[j]);
		}
	}
	_swap(arr, size, &arr[i + 1], &arr[high]);
	return (i + 1);
}

/**
 * quickSort - The Quick sort algorithm implemetation
 * @arr: the array to sort
 * @size: the array size
 * @low: low index
 * @high: pivot index
 * Return: void
 */
void quickSort(int *arr, size_t size, ssize_t low, ssize_t high)
{
	size_t pi;

	if (low < high)
	{
		pi = partition(arr, size, low, high);
		quickSort(arr, size, low, pi - 1);
		quickSort(arr, size, pi + 1, high);
	}
}

/**
 * quick_sort - calls quickSort
 * @array: array to sort
 * @size: array size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quickSort(array, size, 0, size - 1);
}
