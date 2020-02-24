#include "./Element.h"

void insertionSort(Element *Ls, long size){
    for(long i = 1; i < size; ++i){
        Element replace = Ls[i];
        long j;
        for(j = 0; j < i; ++j){
            if(Ls[j].id>replace.id){
                break;
            }
        }
        for(long k = i; k > j; --k){
            Ls[k] = Ls[k-1];
        }
        Ls[j] = replace;
    }
}