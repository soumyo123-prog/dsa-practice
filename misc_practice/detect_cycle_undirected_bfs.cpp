#include <bits/stdc++.h>
using namespace std;

bool isCycle(int V, vector<int> adj[]) {
  int parent[V];
  for (int i = 0; i < V; i++) {
    parent[i] = -1;
  }
  bool vis[V] = {false};
  for (int i = 0; i < V; i++) {
    if (!vis[i]) {
      queue<int> q;
      q.push(i);
      vis[i] = true;
      while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto j : adj[node]) {
          if (!vis[j]) {
            q.push(j);
            vis[j] = true;
            parent[j] = node;
          } else {
            if (parent[node] != j) {
              return true;
            }
          }
        }
      }
    }
  }
  return false;
}

int main() {
  vector<int> adj[] = {{}, {2}, {1, 3}, {2}};
  cout << isCycle(4, adj) << endl;
  return 0;
}