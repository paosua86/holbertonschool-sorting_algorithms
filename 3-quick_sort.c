#include "sort.h"

/**
 * _swap - swaps two values
 * @array: data sort input
 * @firts: first
 * @second: second
 * @size: size
 * Return: nothing
 */
void _swap(int *array, int firts, int second, int size)
{
	int tmp;

	if (array[firts] != array[second])
	{
		tmp = array[firts];
		array[firts] = array[second];
		array[second] = tmp;
		print_array(array, size);
	}
}

/**
 * part - part to a pivot
 * @array: data sort input
 * @first: first
 * @second: second
 * @size: size input
 * Return: New pivote
 */
int part(int *array, int first, int second, size_t size)
{
	int i = first, j;
    int pivot = array[second];

	for (j = first; j <= second; j++)
	{
		if (array[j] < pivot)
		{
			_swap(array, i, j, size);
			i++;
		}
	}
	_swap(array, i, second, size);

	return (i);
}

/**
 * _quicksort -  quick sort algorithm
 * @array: data to sort
 * @first: first pivote
 * @second: second pivote
 * @size: size input
 * Return: nothing
 */
void _quicksort(int *array, int first, int second, size_t size)
{
	int pivote;

	if (first < second)
	{
		pivote = part(array, first, second, size);
		_quicksort(array, first, pivote - 1, size);
		_quicksort(array, pivote + 1, second, size);
	}
}

/**
 * quick_sort -  sorts an array of integers in ascending order using the Quick
 * sort algorithm.
 * @array: the array to be sorted
 * @size: size of the array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	_quicksort(array, 0, size - 1, size);
}