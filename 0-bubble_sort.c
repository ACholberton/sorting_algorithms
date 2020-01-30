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

void bubble_sort(int *array, size_t size)
{
  size_t i, temp, temp2;
  int swapper;

  do
    {
      swapper = 0;
      for (i = 0; i < size - 1; i++)
	{
	  if (array[i] > array[i + 1])
	    {
	      temp = array[i];
	      array[i] = array[i + 1];
	      array[i + 1] = temp;
	      swapper = 1;

	      for (temp = 0; temp < size; temp++)
		{
		  temp2 = array[temp];
		  if (temp2 > 9)
		    _putchar(temp2 / 10 + '0');

		  _putchar(temp2 % 10 + '0');
		  if (array[temp + 1] != '\0')
		    {
		      _putchar(',');
		      _putchar(' ');
		    }
		}

	      if (swapper == 1)
		_putchar(10);
	    }
	}
    } while (swapper == 1);
}
