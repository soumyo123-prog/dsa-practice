#include <bits/stdc++.h>
using namespace std;

bool dfs(int v, bool vis[], vector<int> adj[], int parent) {
  vis[v] = true;
  for (auto i : adj[v]) {
    if (!vis[i]) {
      if (dfs(i, vis, adj, v)) {
        return true;
      }
    } else {
      if (parent != i) {
        return true;
      }
    }
  }
  return false;
}

bool isCycle(int V, vector<int> adj[]) {
  bool vis[V] = {false};
  for (int i = 0; i < V; i++) {
    if (!vis[i]) {
      if (dfs(i, vis, adj, -1)) {
        return true;
      }
    }
  }
  return false;
}

int main() { return 0; }