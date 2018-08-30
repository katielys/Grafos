#include <bits/stdc++.h>
using namespace std;


int vertex, edges;

void dfs(vector<bool> &visited, vector<vector<int> > &graph, int nowVertex) {
    visited[nowVertex] = true;
    vertex += 1;
    edges += graph[nowVertex].size();
    for(int v=0; v<graph[nowVertex].size();v++) {
        if(!visited[v])
            dfs(visited, graph, v);
    }
}

int main() {
    int v;
    char c;
    cin >> v;
    vector<vector<int> > graph(v);
    vector<bool>  visited(v);
    for(int i=0; i<v; i++) {
        for(int j=0; j<v; j++) {
            cin >> c;
            if(i != j && c == 'S')
                graph[i].push_back(j);
        }
    }

    vector<int> componts;
    for(int i=0; i<v; i++) {
        if(!visited[i]) {
            vertex = edges = 0;
            dfs(visited, graph, i);
            if((vertex * (vertex - 1) != edges)) {
                cout << "-1\n";
                return 0;
            }
            componts.push_back(vertex);
        }
    }
    sort(componts.rbegin(), componts.rend());
    cout << componts.size() << '\n';
    for(int i=0; i<componts.size(); i++) {
        cout << componts[i];
        if(i < componts.size() - 1) cout << ' ';
    }
    cout << endl;
    return 0;
}
