#include<stdio.h>
#include<stdlib.h>
void enqueue(int q[],int n,int *front,int *rear,int data)
{
    if(*rear==n)
    {
        printf("queue full");
    }
    else
    {
        q[*rear]=data;
        (*rear)++;
    }
}
int dequeue(int q[],int *front,int *rear)
{
    int data;
    if(*front==*rear)
    {
        printf("queue empty");
        return -1;
    }
    else
    {
        data=q[*front];
        (*front)++;
        return data;
    }
}
int in_queue(int q[],int *front,int *rear,int data)
{
    int i;
    for(i=*front;i<*rear;i++)
    {
        if(q[i]==data)
        {
            return(1);
        }
    }
    return(0);
}
void BFS(int size,int a[][size],int v[],int q[],int *front,int *rear,int n)
{
    int j=0;
    int i;
    if(*front!=*rear)
    {
        i=dequeue(q,front,rear);
        v[i]=1;
        printf("\n%d-",i);
        for(j=0;j<size;j++)
        {
            if(a[i][j]==1 && v[j]==0 && in_queue(q,front,rear,j)==0)
            {
            printf("<%d,%d>",i,j);
            enqueue(q,n,front,rear,j);
            }
        }
        BFS(size,a,v,q,front,rear,n);
        printf("\n");
    }
        
}
int main()
{
    int q[50];
    int n=50;
    int *front,*rear;
    int size=6;
    int v[6]={0,0,0,0,0,0};
  /*  int a[6][6]={0,1,1,0,0,0,
                 1,0,0,1,1,0,
                 1,0,0,0,0,1,
                 0,1,0,0,1,0,
                 0,0,0,1,0,1,
                 0,0,0,0,1,0};*/
    int a[6][6]={0,0,1,1,0,0,
                 0,0,0,0,0,1,
                 1,0,0,1,1,1,
                 1,0,1,1,1,0,
                 0,0,1,1,0,1,
                 0,1,1,0,1,0};
    front=(int *)malloc(sizeof(int));
    rear=(int *)malloc(sizeof(int));
    *front=0;
    *rear=0;
   /* enqueue(q,n,front,rear,100);
     printf("\n front %d rear %d data %d",*front,*rear,q[(*rear)-1]);
    enqueue(q,n,front,rear,200);
     printf("\n front %d rear %d data %d",*front,*rear,q[(*rear)-1]);
      enqueue(q,n,front,rear,300);
     printf("\n front %d rear %d data %d",*front,*rear,q[(*rear)-1]);
      enqueue(q,n,front,rear,400);
     printf("\n front %d rear %d data %d",*front,*rear,q[(*rear)-1]);
      enqueue(q,n,front,rear,500);
    printf("\n front %d rear %d data %d",*front,*rear,q[(*rear)-1]);
       enqueue(q,n,front,rear,600);
    printf("\n front %d rear %d data %d",*front,*rear,dequeue(q,front,rear));
     printf("\n front %d rear %d data %d",*front,*rear,dequeue(q,front,rear));
     printf("\n front %d rear %d data %d",*front,*rear,dequeue(q,front,rear));
     printf("\n front %d rear %d data %d",*front,*rear,dequeue(q,front,rear));
     printf("\n front %d rear %d data %d",*front,*rear,dequeue(q,front,rear));
     printf("\n front %d rear %d data %d",*front,*rear,dequeue(q,front,rear));*/
    enqueue(q,n,front,rear,0);
    BFS(size,a,v,q,front,rear,n);
}
