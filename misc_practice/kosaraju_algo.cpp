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

void dfsUtil(int v, bool vis[], vector<int> adj[]) {
  vis[v] = true;
  for (auto i : adj[v]) {
    if (!vis[i]) {
      dfsUtil(i, vis, adj);
    }
  }
}

int kosaraju(int V, vector<int> adj[]) {
  bool vis[V] = {false};
  stack<int> st;
  for (int i = 0; i < V; i++) {
    if (!vis[i]) {
      topoSortUtil(i, vis, adj, st);
    }
  }

  vector<int> transpose[V];
  for (int i = 0; i < V; i++) {
    vis[i] = false;
    for (auto j : adj[i]) {
      transpose[j].push_back(i);
    }
  }

  int ans = 0;
  while (!st.empty()) {
    int u = st.top();
    st.pop();
    if (!vis[u]) {
      ans++;
      dfsUtil(u, vis, transpose);
    }
  }

  return ans;
}

int main() { return 0; }