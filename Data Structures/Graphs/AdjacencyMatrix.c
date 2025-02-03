#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "GRAPH.h"

struct graph {
    int V;
    int E;
    int** adj;
};

int** MATRIXint(int, int, int);

Graph GRAPHinit(int V) {
    Graph G = malloc(sizeof *G);
    G->V = V;
    G->E = 0;
    G->adj = MATRIXint(V, V, 0);
    return G;
}

void GRAPHinsertE(Graph G, Edge e) {
    int v = e.v;
    int w = e.w;
    
    if (G->adj[v][w] == 0)
        G->E++;
    
    G->adj[v][w] = e.weight;
}

void GRAPHremoveE(Graph G, Edge e) {
    int v = e.v;
    int w = e.w;

    if (G->adj[v][w] > 1)
        G->E--;

    G->adj[v][w] = 0;
}

int GRAPHedges(Edge a[], Graph G) {
    int v, w, E = 0;

    for (v = 0; v < G->V; v++)
        for (w = v+1; w < G->V; w++)
            if (G->adj[v][w] == 1)
                a[E++] = EDGE(v, w, G->adj[v][w]);

    return E;
}

void GRAPHshow(Graph G) {
    int i, j = 0;
    printf ("%d vertices, %d edges\n", G->V, G->E);

    for (i = 0; i < G->V; i++) {
        printf("%2d:", i);
        for (j = 0; j < G->V; j++)
            if (G->adj[i][j] > 0)
                printf(" %2d", j);
        
        printf("\n");
    }
}

void GRAPHprint(Graph G){
    for (int i = 0; i < G->V; i++){
        for (int j = 0; j < G->V; j++){
            printf("%d ", G->adj[i][j]);
        }
        printf("\n");
    }
}

void GRAPHprintWithPrintFunction(Graph G, void (*print)(int)){
    for (int i = 0; i < G->V; i++){
        for (int j = 0; j < G->V; j++){
            print(G->adj[i][j]);
        }
        printf("\n");
    }
}

int GRAPHweightE(Graph G, int v, int w){
    return G->adj[v][w];
}

void GRAPHdestroy(Graph g) {
    int** graph = g->adj;
    int i, j, r = g->V;

    for (i = 0; i < r; i++){
        free(graph[i]);
        graph[i] = 0;
    }

    free(graph);
    graph = 0;
}

int **MATRIXint(int r, int c, int val) {
    int i, j = 0;

    int** t = malloc(r * sizeof(int*));
    if (t == NULL){
        printf("Memory allocation failed. Exiting...");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < r; i++) {
        t[i] = malloc(c * sizeof(int));

        if (t[i] == NULL){
            printf("Memory allocation failed. Exiting...");

            int k = 0;
            for (; k < i; k++){
                free(t[k]);
                t[k] = 0;
            }

            exit(EXIT_FAILURE);
        }
    }
    
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            t[i][j] = val;

    return t;
}

int* DFS(Graph G, int vertex, int vertices, int* visited) {
    static int count = 0;
    count++;
    if (visited[vertex] == 0)
        visited[vertex] = count;

    for (int i = 0; i < vertices; i++) {
        if (G->adj[vertex][i] > 0 && !visited[i]) {
            DFS(G, i, vertices, visited);
        }
    }

    return visited;
}

int* _DFS(Graph G, int vertex, int vertices, int* visited) {
    visited[vertex] = 1;

    for (int i = 0; i < vertices; i++) {
        if (G->adj[vertex][i] > 0 && !visited[i]) {
            _DFS(G, i, vertices, visited);
        }
    }

    return visited;
}

bool contains(int array[], int valueToSearch, int arrayLength){
    for (int i = 0; i < arrayLength; i++){
        if (array[i] == valueToSearch)
            return true;
    }

    return false;
}

int* BFS(Graph G, int vertex, int vertices, int *visited) {
    memset(visited, 0, vertices * (sizeof(int)));
    int j = 0;

    visited[j++] = vertex;

    for (int k = 0; k < vertices; k++){
        int v = visited[k];
        int *row = G->adj[v];

        for (int i = 0; i < vertices; i++){
            if (row[i] != 0 && !contains(visited, i, vertices))
                visited[j++] = i;
        }
    }

    return visited;
}

int GRAPHforests(Graph G, int v){
    int* visited = calloc(v, sizeof(int));
    int count = 0;

    for (int i = 0; i < G->V; i++){
        if (visited[i] == 0){
            _DFS(G, i, v, visited);
            count++;
        }
    }

    free(visited);
    visited = 0;

    return count;
}

void GRAPHtraverseBFS(Graph g, int vertex, void (*print)(int)){
    int *visited = calloc(g->V, sizeof(int));
    int *array = BFS(g, vertex, g->V, visited);

    for (int i = 0; i < g->V; i++) {
        print(array[i]);
    }

    free(visited);
    visited = 0;
}

void GRAPHtraverseDFS(Graph g, int vertex, void (*print)(int)) {
    int *visited = calloc(g->V, sizeof(int));
    int *array = DFS(g, vertex, g->V, visited);
    int *corrected = calloc(g->V, sizeof(int));
    int i, j;

    for (i = 0; i < g->V; i++) {
        corrected[array[i] - 1] = i + 1;
    }

    for (i = 0; i < g->V; i++) {
        print(corrected[i]);
    }

    free(visited);
    visited = 0;

    free(corrected);
    corrected = 0;
}