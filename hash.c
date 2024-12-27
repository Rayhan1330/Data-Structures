#include <stdio.h>
#include <stdlib.h>


//SEPERATE CHAINING


typedef struct node{
    int data;
    struct node *next;
}NODE;


void insert_at_end(NODE **head,int data){
    NODE **temp;
    for(temp = head;(*temp)!=NULL;temp = &((*temp)->next));
    NODE *temp1;
    NODE *new = (NODE *)malloc(sizeof(NODE));
    new->next = NULL;
    new->data= data;
    *temp = new;
}

void print(NODE *head){
    for(NODE *temp =head;temp!=NULL;temp=temp->next)
        printf("%d--> ",temp->data);
    printf("\n");
}

void hash(NODE *arr[],int data){
    int pos = data%10;
    insert_at_end(&arr[pos],data);
}

void print_hash(NODE *arr[]){
    for(int i=0;i<10;i++){
        print(arr[i]);
    }
}

void find(NODE *arr[],int data){
    int pos = data%10;
    NODE *temp = arr[pos];
    int n=0;
    for(NODE *temp1 = temp;temp1!=NULL;temp1=temp1->next){
        if(temp1->data == data){
            n=1;
            printf("Element found\n");
            break;
        }
    }
    if(n!=1)
        printf("Element not found\n");
}

int main(void){
    NODE *arr[10];
    int n,data;
    for(int i=0;i<10;i++){
        arr[i] = NULL;
    }
    while(1){
        printf("Do you want to enter an element?(1/0): ");
        scanf("%d",&n);
        if(n==1){
            printf("Enter the data element: ");
            scanf("%d",&data);
            hash(arr,data);
        }
        else
            break;
    }
    NODE *h=NULL;
    //insert_at_end(&h,1);insert_at_end(&h,2);insert_at_end(&h,3);
    //print(h);
    print_hash(arr);
    find(arr,16);
}
