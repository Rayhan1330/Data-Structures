#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int data;
    struct node *next;
}NODE;

NODE *create_empty(int data){
    NODE *head = (NODE *)malloc(sizeof(NODE));
    head->next = head;
    head->data = data;
    return head;
}

void insert(NODE *head,int pos,int data){
    printf("%d %d\n",pos,data);
    NODE *new = (NODE *)malloc(sizeof(NODE));
    new->data = data;
    NODE *temp = head;
    for(int i=0;i<pos-1;i++)
        temp = temp->next;
    new->next = temp->next;
    temp->next = new;
}



void printlist(NODE *head){
    int i=0;
    for(NODE *temp=head;i<2;temp=temp->next){
        printf("%d-->",temp->data);
        if(temp==head)
            i++;
    }
}

NODE *insert_at_head(NODE *head,int data){
    NODE *temp;
    NODE *new = (NODE *)malloc(sizeof(NODE));
    new->data = data;
    new->next = head;
    for(temp=head->next;temp->next!=head;temp=temp->next);
    temp->next = new;
    return new;
}

NODE *del_head(struct node *head)
{
    struct node *temp,*delnode;
    delnode=head;
    head=head->next;
    for(temp=head;temp->next!=delnode;temp=temp->next);
    temp->next=head;
    free(delnode);
    return head;
}

void del(NODE *head,int data){
    int i= 0;
    for(NODE *temp=head;i<2;temp=temp->next){
        if((temp->next)->data == data){
            NODE *temp1 = temp->next;
            temp->next = temp1->next;
            free(temp1);
            break;
        }
        if(temp==head)
            i++;
    }
}

void spinning_wheel(NODE *head,int n){
    if(n==1)
        printf("Done--\n");
    else{
        NODE *temp=head;
        int i = rand()%(n - 0) + 0;int data;
        if(i==0){
            data = head->data;
            head = del_head(head);
        }
        else{
            for(int j = 0;j<i;j++)
                temp=temp->next;
            data = temp->data;
            del(head,data);
        }
        printf("%d \n",data);
        spinning_wheel(head,--n);
    }
}

void alt(NODE *head,int n){
    if(n==1)
        printf("DONE--\n");
    else{
        int i = rand();int data;
        NODE *temp=head;
        for(int j=0;j<i;j++){
            temp = temp->next;
        }
        if(temp==head){
            data = head->data;
            head = del_head(head);
        }
        else{
            data = temp->data;
            del(head,data);
        }
        printf("%d \n",data);
        alt(head,--n);
    }
}

int main(void){
    NODE *h = create_empty(11);
    for(int i=0;i<5;i++){
        insert(h,i+1,i+1);
    }
    h = insert_at_head(h,12);
    h = del_head(h);
    del(h,3);
    printlist(h);
    int n = 5;
    srand(time(0));
    printf("\n");
    //spinning_wheel(h,n);
    alt(h,n);
}

