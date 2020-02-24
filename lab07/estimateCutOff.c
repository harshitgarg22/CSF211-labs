#include "./Element.h"
#include "./testRun.h"

double absolute(double a, double b)
{
    return a - b > 0 ? a - b : b - a;
}

long estimateCutOff(Element *Ls, long size){
    double *tt;

    long min = 0, max = size;
    long mid = (min + max)/2;

    tt = testRun(Ls, min);

    if(tt[0]>=tt[1]){
        return min;
    }

    tt = testRun(Ls, max);

    if(tt[0]<=tt[1]){
        return max;
    }

    while (absolute(tt[0],tt[1]) > 0.4){
        mid = (min + max)/2;
        tt = testRun(Ls, mid);
        if(tt[0]<tt[1]){
            min = mid;
        }   else{
            max = mid;
        }
    }

    return mid;
}