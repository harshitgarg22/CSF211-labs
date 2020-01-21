#include "./linkedlist.h"
#include<stdlib.h>

void insertFirst(struct linkedList *head, int ele)
{
    //create a node
    struct node *link = (struct node *)malloc(sizeof(struct node)); /* by this you are creating a node whose address is being stored in the link pointer. */
    link->element = ele;
    //point it to old first node
    link->next = head->first;
    //point first to new first node
    head->first = link;
    head->count++;
}

//delete first item
struct node *deleteFirst(struct linkedList *head){
    struct node *del = head->first;
    head->first=head->first->next;

    head->count--;
    free(del);
    return head->first;
}

//display the list
void printList(struct linkedList *head)
{
    struct node *ptr = head->first;
    printf("\n[ ");
    //start from the beginning
    while (ptr != NULL)
    {
        printf("%d, ", ptr->element);
        ptr = ptr->next;
    }
    printf("]");
}

void fprintList(struct linkedList *head, FILE *out)
{
    struct node *ptr = head->first;
    fprintf(out, "\n[ ");
    //start from the beginning
    while (ptr != NULL)
    {
        fprintf(out, "%d, ", ptr->element);
        ptr = ptr->next;
    }
    fprintf(out, "]");
}

struct node *searchElement(struct linkedList *head, int ele){
    struct node *ptr = head->first;
    while (ptr != NULL)
    {
        if(ptr->element==ele){
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}
