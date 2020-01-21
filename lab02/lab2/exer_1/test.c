#include<stdio.h>

int main(int argc, char *argv[]){
    for(int i=0; i<argc; ++i){
        if(i==0){
            printf("%s ", argv[i]+2);
            continue;
        }
        if(argv[i])
        printf("%s ", argv[i]);
    }
}