#include <stdio.h>
#include <stdlib.h>
#include "cycle.h"
#include <stdbool.h>
#include "memory.h"
#include "list.h"

bool testCyclic(linkedlist ls)
{
	if (ls.count == 0)
		return false;

	struct node *curr = ls.head->next;
	struct node *prev = ls.head;

	while (curr != NULL)
	{
		if (curr == ls.head)
			return true;
		struct node *tmp = curr;
		curr = curr->next;
		tmp->next = prev;
		prev = tmp;
	}
	return false;
}