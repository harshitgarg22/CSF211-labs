#include<stdio.h>
#include "./collision.h"

void profile(char **list, long len){
    long baseNumber[][6] = {
        {5003, 5009, 5011, 5000011, 5000077, 5000081}, 
        {50021, 50023, 50033, 50000017, 50000021, 50000047}, 
        {500009, 500029, 500041, 500000003, 500000009, 500000041}
        }, 
        tableSize[] = {5000, 50000, 500000};
    long val[6][3];

    int best_i = 0, best_j = 0;

    printf("Executing profiler...\n");

    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < 3; ++j){
            val[i][j] = collision(list, len, baseNumber[j][i], tableSize[j]);
            printf("Collision for tableSize %d\tand baseNumber %d\t: %d ", baseNumber[j][i], tableSize[j], val[i][j]);
            if(val[best_i][best_j] > val[i][j]){
                best_i = i;
                best_j = j;
            }
            printf("\n");
        }
    } 

    printf("Best indices in baseNumber: (%d,%d) (i.e. baseNumber: %d)\n", best_j, best_i, baseNumber[best_j][best_i]);
    printf("Best indices in tableSize: %d (i.e. tableSize: %d)\n", best_j, tableSize[best_j]);
}