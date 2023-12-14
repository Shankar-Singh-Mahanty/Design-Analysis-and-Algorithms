#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 100

struct Edge {
    char start;
    char end;
    int weight;
};

void dijkstra(struct Edge edges[], int numNodes, int numEdges, char source) {
    int distance[MAX_NODES];
    int visited[MAX_NODES];
    int parent[MAX_NODES];

    for (int i = 0; i < numNodes; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    distance[source - 'A'] = 0;

    for (int i = 0; i < numNodes - 1; i++) {
        int minDistance = INT_MAX;
        int minIndex = -1;

        for (int j = 0; j < numNodes; j++) {
            if (!visited[j] && distance[j] < minDistance) {
                minDistance = distance[j];
                minIndex = j;
            }
        }

        if (minIndex == -1) break;

        visited[minIndex] = 1;

        for (int j = 0; j < numEdges; j++) {
            if (edges[j].start == minIndex + 'A') {
                int end = edges[j].end - 'A';
                int weight = edges[j].weight;

                if (!visited[end] && distance[minIndex] + weight < distance[end]) {
                    distance[end] = distance[minIndex] + weight;
                    parent[end] = minIndex;
                }
            }
        }
    }

    printf("Shortest distances from source %c:\n", source);
    for (int i = 0; i < numNodes; i++) {
        printf("Vertex %c: %d\n", i + 'A', distance[i]);
    }

    // printf("Shortest paths from source %c:\n", source);
    // for (int i = 0; i < numNodes; i++) {
    //     printf("Path to %c: ", i + 'A');
    //     int current = i;
    //     while (current != -1) {
    //         printf("%c ", current + 'A');
    //         current = parent[current];
    //     }
    //     printf("\n");
    // }
}

int main() {
    int numNodes, numEdges;
    printf("Enter number of nodes: ");
    scanf("%d", &numNodes);
    printf("Enter number of edges: ");
    scanf("%d", &numEdges);

    struct Edge edges[MAX_EDGES];
    for (int i = 0; i < numEdges; i++) {
        char start, end;
        int weight;
        printf("Enter edge %d (startV endV weight): ", i + 1);
        scanf(" %c %c %d", &start, &end, &weight);
        start = toupper(start);
        end = toupper(end);
        edges[i].start = start;
        edges[i].end = end;
        edges[i].weight = weight;
    }

    char source;
    printf("Enter source vertex: ");
    scanf(" %c", &source);
    source = toupper(source);
    dijkstra(edges, numNodes, numEdges, source);

    return 0;
}