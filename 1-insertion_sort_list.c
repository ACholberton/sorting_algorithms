#include "sort.h"

/**
 * final_swap - Function that swaps the first two nodes
 * of the linked list if it needs swapping. After this
 * the insertion sort ends
 * @list: The almost completely sorted linked list
 * @current: Pointer to the node to be swapped
 * Return: Nothing
 */
void final_swap(listint_t **list, listint_t *current)
{
	current = *list;
	if (current->n > current->next->n)
	{
		list_swapper(current);
		*list = (*list)->prev;
		print_list(*list);
	}
}

/**
 * list_swapper - Function that moves the position of two nodes
 * by altering which nodes come before and after them
 * @current: The pointer to the current node for altering
 * Return: Nothing
 * Description: Also checks whether the node before or after
 * is a NULL pointer, as attempting to connect to NULL will cause
 * a segmentation fault
 */
void list_swapper(listint_t *current)
{
	listint_t *temp = NULL;

	temp = current->next;
	current->next = current->next->next;
	temp->next = current;
	if (current->next != NULL)
		current->next->prev = current;

	temp->prev = temp->prev->prev;
	if (temp->prev != NULL)
		temp->prev->next = temp;

	current->prev = temp;
}

/**
 * insertion_sort_list - Function that sorts a doubly linked list
 * @list: The doubly linked list to be sorted
 * Return: Nothing
 * Description: Each node is checked and swapped accordingly. When
 * the pointer reaches the end of the list, another check is conducted
 * to check if there are still any unsorted nodes. If there are, reset
 * the pointer and conduct the swap
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list, *list_scan = NULL, *head = *list;

	if (*list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		if (current->next == NULL)
		{
			list_scan = head;
			while (list_scan != NULL)
			{
				if (list_scan->next == NULL)
				{
					final_swap(list, current);
					return;
				}
				if (list_scan->n > list_scan->next->n)
				{
					current = *list, list_scan = *list;
					break;
				}
				list_scan = list_scan->next;
			}
		}
		else if (current->n > current->next->n)
		{
			list_swapper(current);
			while ((*list)->prev != NULL)
				if ((*list)->n > (*list)->prev->n)
					*list = (*list)->prev;

			print_list(*list);
		}
		else
			current = current->next;
	}
}
