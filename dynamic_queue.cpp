#include <stdio.h>
#include <stdlib.h>

struct queue{
    int *a;
    int front;
    int rear;
    int max;
};

void enqueue(struct queue *temp, int d){
    if(temp->rear==(temp->max)-1){
        printf("Queue is full\n");
        return;
    }
    else if(temp->front==-1&&temp->rear==-1){
        temp->front = 0;
        temp->rear = 0;
        temp->a[temp->rear]=d;
    }
    else{
        temp->rear++;
        temp->a[temp->rear]=d;
    }
}

void dequeue(struct queue *temp){
    if(temp->front==-1 && temp->rear==-1){
        printf("Queue is empty\n");
        return;
    }
    else if(temp->front==temp->rear){
        temp->front = -1;
        temp->rear = -1;
    }
    else{
        printf("element removed: %d\n",temp->a[temp->front]);
        temp->front++;
    } 
}

void display(struct queue *temp){
    for(int i=temp->front;i<=temp->rear;i++){
        printf("%d ",temp->a[i]);
    }
    printf("\n");
}

int main(){

    struct queue q1;
    q1.front = -1;
    q1.rear = -1;
    q1.max = 20;

    q1.a = (int *)malloc(q1.max * sizeof(int));

    int c = 0;
    while(c!=4){
        printf("\n\t1: enqueue\n\t2: dequeue\n\t3: print\n\t4: exit\nEnter your choice: ");
        scanf("%d",&c);
        if(c==1){
            int d;
            printf("Enter element: ");
            scanf("%d",&d);
            enqueue(&q1,d);
        }
        if(c==2){
            dequeue(&q1);
        }
        if(c==3){
            display(&q1);
        }
    }
    return 0;
}