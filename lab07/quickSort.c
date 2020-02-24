#include "./Element.h"

void quickSortIterative(Element *Ls, long l, long h, long s);

void quickSort(Element *Ls, long size, long s){
    quickSortIterative(Ls, 0, size-1, s);
}

void swap(Element *a, Element *b){
    Element s = *b;
    *b=*a;
    *a=s;
}

long partition(Element *arr, long l, long h, long s){
    if (h - l + 1 <= s)
    {
        return h;
    }
    long x = arr[h].id;
    long i = (l - 1);

    for (int j = l; j <= h - 1; j++)
    {
        if (arr[j].id <= x)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}

void quickSortIterative(Element *arr, long l, long h, long s){
    long stack[h - l + 1];
    long top = -1;

    stack[++top] = l;
    stack[++top] = h;

    while (top >= 0)
    {
        h = stack[top--];
        l = stack[top--];
        int p = partition(arr, l, h, s);

        if (p - 1 > l)
        {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
        if (p + 1 < h)
        {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}
