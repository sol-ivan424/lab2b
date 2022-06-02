#include "list.h"

int not(stack* st){
    char c;
    printf("Input reverse notation: ");
    do {
        scanf("%c", &c);
        if (c != '+' && c != '-' && c != '*' && c != '/') {
            int s = c - '0';
            push(st, s);
        }
        if (c == '+') {
            if (len(st) < 2) {
                printf("Invalid input\n");
                clear(st);
                return 1;
            }
            int n = pop(st);
            int m = pop(st);

            int s = (n + m) ;
            push(st, s);
        }
        if (c == '-') {
            if (len(st) < 2) {
                printf("Invalid input\n");
                clear(st);
                return 1;
            }
            int n = pop(st);
            int m = pop(st);

            int s = (m - n);
            push(st, s);
        }
        if (c == '*') {
            if (len(st) < 2) {
                printf("Invalid input\n");
                clear(st);
                return 1;
            }
            int n = pop(st);
            int m = pop(st);

            int s = (n * m) ;
            push(st, s);
        }
        if (c == '/') {
            if (len(st) < 2) {
                printf("Invalid input\n");
                clear(st);
                return 1;
            }
            int n = pop(st);
            int m = pop(st);

            int s = (m / n) ;
            push(st, s);
        }
    } while (c != '=');
    pop(st);
    printf("Answer: %d\n", pop(st));
    return 1;
}

int getInt(int* x){
    int y;

    do{
        y = scanf("%d", x);
        if (y < 0){
            return 0;
        }
        if (y == 0){
            printf("%s\n", "Error! Repeat input");
            scanf("%*c");
        }
    } while (y == 0);
    return 1;
}

stack* add(){
    stack* st = (stack*)malloc(sizeof(stack));
    st->head = NULL;
    return st;
}

int len(stack* st) {
    int len=0;
    node* q = st->head;
    while (q) {
        q = q->next;
        ++len;
    }
    return len;
}

void push(stack* st, int x){
    node* new = (node*)malloc(sizeof(node));
    new->item = x;
    new->next = st->head;
    st->head = new;
}

char pop(stack* st){
    int d = (st->head)->item;
    node* q = st->head;
    st->head = (st->head)->next;
    free(q);
    return d;
}

void clear(stack *st){
    while (st->head){
        node *ptr = st->head;
        st->head = (st->head)->next;
        free(ptr);
    }
    free(st->head);
    free(st);
}

int dialog(const char *msgs[], int N){
    char* errmsg = "";
    int ch;
    int i, j;

    for(i = 0; i < N; ++i)
    puts(msgs[i]);

    do{
        puts(errmsg);
        errmsg = "You are wrong. Repeate, please!";
        printf("Make your choice:--> ");
        j = getInt(&ch);
        if(j == 0)
        ch = 0;
    } while(ch < 0 || ch >= N);

    return ch;
}
