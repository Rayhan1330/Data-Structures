x#include <stdio.h>
#define V 4
#define INT_MAX 9999

void Path(int i,int j,int pred[V][V])
{
     if (pred[i][j]== 0)             // path is a single edge
       {
           printf("%d->%d->\n",i,j);
     }
    else
    {
        Path(i, pred[i][j],pred);     // print path from i to pred
        Path(pred[i][j], j,pred);     // print path from pred to j
    }
}

int main(){
    int graph[V][V] = {{0,4,9999,3},{9999,0,5,8},{9999,2,0,9999},{9999,8,1,0}};
    int pre[V][V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
            pre[i][j] = 0;
    }
    for(int k = 0; k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j< V;j++){
                if(graph[i][j]>graph[i][k]+graph[k][j]){
                    graph[i][j]=graph[i][k]+graph[k][j];
                    pre[i][j] = k;
                }
            }
        }
    }
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
            printf("%d ",graph[i][j]);
        printf("\n");
    }
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
            printf("%d ",pre[i][j]);
        printf("\n");
    }
    Path(3,1,pre);
    return 0;
}

