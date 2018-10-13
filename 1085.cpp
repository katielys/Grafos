#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;
#define SIZE 112
#define INFINITY  666666666

typedef pair<string, string> pairString;
typedef pair<int, pairString> pairHelp;


map<string, vector<pairString> > path;
map<string, int> dist;

int M;

int dijkstra(string s, string t){
	string u, v, w, x;
	dist[s] = 0;
	priority_queue<pairHelp, vector<pairHelp>, greater<pairHelp> > fila;
	fila.push(pairHelp(0, pairString(s, " ")));
	while(!fila.empty()){
		u = fila.top().second.first; 
		x = fila.top().second.second; 
		fila.pop();
		if(u == t) break;
		for(int i = 0; i < (int)path[u].size(); i++){
			v = path[u][i].first;
			w = path[u][i].second;
			if(w[0] != x[0]
			&& dist[v] > dist[u] + (int)w.size()){
				dist[v] = dist[u] + (int)w.size();
				fila.push(pairHelp(dist[v], pairString(v, w)));
			}
		}
	}
	return dist[t];
}

int main(){

	char src[SIZE];
	char destiny[SIZE];
	char u[SIZE];
	char v[SIZE];
	char w[SIZE];

	cin >> M;
	while(M != 0){
		cin >> src;
		cin >> destiny;
		path.clear();
		dist.clear();
		dist[src] = dist[destiny] = INFINITY;
		for(int i = 0; i < M; i++){

			cin >> u;
			cin >>v;
			cin >> w;
			dist[u] = dist[v] = INFINITY;
			path[u].push_back(pairString(v, w));
			path[v].push_back(pairString(u, w));
		}
		int value = dijkstra(destiny, src);

		if(value == INFINITY) {
			cout<< "impossivel"<<endl;
		}
		else {
			cout<< value << endl;
		};
		cin>> M;
	}
	return 0;
}
