#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED

typedef int Priority;
typedef int TaskID;

typedef struct{
    TaskID tid;
    Priority p;
}Task;

#endif