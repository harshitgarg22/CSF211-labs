#include<stdlib.h>
#include<stdbool.h>

#include "./que.h"
#include "./multiq.h"

MultiQ createMQ(int num){
    MultiQ mq;
    Queue *list = (Queue *) malloc(sizeof(Queue)*num);

    mq.list = list;
    mq.len = num;
    return mq;
}

MultiQ addMQ(MultiQ mq, Task t){
    Priority pri = t.p;

    mq.list[pri] = addQ(mq.list[pri], t);

    return mq;
}

Task nextMQ(MultiQ mq){
    
    int i;
    
    for(i=mq.len-1; i>=0; --i){
        if(isEmptyQ(mq.list[i])==false){
            break;
        }
    }

    // mq.list[i] is the highest priority queue not empty

    return mq.list[i].head->ele;
}

MultiQ delNextMQ(MultiQ mq){
    
    int i;

    for (i = mq.len - 1; i >= 0; --i)
    {
        if (isEmptyQ(mq.list[i]) == false)
        {
            break;
        }
    }

    // mq.list[i] - highest priority queue not empty

    // delete the front of mq.list[i] queue
    mq.list[i] = delQ(mq.list[i]);

    return mq;
}

bool isEmptyMQ(MultiQ mq){
    
    for(int i=0; i<mq.len; ++i){
        if(isEmptyQ(mq.list[i])==false){
            return false;
        }
    }

    return true;
}

int sizeMQ(MultiQ mq){
    int length = 0;
    Queue traverse;
    
    for(int i=0; i<mq.len; ++i){
        traverse = mq.list[i];
        if(isEmptyQ(traverse)==false){
            length++;
        }
    }

    return length;
}

int sizeMQbyPriority(MultiQ mq, Priority p){
    int length;

    length = lengthQ(mq.list[p]);

    return length;
}

Queue getQueueFromMQ(MultiQ mq, Priority p){
    return mq.list[p];
}