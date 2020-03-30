#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <wchar.h>

char **parse(FILE *finp, long *size){
    char **out = (char**)malloc(sizeof(char*) * 1);
    
    // Offset by 3 characters due to UTF-8 BOM (Bye-order mark) encoding
    wint_t ch = fgetwc(finp);
    ch = fgetwc(finp);
    ch = fgetwc(finp);
    // Offset complete. Next read will read the first character of the file.

    long idx = 1;
    long len = 0;

    do{
        ch = fgetwc(finp);
        if(ch == ' '){
            ++idx;
            len = 0;

            char **test = NULL;
            test = (char **) realloc(out, sizeof(char *) * idx);
            out = test;
            out[idx - 1] = (char *) malloc(sizeof(char) * len);
            
            continue;
        }
        if(isalpha(ch)){
            char *test = NULL;
            ++len;
            test = (char *)realloc(out[idx-1], sizeof(char) * (len));
            out[idx - 1] = test;
            out[idx - 1][len - 1] = ch;

            continue;
        }
    }   while(ch != WEOF);

    printf("Parsing the file input...\n%ld number of valid strings found.\n", idx);
    *size = idx;
    return out;
}