#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
 
#define MAX_VERTICES 100 
 
typedef struct { 
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES]; 
    int numVertices; 
} Graph; 
 
// Function to create a graph with a specified number of vertices 
Graph* createGraph(int vertices) { 
    Graph* graph = (Graph*)malloc(sizeof(Graph)); 
    graph->numVertices = vertices; 
 
    for (int i = 0; i < vertices; i++) 
        for (int j = 0; j < vertices; j++) 
            graph->adjacencyMatrix[i][j] = 0; 
 

    return graph; 
} 
 
// Function to add an edge to the directed graph 
void addEdge(Graph* graph, int src, int dest) { 
    graph->adjacencyMatrix[src][dest] = 1; 
} 
 
// BFS algorithm 
void BFS(Graph* graph, int startVertex) { 
    bool visited[MAX_VERTICES] = {false}; 
    int queue[MAX_VERTICES]; 
    int front = 0, rear = 0; 
 
    visited[startVertex] = true; 
    queue[rear++] = startVertex; 
 
    printf("BFS starting from vertex %d: ", startVertex); 
 
    while (front < rear) { 
        int currentVertex = queue[front++]; 
        printf("%d ", currentVertex); 
 
        for (int i = 0; i < graph->numVertices; i++) { 
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) { 
                visited[i] = true; 
                queue[rear++] = i; 
            } 
        } 
    } 
    printf("\n"); 
} 
 
// DFS algorithm 
void DFSUtil(Graph* graph, int vertex, bool visited[]) { 
    visited[vertex] = true; 
    printf("%d ", vertex); 
 
    for (int i = 0; i < graph->numVertices; i++) { 
        if (graph->adjacencyMatrix[vertex][i] == 1 && !visited[i]) { 
            DFSUtil(graph, i, visited); 
        } 
    } 
} 
 
void DFS(Graph* graph, int startVertex) { 

    bool visited[MAX_VERTICES] = {false}; 
    printf("DFS starting from vertex %d: ", startVertex); 
    DFSUtil(graph, startVertex, visited); 
    printf("\n"); 
} 
 
// Main function to demonstrate BFS and DFS 
int main() { 
    int vertices = 5; // Change this for a different size of graph 
    Graph* graph = createGraph(vertices); 
 
    // Adding edges (example directed graph) 
    addEdge(graph, 0, 1); 
    addEdge(graph, 0, 2); 
    addEdge(graph, 1, 3); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 3, 4); 
 
    // Perform BFS and DFS 
    BFS(graph, 0); 
    DFS(graph, 0); 
 
    // Free allocated memory 
    free(graph); 
 
    return 0; 
} 