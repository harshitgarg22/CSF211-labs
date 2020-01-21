#include<stdio.h>
#include<stdlib.h>
#include "./que.h"
#include "./Element.h"
#include<stdbool.h>

Queue newQ(){
    struct node *head = NULL;
    struct node *tail = NULL;

    Queue q;
    q.head = head;
    q.tail = tail;

    return q;
}

bool isEmptyQ(Queue q){
    if(q.head==NULL){
        return false;
    }
    else{
        return true;
    }
}

Queue delQ(Queue q){
    if(q.head==NULL){
        printf("ERROR Queue is empty!");
        exit(-1);
    }

    struct node *temp = q.head;
    q.head = q.head->next;
    free(temp);

    return q;
}

Element front(Queue q){
    if(q.head!=NULL){
        return q.head->ele;
    }
    else{
        printf("ERROR Queue is empty!");
        exit(-1);
    }
}

Queue addQ(Queue q, Element e){
    struct node* new_ele = (struct node *)malloc(sizeof(struct node *));

    new_ele->ele = e;
    new_ele->next = q.tail->next;
 
    q.tail->next = new_ele;
    q.tail = new_ele;

    return q;
}

int lengthQ(Queue q){
    struct node *traverse = q.head;

    int length = 0;

    while(traverse!=NULL){
        length++;
        traverse = traverse->next;
    }

    return length;
}