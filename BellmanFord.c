#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<ctype.h>

#define MAX_EDGES 100
#define MAX_NODES 100

struct Edge {
    char start;
    char end;
    int weight;
};

void bellmanFord(struct Edge edges[], int numNodes, int numEdges, char source) {
    int distance[MAX_NODES];
    int previous[MAX_NODES];

    for (int i = 0; i < numNodes; i++) {
        distance[i] = INT_MAX;
        previous[i] = -1;
    }

    distance[source - 'A'] = 0;

    for (int i = 0; i < numNodes - 1; i++) {
        for (int j = 0; j < numEdges; j++) {
            char start = edges[j].start;
            char end = edges[j].end;
            int weight = edges[j].weight;

            if (distance[start - 'A'] != INT_MAX && distance[start - 'A'] + weight < distance[end - 'A']) {
                distance[end - 'A'] = distance[start - 'A'] + weight;
                previous[end - 'A'] = start - 'A';
            }
        }
    }

    for (int j = 0; j < numEdges; j++) {
        char start = edges[j].start;
        char end = edges[j].end;
        int weight = edges[j].weight;

        if (distance[start - 'A'] != INT_MAX && distance[start - 'A'] + weight < distance[end - 'A']) {
            printf("Error: Negative cycle detected\n");
            return;
        }
    }

    printf("Shortest distances from source %c:\n", source);
    for (int i = 0; i < numNodes; i++) {
        printf("%c: %d\n", i + 'A', distance[i]);
    }

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
    bellmanFord(edges, numNodes, numEdges, source);

    return 0;
}