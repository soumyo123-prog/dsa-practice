#include <bits/stdc++.h>
using namespace std;

bool isBipartiteUtil(int v, bool vis[], int col[], vector<int> adj[], int color) {
  vis[v] = true;
  col[v] = color;
  for (auto i : adj[v]) {
    if (!vis[i]) {
      if (isBipartiteUtil(i, vis, col, adj, 3 - color)) {
        return true;
      }
    } else if (col[i] == color) {
      return false;
    }
  }
  return true;
}

bool isBipartite(int V, vector<int> adj[]) {
  bool vis[V] = {false};
  int col[V] = {0};

  for (int i = 0; i < V; i++) {
    if (!vis[i]) {
      if (isBipartiteUtil(i, vis, col, adj, 1)) {
        return true;
      }
    }
  }

  return false;
}

int main() { return 0; }