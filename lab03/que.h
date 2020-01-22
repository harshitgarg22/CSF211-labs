#ifndef QUE_H_INCLUDED
#define QUE_H_INCLUDED

#include <stdbool.h>
#include "./Element.h"

typedef struct node{
    Element ele;
    struct node *next;
}node;

typedef struct {
    node *head;
    node *tail;
}Queue;

Queue newQ();
bool isEmptyQ(Queue q);
Queue delQ(Queue q);
Element front(Queue q);
Queue addQ(Queue q, Element e);
int lengthQ(Queue q);

#endif