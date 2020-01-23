#include<stdio.h>
#include<ctype.h>
#include <sys/time.h>   // for gettimeofday()

#include "./multiq.h"


// Number of Task inputs
#define NUM 10

MultiQ loadData(FILE *f){
    
    // Initialize a new MultiQ
    MultiQ mq = createMQ(NUM);
    
    while(!feof(f)){
        
        // Take input from file as format TASKID,Priority'\n'
        TaskID tid;
        Priority p;
        fscanf(f, "%d,%d", &tid, &p);

        // Make a new Task object of the newly obtained values
        Task t;
        t.tid = tid;
        t.p = p;

        // Call the addMQ fn to add Task to queue accordingly
        mq = addMQ(mq, t);
    }

    return mq;
}

MultiQ testDel(MultiQ mq, int num){
    
    // Calls delNextMQ 'num' times
    for(int i=0; i<num; ++i){
        mq = delNextMQ(mq);
    }

    return mq;
}

int main(int argc, char *argv[]){

    // Name of input file is passed as first argument
    FILE *input = fopen(argv[1], "r");

    struct timeval t1, t2;
    double elapsedTime;
    // start timer
    gettimeofday(&t1, NULL);

    MultiQ mq = loadData(input);

    gettimeofday(&t2, NULL);

    // compute and print the elapsed time in millisec
    elapsedTime = (t2.tv_usec - t1.tv_usec) / 1000.0;
    printf("Total time for loading Data is %fms.\n", elapsedTime);

    elapsedTime = 0;
    // start timer
    gettimeofday(&t1, NULL);


    mq = testDel(mq, 5);
    
    gettimeofday(&t2, NULL);

    // compute and print the elapsed time in millisec
    elapsedTime = (t2.tv_usec - t1.tv_usec) / 1000.0;
    printf("Total time for Deleting is %fms.\n", elapsedTime);
}