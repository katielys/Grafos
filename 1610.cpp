#include<vector>
#include <iostream>
using namespace std;
//1610 uri
// Katiely dos Santos Oliveira Moreira - 21600808

bool hasCicle;
vector<vector<int> > graph;
vector<int> visited; 
void dfs(int n){
	visited[n] = 1;
	if (hasCicle) return;
	for (int i = 0 ; i < graph[n].size(); i++){
		if (visited[graph[n][i]] == 1){
			hasCicle = true;
			return;
		}
		else if (visited[graph[n][i]] == 0){
			dfs(graph[n][i]);
		}
	}	
	visited[n] = 2;
}

int main (){
	int numberCases,b,a,m,n;
	//vector<int> visited ;
	cin >> numberCases;
	while(numberCases>0){
		cin >> n;
		cin >> m;
		graph.assign(n, vector<int> ());
		visited.assign(n,0);
		
		for (int i = 0 ; i < m; i++){
			cin >> a;
			cin >> b;
			if(a>=1 && b<=n && 	b!=a){
				graph[a - 1].push_back(b - 1);	
			}
			
		}

		hasCicle = false;
		for (int i = 0 ; i < n; i++){
			if (visited[i]!=1)
				dfs(i);
			if (hasCicle) break;
		}
		if (hasCicle) {
			cout << "SIM\n";	
		}
		else {
			cout << "NAO\n";
		}
		visited.clear();
		graph.clear();
		hasCicle = false;
		numberCases--;
	}
}
