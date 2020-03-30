#include "./hashfn.h"
#include <stdlib.h>

long collision(char **list, long len, long baseNumber, long tableSize){
    long num = 0;
    long hash;

    int *hashes = (int *) calloc(tableSize, sizeof(int));

    for(long i = 0; i < len; ++i){
        hash = hashfn(list[i], baseNumber, tableSize);
        hashes[hash]++;

        if(hashes[hash] > 1){
            num++;
        }
    }

    return num;
}