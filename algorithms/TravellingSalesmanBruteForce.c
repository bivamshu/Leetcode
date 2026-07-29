#include <stdio.h>
#include <limits.h>

#define V 4

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int calculateCost(int graph[V][V], int path[]){
    int cost = 0;

    for(int i = 0; i < V - 1; i++){
        cost += graph[path[i]][path[i+1]];
    }

    cost += graph[path[V - 1]][path[0]];

    return cost;
}

void tsp(int graph[V][V], int path[], int start, int end, int *minCost){
    if(start == end){
        int cost = calculateCost(graph, path);

        if(cost < *minCost){
            *minCost = cost;
        }

        return;
    }

    for(int i = start; i <= end; i++){
        swap(&path[start], &path[i]);

        tsp(graph, path, start + 1, end, minCost);

        swap(&path[start], &path[i]);
    }
}

int main(){
    int graph[V][V] = { 
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int path[V] = {0, 1, 2, 3};
    int minCost = INT_MAX;

    tsp(graph, path, 1, V - 1, &minCost);

    printf("Minimum Cost = %d\n", minCost);

    return 0;
}