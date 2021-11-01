#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int charToInt(char c){
	int num = 0;
	num = c - '0';
	return num;
}

char postfix[100],stk[20],x;
int top=-1,i=0;

void push(char element) {
    top = top+1;
    stk[top] = element;
}

int pop() {
    if (top == -1) {
        return -1;
    }
    else {
        int a =  charToInt(stk[top--]);
        return a;
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
    printf("Enter Postfix expression: ");
    scanf("%[^\n]%*c", postfix);

    while(i < strlen(postfix)) {
        if (isdigit(postfix[i])) {
            push(stk[i]);
        }
        else {
            int a, b;
            b = pop();
            a = pop();
            if(postfix[i]=='+') {
                push(a+b);
            }
            else if(postfix[i]=='-') {
                push(a-b);
            }
            else if(postfix[i]=='*') {
                push(a*b);
            }
            else if(postfix[i]=='/') {
                push(a/b);
            }
            else if(postfix[i]=='^') {
                int c = pow(a,b);
                push(c);
            }    
        }
        i++;
    }
    printf("%c",pop());
}

/*

infix: A+B/C–D+(E^F)
Postfix: ABC/+D-EF^+

setting: A=6, B=5, C=4,
         D=3, E=2, F=1

infix: 6+5/4–3+(2^1)
Postfix: 654/+3-21^+

*/