#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int v, vector<int> adj[]) {
  vector<bool> vis(v, false);
  vector<int> bfsResult;

  for (int i = 0; i < v; i++) {
    if (!vis[i]) {
      queue<int> q;
      q.push(i);
      vis[i] = true;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        bfsResult.push_back(u);
        for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
          if (!vis[*i]) {
            q.push(*i);
            vis[*i] = true;
          }
        }
      }
    }
  }

  return bfsResult;
}

int main() { return 0; }