#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Define a structure for the graph
typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int start, int end) {
    // Add edge from start to end
    Node* newNode = createNode(end);
    newNode->next = graph->adjLists[start];
    graph->adjLists[start] = newNode;

    // Add edge from end to start (for undirected graph)
    newNode = createNode(start);
    newNode->next = graph->adjLists[end];
    graph->adjLists[end] = newNode;
}

// Function to print the graph (adjacency list)
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        printf("\nVertex %d:", i);
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(5);  // Create a graph with 5 vertices

    addEdge(graph, 0, 1);  // Edge between vertex 0 and 1
    addEdge(graph, 0, 4);  // Edge between vertex 0 and 4
    addEdge(graph, 1, 2);  // Edge between vertex 1 and 2
    addEdge(graph, 1, 3);  // Edge between vertex 1 and 3
    addEdge(graph, 3, 4);  // Edge between vertex 3 and 4

    printf("Adjacency List:\n");
    printGraph(graph);

    return 0;
}