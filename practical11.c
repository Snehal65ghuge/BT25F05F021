
#include <stdio.h>

int graph[100][100];
int visited[100];
int queue[100];
int n;

// Breadth First Search
void BFS(int start) {
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int edges, u, v, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize graph and visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;

        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges (u v):\n");

    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;  // Undirected graph
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    printf("BFS traversal: ");
    BFS(start);

    return 0;
}
