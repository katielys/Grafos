#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//katiely - 1862 Westeros - DFS - 30.08

int nVertex, nEdges;

void dfs(vector<bool> &visited, vector<vector<int> > &graph, int s) {
    visited[s] = true;
    nVertex += 1;
    nEdges += graph[s].size();
    for(int v : graph[s]) {
        if(!visited[v])
            dfs(visited, graph, v);
    }
}

int main() {
  
    int numberOfPeople;
    char c;
    cin >> numberOfPeople;

    vector<vector<int> > graph(numberOfPeople);
    vector<bool> visited(numberOfPeople);

    for(int i=0; i<numberOfPeople; i++) {
        for(int j=0; j<numberOfPeople; j++) {
            cin >> c;
            if(i != j && c == 'S')
                graph[i].push_back(j);
        }
    }

    vector<int> neighbourhoodWesteros;

    for(int i=0; i<numberOfPeople; i++) {
        if(!visited[i]) {
            nVertex =0;
            nEdges = 0;
            dfs(visited, graph, i);
            if((nVertex * (nVertex - 1) != nEdges)) {
                cout << -1 <<endl;
                return 0;
            }
            neighbourhoodWesteros.push_back(nVertex);
        }
    }
    sort(neighbourhoodWesteros.rbegin(), neighbourhoodWesteros.rend());
    cout << neighbourhoodWesteros.size() << endl;
    for(int i=0; i<neighbourhoodWesteros.size(); i++) {

        cout << neighbourhoodWesteros[i];
        if(i < neighbourhoodWesteros.size() - 1){
        	cout << ' ';
        } 
    }
    cout << endl;
    visited.clear();
    graph.clear();
    return 0;
}
