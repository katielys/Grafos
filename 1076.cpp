#include <iostream>
#include
#define V 100

/* Katiely */
using namespace std;
int my_graph[V][V];
int visiteed[V];
int stack[V];
int sizeStack = 0;
int cont = 0;

void makeEdge(int u, int v){
	my_graph[u][v] = 1;
	my_graph[v][u] = 1;
}


void dfs (int v, int e){
	int i;
	visiteed[v] = 1;
	for (i = 0; i < e; i++){
		if (my_graph[v][i] == 1 && visiteed[i] == -1){
			cont++;
			dfs(i, e);
		}
	}
}

int main(){
	int v, a, src, y, t, firstVertex;
	cin >>  t;
	for(int j = 0; j < t; j++){
		cont = 0;
		memset(my_graph, -1, sizeof(my_graph));
		memset(visiteed, -1, sizeof(visiteed));
		memset(stack, -1, sizeof(stack));
        cin >>  firstVertex;
        cin >> v; 
        cin >> a;
		for (int i = 0; i < a; i++){
            cin >> src ;
            cin >> y;
			makeEdge(src, y);
		   
	    }
         dfs(firstVertex, v);
		 cont *= 2;
         cout << cont <<endl;
    }

	return 0;
}