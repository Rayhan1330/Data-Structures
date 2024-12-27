#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int front,rear;
    int arr[100];
}queue;

queue *create_empty(int size){
    queue *new = (queue *)malloc(sizeof(queue));
    new->front = 0;
    new->rear = 0;
    return new;
}

int isEmpty(queue *q){
    if(q->front==q->rear)
        return 1;
    else
        return 0;
}

void enqueue(queue *q,int data){
    q->arr[q->rear++] = data;
}

int dequeue(queue *q){
    return q->arr[q->front++];
}

void print_queue(queue *q){
    for(int i=q->front;i<q->rear;i++)
        printf("%d--> ",q->arr[i]);
}

int indegree(int n,int a[n][n],int vertex){
    int sum = 0;
    for(int i=0;i<n;i++){
        if(a[i][vertex]==1)
            ++sum;
    }
    return sum;
}

void toposort(int n,int a[n][n]){
    queue *q = create_empty(10);
    int i=0,count=0;
    int toposort[10];
    for(int i=0;i<n;i++){
        if(indegree(n,a,i)==0)
            enqueue(q,i);
    }
    while(!isEmpty(q)){
        int v = dequeue(q);
        ++count;
        toposort[i++] = v;
        for(int w=0;w<n;w++){
            if(a[v][w]>0){
                a[v][w] = 0;
                if(indegree(n,a,w)==0)
                    enqueue(q,w);
            }
        }
    }
    if(count!=n) printf("Graph is cyclic\n");
    else{
        for(int i=0;i<n;i++)
            printf("v%d,",toposort[i]+1);
    }
}

int main(void){
    int a[7][7] = {{0,1,1,1,0,0,0},{0,0,0,1,1,0,0},{0,0,0,0,0,1,0},{0,0,1,0,0,1,1},{0,0,0,1,0,0,1},{0,0,0,0,0,0,0},{0,0,0,0,0,1,0}};
    printf("%d\n",indegree(7,a,3));
    toposort(7,a);
}
