#include "main.h"

list_t *insert_node(list_t **head, int number)
{
	list_t *node = NULL;

	if (!head)
		return (NULL);

	node = malloc(sizeof(list_t));
	if (!node) /* node == NULL */
		return (NULL);

	node->n = number;
	node->next = *head;

	*head = node;

	return (node);
}

void print_list(list_t *head)
{
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

int main(void)
{
	list_t *head = NULL;

	insert_node(&head, 1);
	insert_node(&head, 2);
	insert_node(&head, 3);
	insert_node(&head, 4);
	insert_node(&head, 5);

	print_list(head);
	return (0);
}
