#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *              using the Bubble sort algorithm
 * @array: Pointer to the array
 * @size: Number of elements in array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, n;
	int tmp;
	int swapped;

	if (array == NULL || size < 2)
		return;

	n = size;
	swapped = 1;

	while (swapped)
	{
		swapped = 0;
		for (i = 0; i < n - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				swapped = 1;
				print_array(array, size);
			}
		}
		/* After each pass, the largest element is at the end */
		n--;
	}
}
