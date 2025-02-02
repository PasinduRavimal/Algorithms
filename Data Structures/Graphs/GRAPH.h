#ifndef GRAPHADT_H
#define GRAPHADT_H

typedef struct {
    int v;
    int w;
    int weight;
} Edge;

Edge EDGE(int v, int w, int weight) {
    Edge* edge = malloc(sizeof *edge);
    edge->v = v;
    edge->w = w;
    edge->weight = weight;

    return *edge;
};

typedef struct graph *Graph;

Graph GRAPHinit(int);
void GRAPHinsertE(Graph, Edge);
void GRAPHremoveE(Graph, Edge);
int GRAPHedges(Edge[], Graph G);
Graph GRAPHcopy(Graph);
void GRAPHdestroy(Graph);
void GRAPHshow(Graph);
void GRAPHprint(Graph);
void GRAPHprintWithPrintFunction(Graph, void (*print)(int));
int GRAPHweightE(Graph, int, int);


#endif