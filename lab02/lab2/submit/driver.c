#include<stdio.h>
#include<stdlib.h>
#include "./Stack.h"

int main(int argc, char *argv[]){

    FILE *input = fopen(argv[1], "r");


    struct linkedList *head = (struct linkedList *)malloc(sizeof(struct linkedList *));

    head->count = 0;

    while(!feof(input)){
        int temp;
        fscanf(input, "%d ", &temp);
        push(head, temp);
        printf("%d\n", head->count);
    }

    while(head->count!=0){
        pop(head);
    }

}