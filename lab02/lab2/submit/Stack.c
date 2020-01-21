#include "./Stack.h"
#include "./linkedlist.h"
#include<stdio.h>

void push(struct linkedList *head, int ele){
    insertFirst(head, ele);
}

struct node *pop(struct linkedList *head){
    if(head->count!=0){
        printf("%d\n", head->count);
        return deleteFirst(head);
    }
    else{
        printf("Stack empty\n");
        return NULL;
    }
}
