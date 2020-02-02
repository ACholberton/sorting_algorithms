#ifndef SORT_H
#define SORT_H

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_alt(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);
void swap(int *a, int *b);
void final_swap(listint_t **list, listint_t *current);
void list_swapper(listint_t *current);
void shell_sort(int *array, size_t size);
void forward_Shake(listint_t *current);
void backward_shake(listint_t *current);
void cocktail_shaker(listint_t **list);
void cocktail_sort_list(listint_t **list);

#endif
