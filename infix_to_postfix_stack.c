#include <stdio.h>
#include <ctype.h>
#include <string.h>
char infix[100],stk[20],x;
int top=-1,i=0;

void push(char element) {
    top = top+1;
    stk[top] = element;
}

char pop() {
    if (top == -1) {
        return -1;
    }
    else {
        return stk[top--];
    }
}

int priority(char s) {
    if(s == '$' || s == '^') {
        return 3;
    }
    else if(s == '*' || s == '/') {
        return 2;
    }
    else if(s == '+' || s == '-') {
        return 1;
    }
    else {
        return 0;
    }
}

void main() {
    printf("Enter Infix expression: ");
    scanf("%[^\n]%*c", infix);
    while(i < strlen(infix)) {
        if (isalnum(infix[i])) {
            printf("%c ", infix[i]);
        }
        else if (infix[i]=='(') {
            push(infix[i]);
        }
        else if (infix[i]==')') {
            while( (x=pop()) != '(') {
                printf("%c ",x);
            }
        }
        else {
            while(priority(stk[top]) >= priority(infix[i])) {
                printf("%c ",pop());
            }
            push(infix[i]);
        }
        i++;
    }
    while(top != -1) {
        printf("%c",pop());
    }
}