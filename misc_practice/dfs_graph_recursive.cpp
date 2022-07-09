#include <bits/stdc++.h>
using namespace std;

void dfsHelper(int v, int vis[], vector<int> adj[], vector<int> &dfsResult) {
  vis[v] = true;
  dfsResult.push_back(v);
  for (auto i : adj[v]) {
    if (!vis[i]) {
      dfsHelper(i, vis, adj, dfsResult);
    }
  }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
  int vis[V] = {false};
  vector<int> dfsResult;
  for (int i = 0; i < V; i++) {
    if (!vis[i]) {
      dfsHelper(i, vis, adj, dfsResult);
    }
  }
  return dfsResult;
}

int main() { return 0; }