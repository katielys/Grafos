#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 100
using namespace std;
int my_graph[MAX][MAX];
int visiteed[MAX];
int stack[MAX];
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
	int v;
	int a;
	int src, dest, numberofTestes, firstVertex;
	cin >>  numberofTestes;
	for(int j = 0; j < numberofTestes; j++){
		cont = 0;
		memset(my_graph, -1, sizeof(my_graph));
		memset(visiteed, -1, sizeof(visiteed));
		memset(stack, -1, sizeof(stack));
        cin >> firstVertex;
        cin >> v; 
        cin >> a;
		for (int i = 0; i < a; i++){
            cin >> src ;
            cin >> dest;
			makeEdge(src, dest);
		   
	    }
         dfs(firstVertex, v);
		 cont *= 2;
         cout << cont <<endl;
    }

	return 0;
}