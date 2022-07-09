#include <bits/stdc++.h>
using namespace std;

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
  int vis[V] = {false}, recStack[V] = {false};
  vector<int> dfsResult;
  for (int i = 0; i < V; i++) {
    if (!vis[i]) {
      stack<int> nodes;
      nodes.push(i);
      recStack[i] = true;
      while (!nodes.empty()) {
        int node = nodes.top();
        nodes.pop();
        vis[node] = true;
        dfsResult.push_back(node);
        for (auto j : adj[node]) {
          if (!vis[j] && !recStack[j]) {
            nodes.push(j);
            recStack[j] = true;
          }
        }
      }
    }
  }
  return dfsResult;
}

int main() { return 0; }