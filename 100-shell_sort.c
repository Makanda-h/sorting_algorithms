#include "sort.h"

/**
*swap - swaps elemnts to arrays
*@array: array
*@item1: array element
*@item2: array element
*/
void swap(int *array, int item1, int item2)
{

	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}
/**
 * shell_sort - sorts array of integers in ascending
 * order using shell sort algorithm, using Knuth sequence
 * @size: size of array
 * @array: numbers lists
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, index = 0;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap = 3 * gap + 1;
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
			for (index = i; index >= gap &&
			 (array[index] < array[index - gap]); index -= gap)
				swap(array, index, index - gap);
		print_array(array, size);
		gap /= 3;
	}
}
