#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EDGES 100
#define MAX_NODES 100

struct Edge {
    char start;
    char end;
    int weight;
};

int cmpfunc(const void* a, const void* b) {
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge1->weight - edge2->weight;
}

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

void kruskal(struct Edge edges[], int numNodes, int numEdges) {
    int parent[MAX_NODES];
    memset(parent, -1, sizeof(parent));

    qsort(edges, numEdges, sizeof(struct Edge), cmpfunc);

    int mstWeight = 0;
    for (int i = 0; i < numEdges; i++) {
        char start = edges[i].start;
        char end = edges[i].end;
        int weight = edges[i].weight;

        int parentStart = find(parent, start - 'A');
        int parentEnd = find(parent, end - 'A');

        if (parentStart != parentEnd) {
            Union(parent, parentStart, parentEnd);
            printf("Edge %c - %c with weight %d added to MST\n", start, end, weight);
            mstWeight += weight;
        }
    }

    printf("Minimum Spanning Tree weight: %d\n", mstWeight);
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
        edges[i].start = start;
        edges[i].end = end;
        edges[i].weight = weight;
    }

    kruskal(edges, numNodes, numEdges);

    return 0;
}