#include <iostream>
using namespace std;

int maxSize = 10;
int queue[20];
int front = -1;
int rear = -1;

void enqueue() {
    if(rear==maxSize-1) {
        cout<<"Queue is full";
    }
    else if(front==-1 && rear==-1) {
        front = 0;
        rear = 0;
        int element;
        cout<<"Enter element: ";
        cin>>element;
        queue[rear] = element;
    }
    else {
        int element;
        cout<<"Enter element: ";
        cin>>element;
        rear++;
        queue[rear] = element;
    }
}

void dequeue() {
    if(front==-1 && rear==-1) {
        cout<<"Queue is empty";
    }
    else if(front==rear) {
        front = -1;
        rear = -1;
        maxSize = 10;
    }
    else {
        front++;
        maxSize++;
    }
}

void display() {
    if(front==-1 && rear==-1) {
        cout<<"Queue is empty";
    }
    else {
        cout<<"Queue: ";
        for(int i=front;i<rear+1;i++) {
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    
    while(1) {
        int option;
        cout<<"\n\t1: enqueue\n\t2: dequeue\n\t3: display\nEnter your choice: ";
        cin>>option;
        if(option==1) {
            enqueue();
        }
        else if(option==2) {
            dequeue();
        }
        else if(option==3) {
            display();
        }
        else {
            break;
        }
    }
}

queue[rear].left = &queue[front];
queue[rear].right = &queue[front+1];
queue[front].parent = &queue[rear];
queue[front+1].parent = &queue[rear];