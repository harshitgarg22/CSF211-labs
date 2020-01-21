#include<stdio.h>
#include<ctype.h>

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

    MultiQ mq = loadData(input);

    mq = testDel(mq, 5);
}