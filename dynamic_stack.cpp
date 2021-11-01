// Implementing basic stack functions
#include <stdio.h>
#include <stdlib.h>

struct stack {
    int *array;
    int top;
    int maxSize;
};

void push(struct stack *s, int element) {
    if(s->top == s->maxSize-1) {
        printf("Stack Overflow\n");
    }
    else {
        s->top++;
        s->array[s->top] = element;
    }
    printf("\n");
}

int pop(struct stack *s) {
    if(s->top == -1) {
        printf("Stack Underflow\n");
    }
    else {
        return s->array[s->top];
        s->top--;
    }
    printf("\n");
}

void display(struct stack *s) {
    printf("stack:  ");
    for(int i=0; i<=s->top; i++) {
        printf("%d ",s->array[i]);
    }
    printf("\n");
}

int main() {
    struct stack s;
    s.maxSize = 10;
    s.top = -1;
    s.array = (int *)malloc(s.maxSize * sizeof(int));
    while(1) {
        int c;
        printf("\t1: push\n\t2: pop\n\t3: display\n\t4: exit\nEnter your choice: ");
        scanf("%d",&c);
        if(c==1) {
            int el;
            printf("Enter element to be pushed: ");
            scanf("%d",&el);
            push(&s,el);
        }
        else if(c==2) {
            printf("%d\n",pop(&s));
        }
        else if(c==3){
            display(&s);
        }
        else if(c==4){
            display(&s);
            break;
        }
    }
}