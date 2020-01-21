#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "./linkedlist.h"

void push(struct linkedList *head, int ele);
struct node *pop(struct linkedList *head);

#endif 