#include "sort.h"
/**
 * insertion_sort_list - sort doubly linked list
 * of integers in ascending order using Insertion sort algorithm
 * @list: Dobule linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}
/**
 *swap_node - swap a node for the prev one
 *@node: node
 *@list: node list
 *Return: returns pointer to node
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current = node;
	/*NULL, 19, 48, 9, 71, 13, NULL*/

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}
