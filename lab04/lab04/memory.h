#ifndef MEMORY_H_INCLUDED
#define MEMORY_H_INCLUDED
#include <stdio.h>

void *myalloc(size_t size);
void print_size();
void myfree(void *ptr);

#endif