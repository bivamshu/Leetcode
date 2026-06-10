#include<stdio.h>
#include<stdlib.h>

#define NODES 4 // Total number of nodes in our graph 

void DFS(int graph[NODES][NODES], int visited[NODES], int currentNode){
    //1. Mark the current node as visited in our graph and print it
    visited[currentNode] = 1;
    printf("%d", currentNode);

    //2. Look at all potential neighbours of the current node
    for(int neighbour = 0; neighbour < NODES; neighbour++){
        if(graph[currentNode][neighbour] == 1 && !visited[neighbour]){
            DFS(graph, visited, neighbour);
        }
    }
}

int main(){
    int graph[NODES][NODES] = {
        {0, 1, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    int visited[NODES] = {0}; // Initialize all to 0 (false)

    printf("DFS Traversal starting from Node 0: ");

    DFS(graph, visited, 0);

    printf("\n");


}