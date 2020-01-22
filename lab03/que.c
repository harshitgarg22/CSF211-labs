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
        return true;
    }
    else{
        return false;
    }
}

Queue delQ(Queue q){
    if(isEmptyQ(q)==true){
        printf("ERROR Queue is empty!\n");
        exit(-1);
    }

    struct node *temp = q.head;
    q.head = q.head->next;
    free(temp);
    if(q.head==NULL){
        q.tail = NULL;
    }

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
    node* new_ele = (struct node *)malloc(sizeof(struct node *));

    new_ele->ele = e;
    new_ele->next = NULL;
    
    if(q.tail!=NULL){
        q.tail->next = new_ele;
        q.tail = new_ele;
    }

    else{
        q.head = q.tail = new_ele;
    }

    return q;
}

int lengthQ(Queue q){
    node *traverse = q.head;

    int length = 0;

    while(traverse!=NULL){
        length++;
        traverse = traverse->next;
    }

    return length;
}