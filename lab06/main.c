#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "./Element.h"
#include "./mergeSort.h"

#define COUNT 1024  // No. of entries in input file

int main(int argc, char **argv){
    
    //input from file
    if(argc==1){
        printf("File not given!");
        return -1;
    }
    FILE *finput = fopen(argv[1], "r");
    Element *arr = (Element *)malloc(sizeof(Element)*COUNT);

    int i = 0;

    char *inp = (char*)malloc(sizeof(char)*(10));
    double gpa;

    while (!feof(finput)){
        printf("HI\n");
        fscanf(finput, "%s,%lf", inp, &gpa);
        printf("%s %lf\n", inp, gpa);
        strcpy(arr[i].name, inp);
        arr[i].cgpa = gpa;
        ++i;
    }
    //input taken

    mergeSort(arr, COUNT);

    return 0;
}