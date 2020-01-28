#include<stdio.h>

int i=0;

void p(){
    int pilani;
    ++i;
    printf("Address of Pilani is: %u\n", &pilani);
    p();
}

void g(){
    int goa;
    printf("Address of Goa is: %u\n", &goa);
}
void h(){
    int hyderabad;
    printf("Address of Hyderabad is: %u\n", &hyderabad);
}
void d(){
    int dubai;
    printf("Address of Dubai is: %u\n", &dubai);
}

int main(){
    p();
    g();
    h();
    d();
}