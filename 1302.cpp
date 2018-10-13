#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

#define MAX 100011
#define LD 20 


int n, nxt[MAX], grauRela[MAX];

vector<int> g[MAX];

bool grey[MAX], visited[MAX];
int ring, ring_size[MAX], people[MAX], actualTree, treeID[MAX];

int MATRIX[MAX][LD] ;
int L[MAX];
int T[MAX];

void prepare(int node) {
  queue<int> Q;
  Q.push(node);

  while (!Q.empty()) {
    int act = Q.front(); Q.pop();
    int p = act == node ? -1: T[act];
    L[act] = p == -1 ? 0 : L[p] + 1; 
    memset(MATRIX[act], -1, sizeof (MATRIX[act]));
    MATRIX[act][0] = p;

    for (int i = 0; i + 1 < LD && MATRIX[act][i] != -1; ++i){

      MATRIX[act][i + 1] = MATRIX[MATRIX[act][i]][i];
    } 

    for (auto &it : g[act]) {
      int v = it;
      if (!grey[v]) {
        people[v] = people[act];
        treeID[v] = treeID[act];
        T[v] = act;
        Q.push(v);
      }
    }
  }
}

int jump(int u, int d) {
  for (int i = 0; i < LD; ++ i) {
    if (d >> i & 1) {
      u = MATRIX[u][i];
    }
  }
  return u;
}

int resi(int u, int v) {
  if (L[u] > L[v]) {
    int x ; 
    x = u;
    u = v;
    v = x; 
  }
  v = jump(v, L[v] - L[u]);
  if(u == v)
    return u;

  for (int i = LD - 1; i >= 0; --i) {
    if (MATRIX[u][i] != MATRIX[v][i]) {
      u = MATRIX[u][i];
      v = MATRIX[v][i];
    }
  }
  return MATRIX[u][0];
}

int solve(int a, int b) {
  if (people[a] != people[b]) {
    return -1;
  }
  if (treeID[a] != treeID[b]) {
    int r = ring_size[people[a]];
    int d = abs(treeID[a] - treeID[b]);
    return L[a] + L[b] + min(d, r - d);
  }
  int c = resi(a, b);
  return L[a] + L[b] - 2 * L[c];
}

void ordenaTop() {
  queue<int> Q;
  memset(grey, true, sizeof (grey));
  for (int i = 0; i < n; ++i)
    if (!grauRela[i])
      Q.push(i);

  while (!Q.empty()) {
    int u = Q.front(); Q.pop();
    grey[u] = false;
    if (!--grauRela[nxt[u]])
      Q.push(nxt[u]);
  }
}

int main() {

  while (cin >> n) {
    for (int i = 0; i < n; ++ i)
      g[i].clear();

    memset(grauRela, 0, sizeof (grauRela));
    for (int i = 0; i < n; ++ i) {
      cin >> nxt[i];
      g[--nxt[i]].push_back(i);
      grauRela[nxt[i]]++;
    }

    ordenaTop();

    ring = actualTree = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; ++ i) {
      if (grey[i]) {
        if (!visited[i]) {
          ring_size[ring] = 0;
          int j = i;
          do {
            visited[j] = true;
            people[j] = ring;
            ring_size[ring]++;
            treeID[j] = actualTree++;
            j = nxt[j];
          } while (j != i);
          ring++;
        }
        prepare(i);
      }
    }

    int q;
    cin >> q;
    while (q--) {
      int a, b;
      cin >> a;
      cin >> b;
      cout << solve(a - 1, b - 1) << endl;
    }
  }
  return 0;
}
