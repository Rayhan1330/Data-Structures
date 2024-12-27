 #include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}NODE;

NODE *create_empty(){
    NODE *head = (NODE *)malloc(sizeof(NODE));
    return head;
}

void insert_at_tail(NODE **head,int data){
    NODE *new = (NODE *)malloc(sizeof(NODE));
    new->data = data;
    new->next = NULL;
    if(*head==NULL){
        *head = new;
    }
        
    else{
        
        NODE *temp = *head;
        while(temp->next != NULL)
            temp = temp->next;
        NODE **temp1 = &temp;
        (*temp1)->next = new;
    }
}

NODE *insert_at_head(NODE *head,int data){
    NODE *new = (NODE *)malloc(sizeof(NODE));
    new->data = data;
    new->next = head;
    return new;
}

void delete_tail(NODE *head){
    NODE *temp = head;
    while((temp->next)->next!=NULL)
        temp=temp->next;
    NODE *temp1 = temp->next;
    temp->next = NULL;
    free(temp1);
}

NODE *delete_head(NODE *head){
    NODE *temp = head->next;
    free(head);
    return temp;
}

void printlist(NODE *head){
    for(NODE *temp=head; temp!=NULL ;temp=temp->next)
        printf("%d--> ",temp->data);
}

int main(void){
    NODE *h = NULL;
    insert_at_tail(&h,1);
    insert_at_tail(&h,2);
    insert_at_tail(&h,3);
    insert_at_tail(&h,4);
    h = insert_at_head(h,0);
    h = insert_at_head(h,-1);
    delete_tail(h);
    h = delete_head(h);
    printlist(h);
}
