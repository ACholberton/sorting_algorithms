#include "sort.h"

/**
 *shell_sort - function that sorts an array of integers in ascending order using
 *the Shell sort algorithm, using the Knuth sequence.
 *@array: is the array to be sorted.
 *@size: is the size of the array.
 *Return: nothing
 */

void shell_sort(int *array, size_t size)
{
	unsigned int j, i, gap = 1;
	int tmp;

	if (array == NULL || size < 2)
		return;
	for(gap = size/2; gap > 0; gap /= 2)
	{
		for(i = gap; i < size; i++)
		{
			tmp = array[i];
			for(j = i; j >= gap && tmp < array[j-gap];
			    j -= gap)
			{
				array[j] = array[j-gap];
			}
			array[j] = tmp;
		}
		print_array(array, size);
	}
}