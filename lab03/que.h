#ifndef QUE_H_INCLUDED
#define QUE_H_INCLUDED

#include <stdbool.h>
#include "./Element.h"

typedef struct{
    Element ele;
    struct node *next;
}node;

typedef struct {
    struct node *head;
    struct node *tail;
}Queue;

Queue newQ();
bool isEmptyQ(Queue q);
Queue delQ(Queue q);
Element front(Queue q);
Queue addQ(Queue q, Element e);
int lengthQ(Queue q);

#endif