#include "./Element.h"
#include "./merge.h"
#include<stdio.h>

void mergeSort(Element* arr, int size){
    if(size>1){
        mergeSort(arr + 0, size/2);
        mergeSort(arr + size/2 + 1, size);
        merge(arr, size/2, arr + size/2 + 1, size, arr);
    }   else{
        return;
    }
    return;
}