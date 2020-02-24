#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include "./quickSort.h"
#include "./estimateCutOff.h"
#include "./insertionSort.h"
#include "./Element.h"
#include "./testRun.h"

int main(long argc, char **argv){
    FILE *finput = fopen(argv[1], "r");
    FILE *foutput = fopen(argv[2], "w");

    long COUNT;
    sscanf(argv[1], "%d", &COUNT);

    Element Ls[COUNT];
    long i = 0;

    while(!feof(finput)){
        Ls[i].name = malloc(sizeof(char)*10);
        fscanf(finput, "%s", Ls[i].name, ' ');
        Ls[i].id = 0;
        fscanf(finput, " %d\n", &Ls[i].id, '\n');
        ++i;
    }

    struct timeval t1, t2;

    gettimeofday(&t1, 0);
    // sorting procedure
    long cutoff = estimateCutOff(Ls, COUNT);

    quickSort(Ls, COUNT, cutoff);
    insertionSort(Ls, COUNT);

    // sorting procedure ends
    gettimeofday(&t2, 0);

    double tim = (t2.tv_usec - t1.tv_usec) / 1000.0;

    fprintf(foutput, "For size %ld, %lf ms time was taken.\n", COUNT, tim);

    fclose(finput);
    fclose(foutput);

    return 0;
}