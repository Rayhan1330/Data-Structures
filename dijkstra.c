#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#define V 9
int minimum_dist(int dist[], bool path[])
{
   int min = INT_MAX, min_index;
   for (int v = 0; v < V; v++)
   {
      if (path[v] == false && dist[v] <= min)
      {
         min = dist[v];
         min_index = v;
      }
}
   return min_index;
}
void Display(int dist[], int n)
{
    printf("Shortest Vertex Distance from the Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}
void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool path[V];
    for (int i = 0; i < V; i++){
        dist[i] = INT_MAX;
        path[i] = false;
        dist[src] = 0;
    }
    for (int count = 0; count < V - 1; count++){
        int u = minimum_dist(dist, path);
        path[u] = true;
        for (int v = 0; v < V; v++){
            if (!path[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    Display(dist, V);
}

int main() {
   int graph[V][V] = { { 0, 8, 0, 0, 0, 5, 0, 2, 0 },
      { 7, 0, 5, 0, 0, 0, 0, 11, 0 },
      { 0, 8, 0, 7, 0, 6, 0, 0, 2 },
      { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
      { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
      { 0, 0, 5, 14, 10, 0, 2, 0, 0 },
      { 0, 0, 4, 0, 0, 2, 0, 1, 6 },
      { 5, 15, 0, 0, 0, 0, 3, 0, 9 },
      { 0, 0, 1, 0, 0, 0, 6, 8, 0 }};
    int x;
    printf("Enter source(0-8): ");
    scanf("%d",&x);
    dijkstra(graph, x);
    return 0;
}
