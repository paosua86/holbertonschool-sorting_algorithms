#include "sort.h"
/**
 * shell_sort - function that sorts an array of
 * integers in ascending order using the Shell sort
 * algorithm, using the Knuth sequence
 * @array: data sort input
 * @size: data size
 * Return: Nothing
 */

void shell_sort(int *array, size_t size)
{

	size_t gap = 1, i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j = j - gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}

