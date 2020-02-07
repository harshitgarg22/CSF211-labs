#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

int main()
{
	int *arr = (int *)myalloc(sizeof(int) * 5);
	arr[0] = 1;
	print_size();
	myfree(arr);
	print_size();
}
