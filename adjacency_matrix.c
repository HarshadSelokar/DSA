#include <stdio.h>

#define MAX_VERTICES 5

void initializeMatrix(int matrix[MAX_VERTICES][MAX_VERTICES]) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            matrix[i][j] = 0;
        }
    }
}

void addEdge(int matrix[MAX_VERTICES][MAX_VERTICES], int start, int end) {
    matrix[start][end] = 1;  // Directed edge from start to end
    matrix[end][start] = 1;   // Uncomment for undirected graph
}

void displayMatrix(int matrix[MAX_VERTICES][MAX_VERTICES]) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[MAX_VERTICES][MAX_VERTICES];
    initializeMatrix(matrix);

    addEdge(matrix, 0, 1);  // Edge between vertex 0 and 1
    addEdge(matrix, 0, 4);  // Edge between vertex 0 and 4
    addEdge(matrix, 1, 2);  // Edge between vertex 1 and 2
    addEdge(matrix, 1, 3);  // Edge between vertex 1 and 3
    addEdge(matrix, 3, 4);  // Edge between vertex 3 and 4

    printf("Adjacency Matrix:\n");
    displayMatrix(matrix);

    return 0;
}