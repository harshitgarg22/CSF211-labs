#include "./Element.h"

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]){
    int i = 0, j = 0, k = 0;

    for(i = 0; j!=sz1 || k!=sz2; ++i){
        if(Ls1[j].cgpa<=Ls2[k].cpga){
            Ls[i] = Ls1[j++];
        }   else{
            Ls[i] = Ls2[k++];
        }
    }

    if(j<sz1){
        while(j!=sz1){
            Ls[i++] = Ls1[j++];
        }
    }   else if(k<sz2){
        while(k!=sz2){
            Ls[i++] = Ls2[k++];
        }
    }
}