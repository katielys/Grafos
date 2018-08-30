#include <iostream>
#include <algorithm>
 
using namespace std;
 
typedef struct {
    int x;
    int y;
    int w;
} edge;
 
bool compare(edge u, edge v) {
    return (u.w < v.w);
}
 
int hasCicle(int path[], int src, int dest) {
    while (path[src] > -1) {
        src = path[src];
    }
     
    while (path[dest] > -1) {
        dest = path[dest];
    }
     
    if (src != dest) {
        path[dest]=src;
         
        return 1;
    }
     
    return 0;
}

int main() {
    int totalVertexs, totalEdges;
     
    int path[200000]; edge edges[200000];
    while (cin>> totalEdges >> totalVertexs) {
         if( totalEdges==0 && totalVertexs==0){
             return 0;
         }
        int cost = 0, totalCost = 0;
         
        for (int i = 0; i < totalVertexs; i++) {
            path[i] = -1;
        }
         
        for (int i = 0; i < totalEdges; i++) {
            cin >> edges[i].x >> edges[i].y >> edges[i].w;
            totalCost += edges[i].w;
        }
     
        sort (edges, edges + totalEdges, compare);
     
        int i = 0;
        int j = 1;
         
        while (j < totalVertexs and i < totalEdges) {
            if (hasCicle(path, edges[i].x, edges[i].y)) {
                j++;
                cost = cost + edges[i].w;
            }
             
            i++;
        }
         
        cout << totalCost - cost << endl;
    }
     
    return 0;
}
