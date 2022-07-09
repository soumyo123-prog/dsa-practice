#include <bits/stdc++.h>
using namespace std;

void topoSortUtil(int v, bool vis[], vector<int> adj[], stack<int> &st) {
  vis[v] = true;
  for (auto i : adj[v]) {
    if (!vis[i]) {
      topoSortUtil(i, vis, adj, st);
    }
  }
  st.push(v);
}

vector<int> topoSort(int V, vector<int> adj[]) {
  bool vis[V] = {false};
  stack<int> st;
  for (int i = 0; i < V; i++) {
    if (!vis[i]) {
      topoSortUtil(i, vis, adj, st);
    }
  }

  vector<int> topoSortResult;
  while (!st.empty()) {
    topoSortResult.push_back(st.top());
    st.pop();
  }
  return topoSortResult;
}

int main() { return 0; }