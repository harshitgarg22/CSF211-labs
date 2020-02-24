#include<sys/time.h>
#include<stdlib.h>
#include "./Element.h"
#include "./insertionSort.h"
#include "./quickSort.h"

double *testRun(Element *Ls, long size){
    double *time = (double *)malloc(sizeof(double)*2);

    Element arr1[size], arr2[size];

    for(int i=0; i<size; ++i){
        arr1[i] = Ls[i];
        arr2[i] = Ls[i];
    }

    struct timeval t1, t2;

    gettimeofday(&t1, 0);
    insertionSort(arr1, size);
    gettimeofday(&t2, 0);

    time[0] = (t2.tv_usec - t1.tv_usec) / 1000.0;
    
    gettimeofday(&t1, 0);
    quickSort(arr2, size, 0);
    gettimeofday(&t2, 0);

    time[1] = (t2.tv_usec - t1.tv_usec) / 1000.0;

    return time;
}