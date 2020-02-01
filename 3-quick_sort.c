#include "sort.h"

/**
 * swap - Function that swaps two elements
 * @a: The first element to be swapped
 * @b: The second element to be swapped
 * Return: 1. Cannot fail
 * Description: Note that the values being passed in are
 * pointers to the value, not the value itself. This is
 * because passing in the value itself creates a copy of
 * the value for swapping, but the original themselves
 * are not affected. We want the originals to be swapped
 */
int swap(int* a, int* b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;

	return (1);
}

/**
 * partition - Function that "splits" the array up
 * for quick sort use
 * @array: The passed in array
 * @low: The lower end of the array
 * @high: The upper end of the array
 * @size: The size of the array. For printing purposes
 * Return: A number that determines where the beginning
 * or end of the "newly split" array is at
 */
int partition(int *array, int low, int high, size_t size)
{ 
	int pivot = array[high];
	int i = low - 1, j, swapper = 0;
	(void) size;

	for (j = low; j <= high - 1; j++)
	{
		swapper = 0;
		if (array[j] < pivot)
        	{
			i++;
			swapper += swap(&array[i], &array[j]);
		}
	}
	swapper = swap(&array[i + 1], &array[high]);
	return (i + 1);
}

/**
 * qucik_sort_alt - Function that actually does the quick sort
 * @array: The passed in array
 * @low: The lower end of the array
 * @high: The upper end of the array
 * @size: The passed in size. For printing purposes
 * Return: Nothing
 */
void quick_sort_alt(int *array, int low, int high, size_t size)
{
	int part_i;

	if (low < high)
	{
		part_i = partition(array, low, high, size);

		quick_sort_alt(array, low, part_i - 1, size);
		quick_sort_alt(array, part_i + 1, high, size);
	}
}

/**
 * quick_sort - Function that implements the quick sort
 * algorithm
 * @array: The unsorted array
 * @size: The size of the passed in array
 * Return: None
 * Description: This is actually the driver function. As
 * the quick sort algorithm requires knowing the beginning
 * and ending of the array for partitioning purposes,
 * the quick_sort_alt function is created
 */  
void quick_sort(int *array, size_t size)
{ 
	int low = 0, high;

	high = (int)size - 1;
	quick_sort_alt(array, low, high, size);
} 