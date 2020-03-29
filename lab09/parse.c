#include <stdio.h>
#include <ctype.h>

char **parse(FILE *finp){
    char **out = NULL;
    char ch = 0;

    long idx = 1;
    long len = 0;
    do{
        ch = fgetc(finp);
        if(ch == '.'){
            ++idx;
            len = 0;

            char **test = NULL;
            test = (char **) realloc(out, sizeof(char *) * idx);
            out = test;
            out[idx - 1] = (char *) malloc(sizeof(char) * len);
            
            continue;
        }
        if(isalph(ch)){
            char *test = NULL;
            ++len;
            test = (char *)realloc(out[idx-1], sizeof(char) * (len));
            out[idx - 1] = test;
            out[idx - 1][len - 1] = ch;

            continue;
        }
    }   while(ch != EOF);

    printf("Parsing the file input...\n%ld number of valid strings found.", idx);
    return out;
}