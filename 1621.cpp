#include <bits/stdc++.h>

#define INF 66666666
using namespace std;
typedef pair<int, int> par;

vector<vector<par > > g;
vector<int> piDist;
int n;
int m;

void dijkstra(int src){


	piDist.clear();
	piDist.assign(m * m + 2, INF);
	piDist[src] = 0;
	
	priority_queue<par, vector<par>, greater<par> > fila;
	
	fila.push(par(0, src));
	
	while(!fila.empty()){
		par v = fila.top();
		fila.pop();
		
		
		for (int i = 0 ; i < g[v.second].size(); i++){
			if (piDist[g[v.second][i].second] > piDist[v.second] + 1){
				piDist[g[v.second][i].second] = piDist[v.second] + 1;
				fila.push(par(piDist[g[v.second][i].second], g[v.second][i].second));
			}
		}
	}
}
int main(){
	vector<string> aux;
	string x;
	
	char c;
	while(1){

		cin >> n;
		cin >> m;
		if (!n && !m) return 0;
		g.assign(m * m + 2, vector<par> ());
		
		for (int i = 0 ; i < n ; i++){
			cin >> x;
			aux.push_back(x);
		}
		
		for (int i = 0 ; i < n; i++){
			for (int j = 0; j < m; j++){
				if (aux[i][j] == '.'){
					if (i > 0){
						if (aux[i - 1][j] == '.'){
							g[m * i + j].push_back(make_pair(1, m * (i - 1) + j));
						}
					}
					if (i < n - 1){
						if (aux[i + 1][j] == '.'){
							g[m * i + j].push_back(make_pair(1, m * (i + 1) + j));
						}
					}
					if (j > 0){
						if (aux[i][j - 1] == '.'){
							g[m * i + j].push_back(make_pair(1, m * i + j - 1));
						}
					}
					if (j < m - 1){
						if (aux[i][j + 1] == '.'){
							g[m * i + j].push_back(make_pair(1, m * i + j + 1));
						}
					}
				}
			}
		}
		int src;
		
		for (src = 0; src < g.size(); ++src) if (g[src].size()) break;
		dijkstra(src);
		int maux = INT_MIN;
		for (int i = 0 ; i < piDist.size(); ++i){
			if (piDist[i] != INF && piDist[i] > maux) maux = piDist[i], src = i;
		}
		dijkstra(src);
		maux = INT_MIN;
		for (int i = 0 ; i < piDist.size(); ++i){
			if (piDist[i] != INF && piDist[i] > maux) {
				maux = piDist[i];
			}
		}
		
		
		cout << maux << endl;
		
		g.clear();		
		aux.clear();
	}
	
}

