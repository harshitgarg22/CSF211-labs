#ifndef MULTIQ_H_INCLUDED
#define MULTIQ_H_INCLUDED

#include "./Task.h"
#include "./que.h"

typedef struct{
    Queue *list;
    int len;
}MultiQ;

typedef int Priority;

MultiQ createMQ(int num);
MultiQ addMQ(MultiQ mq, Task t);
Task nextMQ(MultiQ mq);
MultiQ delNextMQ(MultiQ mq);
bool isEmptyMQ(MultiQ mq);
int sizeMQ(MultiQ mq);
int sizeMQbyPriority(MultiQ mq, Priority p);
Queue getQueueFromMQ(MultiQ, Priority p);

#endif