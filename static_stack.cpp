#include <iostream>
using namespace std;

int maxSize = 10;
int arr[20];
int top = -1;

void push() {
    if(top == maxSize - 1) {
        cout<<"Stack Overflow";
    }
    else {
        int element;
        cout<<"Enter element: ";
        cin>>element;
        top++;
        arr[top] = element;
    }
}

void pop() {
    if(top == -1) {
        cout<<"Stack Underflow";
    }
    else {
        top--;
    }
}

void display() {
    if(top == -1) {
        cout<<"Stack is empty";
    }
    else {
        cout<<"Stack: ";
        for(int i=0;i<top+1;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    
    while(1) {
        int option;
        cout<<"\n\t1: push\n\t2: pop\n\t3: display\nEnter your choice: ";
        cin>>option;
        if(option==1) {
            push();
        }
        else if(option==2) {
            pop();
        }
        else if(option==3) {
            display();
        }
        else {
            break;
        }
    }
}
