#include "./Element.h"

void insertionSort(Element *Ls, int size){
    for(int i = 1; i < size; ++i){
        Element replace = Ls[i];
        int j;
        for(j = 0; j < i; ++j){
            if(Ls[j].id>replace.id){
                break;
            }
        }
        for(int k = i; k > j; --k){
            Ls[k] = Ls[k-1];
        }
        Ls[j] = replace;
    }
}