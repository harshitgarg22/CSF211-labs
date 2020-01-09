/***********file:   Ops.c *********/
#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;

void copy_sorted_ele(SeqList[] , JobList);

SeqList createlist()
{
 SeqList sl;
 sl.head = nextfreeloc++;
 sl.size = 0;
 st[sl.head].next = -1;
 return (sl);
}

void printJob (Job j)
{
printf ("JOB ID = %d, Priority = %d, Arr time = %d, Arrival time = %d \n",j.id,j.pri,j.et,j.at);
}


int initialize_elements (JobList list)
{
 int i; int size;

 printf("\n Enter the Number of Jobs: ");
 scanf("%d", &size);

 for (i=0;i<size;i++)
 {
  printf ("\nEnter job ID: ");
  scanf ("%d",&list[i].id);
  printf ("Enter Priority (from 0 - 2): ");
  scanf ("%d",&list[i].pri);
  printf ("Execution Time: ");
  scanf ("%d",&list[i].et);
  printf ("Arrival Time: ");
  scanf ("%d",&list[i].at);
 }
 return size;
}

SeqList insert(Job j , SeqList sl)
{
    int i;
    for(i=sl.head; st[i].next!=-1; i=st[i].next){
        if(compare(j, st[st[i].next].ele) == LESSER){
            break;
        }
    }
    
    st[nextfreeloc].ele=j;
    st[nextfreeloc].next=st[i].next;
    st[i].next=nextfreeloc;

    nextfreeloc++;
    sl.size++;

    return sl;
 }
  
void insertelements (JobList list , int size, SeqList s[3])
{
    for(int i=0; i<3; ++i){
        createlist(s[i]);
    }

    for(int i=0; i<size; i++){
        insert(list[i], s[list[i].pri]);
    }

    copy_sorted_ele(s, list);

}

void copy_sorted_ele(SeqList s[3] , JobList ele)
{
    int k=0;
    for(int i=3; i>0; --i){
        for(int j=s[i].head; j!=-1; j=st[j].next){
            ele[k] = st[j].ele;
        }
    }

}

void printlist(SeqList sl) {
    // Implement this function
    // printJobList()
}

void printSeqList(SeqList s){
    int i;
    for(i = s.head; st[i].next != -1; i = st[i].next) {
        printJob(st[i].ele);
    }
    printJob(st[i].ele);
}

void printJobList(JobList list, int size)
{
    for(int i=0; i<size; ++i){
        printJob(list[i]);
    }

}

void copy_pro(JobList list, int size){
    for(int i=0; i<size; ++i){
        list[i] = st[i].ele;
    }
}

void insert_pro(Job jaub){
    
    int i;
    
    for(i=nextfreeloc; i<nextfreeloc; ++i){
        if(compare(jaub, st[i].ele) == LESSER){
            break;
        }
    }

    for(int j=nextfreeloc-1; j>i; --j){
        st[j+1] = st[j];
        st[j] = st[j-1];
    }

    st[i].ele = jaub;

    ++nextfreeloc;
}

void sort_but_pro(JobList list, int size){
    for(int i=3; i>=1; --i){
        for(int j=0; j<size; j++){
            if(list[j].pri==i){
                insert_pro(list[j]);
            }
        }
    }

    copy_pro(list, size);
}

void sortJobList(JobList list, int size)
{
 SeqList seq[3];
 seq[0] = createlist();
 seq[1] = createlist();
 seq[2] = createlist();
 insertelements (list, size, seq);
 printlist(seq[0]);   
 printlist(seq[1]);
 printlist(seq[2]);
 copy_sorted_ele (seq , list); 
}
