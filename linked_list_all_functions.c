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

struct node *insertStart(struct node *head, int a) {
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->value = a;
    if (head==NULL) {
        head = (struct node*)malloc(sizeof(struct node));
        head=temp;
        head->next =NULL;
    }
    else {
        temp->next = head;
        head = temp;
    }
    return temp;
}

struct node *insertEnd(struct node *head, int a) {
    struct node *temp, *r;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->value = a;
    r=(struct node*)malloc(sizeof(struct node));
    r=head;
    if(r==NULL) {
        head = (struct node*)malloc(sizeof(struct node));
        head=temp;
        head->next=NULL;
    }
    else {
        while(r->next!=NULL) {
            r=r->next;
        }
        r->next=temp;
        temp->next=NULL;
    }
    return head;
}

struct node *insertPosition(struct node *head, int pos, int a) {        //pos starts from 1
    struct node *temp, *m, *n;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->value = a;
    m=NULL;
    n=head;
    if(pos<=1){
        head = insertStart(head,a);
    }
    else if(length(head)<=pos){
        head = insertEnd(head,a);
    }
    else{
        for(int i=0;i<pos-1;i++) {
            m=n;  //used to get the node before n after step 67
            if(n->next==NULL) {
                break;
            }
            else {
                n=n->next;
            }
        }
        if(m==NULL) {
            head=temp;
            head->next=NULL;
        }
        else {
            struct node *ptr;
            ptr=m->next;
            m->next=temp;
            temp->next=ptr;
        }
    }
    return head;
}

struct node *deleteValue(struct node *head, int val) {
    int flag = 0;
    struct node *r;
    r=head;
    if (r->next==NULL) {
        r=NULL;
    }
    else if(r->value==val) {
        head=r->next;
        free(r);
    }
    else {
        while((r->next)->next!=NULL) {
            if((r->next)->value!=val) {
                r=r->next;
            }
            else {
                flag = 1;
                break;
            }
        }
        if(flag==1){
            struct node *ptr=r->next;
            r->next=(r->next)->next;
            free(ptr);
        }
        else{
            printf("\nvalue entered (%d) not present in list\n",val);
        }
    }
    return head;
}

struct node *deletePosition(struct node *head, int pos) {       //pos starts from 1
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

struct node *deleteStart(struct node *head) {
    struct node *r;
    r=head;
    if(r==NULL){
        printf("\nEMPTY LIST\n");
    }
    else if(r->next==NULL) {
        head=NULL;
    }
    else {
        head=r->next;
        free(r);
    }
    return head;
}

struct node *deleteEnd(struct node *head) {
    struct node *r;
    r=head;
    if(r==NULL){
        printf("\nEMPTY LIST\n");
    }
    else if(r->next==NULL) {
        head=NULL;
    }
    else{
        while((r->next)->next!=NULL){
            r=r->next;
        }
        free(r->next);
        r->next=NULL;
    }
    return head;
}

void elementSearch(struct node *head, int val){         //pos starts from 0
    struct node *r;
    r=head;
    int c=0, flag=0;
    if(r==NULL) {
        printf("EMPTY LIST");
        return ;
    }
    else if(r->value==val){
        printf("\nThe value %d is at 0 position\n",val);
    }
    else {
        while((r->next)!=NULL) {
            if((r->next)->value!=val) {
                c++;
                r=r->next;
            }
            else {
                flag=1;
                break;
            }
        }
        if(flag==1) {
            printf("\nThe value %d is at %d position\n",val,c+1);
        }
        else {
            printf("\nelement entered (%d) is not present in the list\n",val);
        }
    }
}

struct node *reverse(struct node *head){        //DOES NOT WORK
    struct node *prev,*curr,*next;
    prev=NULL;
    curr=head;
    next=curr->next;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head = prev;
    return head;
}  

void display(struct node *head) {
    printf("\n");
    struct node *r;
    r=head;
    while(r!=NULL) {
        printf("%d ",r->value);
        r=r->next;
    }
}

int main(){
    struct node *l1;
    int choice;
    while(choice!=10) {
        printf("\n1.Insert(Beginning)\n2.Insert(End)\n");
        printf("3.Insert(Position)\n4.Delete(Beginning)\n");
        printf("5.Delete(End)\n6.Delete(Position)\n");
        printf("7.Search an Element\n8.Reverse the List\n");
        printf("9.Display\n10.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice) {
            case 1: {
                printf("Enter value of node to be inserted: ");
                int val;
                scanf("%d",&val);
                l1 = insertStart(l1,val);
                break;
            }
            case 2: {
                printf("Enter value of node to be inserted: ");
                int val;
                scanf("%d",&val);
                l1 = insertEnd(l1,val);
                break;
            }
            case 3: {
                printf("Enter value of node to be inserted: ");
                int val;
                scanf("%d",&val);
                printf("Enter position of node to be inserted: ");
                int pos;
                scanf("%d",&pos);
                l1 = insertPosition(l1,pos,val);
                break;
            }
            case 4: {
                l1 = deleteStart(l1);
                break;
            }
            case 5: {
                l1 = deleteEnd(l1);
                break;
            }
            case 6: {   
                printf("Enter position of the node to be deleted: ");
                int pos;
                scanf("%d",&pos);
                l1 = deletePosition(l1,pos);
                break;
            }
            case 7: {
                printf("Enter value to be found: ");
                int val;
                scanf("%d",&val);
                elementSearch(l1,val);
                break;
            }
            case 8: {
                l1 = reverse(l1); //DOES NOT WORK
                break;
            }
            case 9: {
                display(l1);
                break;
            }
            case 10: {
                printf("Exiting....");
                break;
            }
            default: {
                printf("Invalid Input");
            }
        };
    }
    return 0;
}

