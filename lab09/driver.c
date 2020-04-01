#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include "./parse.h"
#include "./profile.h"

int main(int argc, char **argv){
    setlocale(LC_ALL, "en_US.UTF-8");
    
    if(argc == 1){
        printf("File not specified. Exiting...\n");
        return -1;
    }

    FILE * const finp = fopen(argv[1], "r");
    if(finp == NULL){
        printf("File could not be opened!");
        return -2;
    }


    long *size = malloc(sizeof(int));
    *size = 0;
    char** out = parse(finp, size);
    long len = *size;

    fclose(finp);

    // Outputs parsed output
    FILE *fout = fopen("./out.txt", "w");
    for(long i = 0; i < len; ++i){
        fprintf(fout, "%s\n", out[i]);
    }
    fclose(fout);

    profile(out, len);

    return 0;
}