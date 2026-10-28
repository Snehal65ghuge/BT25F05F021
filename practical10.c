
#include <stdio.h>

int graph[100][100];
int visited[100];
int n;

// Depth First Search
void DFS(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int edges, u, v, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;  // Undirected graph
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    printf("DFS traversal: ");
    DFS(start);

    return 0;
}
