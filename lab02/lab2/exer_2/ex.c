#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    FILE *reader = fopen(argv[1], "r");
    FILE *writer = fopen(argv[2], "w");

    char temp;
        
    if(reader==NULL|writer==NULL){
        printf("Error! Could not open file");
        exit(-1);
    }

    for(temp=fgetc(reader); temp!=EOF; temp=fgetc(reader)){
        fputc(temp, writer);
    }

    fclose(reader);
    fclose(writer);
}
