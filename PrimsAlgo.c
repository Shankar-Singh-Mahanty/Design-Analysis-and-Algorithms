#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h> // This header file contains the toupper function

#define MAX_NODES 100
#define MAX_EDGES 100

struct Edge {
    char start;
    char end;
    int weight;
};

int minKey(int key[], int visited[], int numNodes) {
    // Find the vertex with minimum key value that is not yet visited
    int min = INT_MAX;
    int minIndex;

    for (int i = 0; i < numNodes; i++) {
        if (visited[i] == 0 && key[i] < min) {
            min = key[i];
            minIndex = i;
        }
    }

    // Check if the vertex is visited or not
    if (visited[minIndex] == 0) {
        return minIndex;
    } else {
        // If the vertex is visited, return -1 to indicate an error
        return -1;
    }
}

void prim(struct Edge edges[], int numNodes, int numEdges) {
    // Array to store constructed MST
    int parent[MAX_NODES];

    // Key values used to pick minimum weight edge in cut
    int key[MAX_NODES];

    // To represent set of vertices not yet included in MST
    int visited[MAX_NODES];

    // Initialize all keys as INFINITE
    for (int i = 0; i < numNodes; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    // Always include first vertex in MST
    key[0] = 0;
    parent[0] = -1;

    // The MST will have numNodes vertices
    for (int count = 0; count < numNodes - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, visited, numNodes);

        // Check if the minKey function returns -1 or not
        if (u == -1) {
            // If it returns -1, break the loop and stop the algorithm
            break;
        }

        // Add the picked vertex to the MST Set
        visited[u] = 1;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int i = 0; i < numEdges; i++) {
            char start = edges[i].start;
            char end = edges[i].end;
            int weight = edges[i].weight;

            if (start - 'A' == u && visited[end - 'A'] == 0 && weight < key[end - 'A']) {
                parent[end - 'A'] = u;
                key[end - 'A'] = weight;
            }

            if (end - 'A' == u && visited[start - 'A'] == 0 && weight < key[start - 'A']) {
                parent[start - 'A'] = u;
                key[start - 'A'] = weight;
            }
        }
    }

    // Print the constructed MST
    printf("Edge\tWeight\n");
    int mstWeight = 0;
    for (int i = 1; i < numNodes; i++) {
        printf("%c - %c\t%d\n", parent[i] + 'A', i + 'A', key[i]);
        mstWeight += key[i];
    }

    printf("Minimum Spanning Tree weight: %d\n", mstWeight);
}

void dfs(struct Edge edges[], int numEdges, int visited[], int v) {
    // Mark the current vertex as visited
    visited[v] = 1;

    // Recursively visit all the adjacent vertices of the current vertex
    for (int i = 0; i < numEdges; i++) {
        char start = edges[i].start;
        char end = edges[i].end;

        if (start - 'A' == v && visited[end - 'A'] == 0) {
            dfs(edges, numEdges, visited, end - 'A');
        }

        if (end - 'A' == v && visited[start - 'A'] == 0) {
            dfs(edges, numEdges, visited, start - 'A');
        }
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
        // Convert the input letters to uppercase
        start = toupper(start);
        end = toupper(end);
        edges[i].start = start;
        edges[i].end = end;
        edges[i].weight = weight;
    }

    // Check if the input graph is connected or not
    int connected = 1;
    int visited[MAX_NODES] = {0};
    dfs(edges, numEdges, visited, 0); // Perform a depth-first search from the first vertex
    for (int i = 0; i < numNodes; i++) {
        if (visited[i] == 0) {
            // If any vertex is not visited, the graph is not connected
            connected = 0;
            break;
        }
    }

    if (connected) {
        // If the graph is connected, run the prim function
        prim(edges, numNodes, numEdges);
    } else {
        // If the graph is not connected, print an error message
        printf("The input graph is not connected. Cannot find a minimum spanning tree.\n");
    }

    return 0 ;
}