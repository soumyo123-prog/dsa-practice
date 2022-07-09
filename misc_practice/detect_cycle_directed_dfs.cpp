#include <bits/stdc++.h>
using namespace std;

bool isCyclicUtil(int v, bool vis[], vector<int> adj[], bool dfsStack[]) {
  vis[v] = true;
  dfsStack[v] = true;
  for (auto i : adj[v]) {
    if (!vis[i]) {
      if (isCyclicUtil(i, vis, adj, dfsStack)) {
        return true;
      }
    } else if (dfsStack[i]) {
      return true;
    }
  }
  dfsStack[v] = false;
  return false;
}

bool isCyclic(int V, vector<int> adj[]) {
  bool vis[V] = {false};
  bool dfsStack[V] = {false};
  for (int i = 0; i < V; i++) {
    if (!vis[i]) {
      if (isCyclicUtil(i, vis, adj, dfsStack)) {
        return true;
      }
    }
  }
  return false;
}

int main() { return 0; }