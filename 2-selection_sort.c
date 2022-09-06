#include "sort.h"

/**
 * selection_sort - selection algorthms
 * @size: size input
 * @array: pointer input
 * Return: No Return
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, k, tmp;

	for (i = 0; i < size - 1; i++) /* array length is size - 1*/
	{
		k = i;

		for (j = i + 1; j < size; j++) /*finds the smallest element*/
		{
			if (array[j] < array[k])
			{
				k = j;
			}
		}
		if (k != i)
		{
			tmp = array[k];
			array[k] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
