#include "sort.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
  return (write(1, &c, 1));
}

void selection_sort(int *array, size_t size)
{
  size_t i, j, k, min_index;
  int min_value, temp;

  for (i = 0; i < size - 1; i++)
    {
      min_index = i;
      min_value = array[i];
      for (j = i + 1; j < size; j++)
	{
	  if (array[j] < min_value)
	    {
	      min_value = array[j];
	      min_index = j;
	    }
	}
      array[min_index] = array[i];
      array[i] = min_value;
      for (k = 0; k < size; k++)
	{
	  temp = array[k];
	  if (temp > 9)
	    _putchar(temp / 10 + '0');
	  _putchar(temp % 10 + '0');
	  if (array[k + 1] != '\0')
	    {
	      _putchar(',');
	      _putchar(' ');
	    }
	}
      _putchar('\n');
    }
}
