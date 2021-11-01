#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

int length(struct node *head) {
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp = head;
    int i = 0;
    while(temp!=NULL) {
        temp=temp->next;
        i++;
    }
    return i;
}

struct node *insert(struct node *head, int pos, int a) {        //pos starts from 1
    struct node *temp, *m, *n;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->value = a;
    m=NULL;
    n=(struct node *)malloc(sizeof(struct node));
    n=head;
    if (n==NULL) {
        n=temp;
        n->next =NULL;
    }
    else if(pos<=1){
        temp->next = n;
        n = temp;

    }
    else if(length(head)<=pos){
        while(n->next!=NULL) {
            n=n->next;
        }
        n->next=temp;
        temp->next=NULL;
    }
    else {
        for(int i=2;i<pos-1;i++) {
            m=n;
            if(n->next==NULL) {
                break;
            }
            else {
                n=n->next;
            }
        }
        struct node *ptr;
        ptr=m->next;
        m->next=temp;
        temp->next=ptr;
    }
    return n;
}

struct node *delete(struct node *head, int pos) {       //pos starts from 1
    struct node *r;
    r=head;
    if (pos==1) {
        if(r->next==NULL) {
            head=NULL;
        }
        else {
            head=r->next;
            free(r);
        }
    }
    else if(pos<1||pos>length(head)) {
        printf("\nposition entered (%d) is invalid\n",pos);
    }
    else {
        for(int i=0;i<pos-2;i++) {
            r=r->next;
        }
        if ((r->next)->next==NULL) {
            free(r->next);
            r->next=NULL;
        }
        else {
            struct node *ptr=(r->next);
            r->next=(r->next)->next;
            free(ptr);
        }
    }
    return head;
}

void display(struct node *head) {
    printf("linked list: ");
    struct node *r;
    r=head;
    while(r!=NULL) {
        printf("%d ",r->value);
        r=r->next;
    }
}

int main(){

    struct node *l1;
    l1 = NULL;
    int choice;
    while(1){
        printf("\n\t1: Insert\n\t2: Delete\n\t3: Display\n\t4: Exit\nEnter your choice: ");
        scanf("%d",&choice);
        if(choice==1){
            printf("Enter value of node to be inserted: ");
            int val;
            scanf("%d",&val);
            printf("Enter position of node to be inserted: ");
            int pos;
            scanf("%d",&pos);
            l1 = insert(l1,pos,val);
        }
        else if(choice==2) {   
            printf("Enter position of the node to be deleted: ");
            int pos;
            scanf("%d",&pos);
            l1 = delete(l1,pos);
        }
        else if(choice==3) {
            display(l1);
        }
        else {
            printf("Exiting....");
            break;
        }
    }
    return 0; 
}