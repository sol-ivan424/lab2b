#include <stdio.h>
#include <stdlib.h>

const char *msgs[2];
const int NMsgs;

typedef struct node{
    struct node* next;
    struct node* head;
    int item;
}node;

typedef struct stack{
    node* head;
}stack;

int getInt(int* a);
int dialog(const char* msgs[], int N);
int not(stack* pt);
stack *add();
int len(stack* st);
void push(stack* st, int x);
char pop(stack* st);
void clear(stack* st) ;

