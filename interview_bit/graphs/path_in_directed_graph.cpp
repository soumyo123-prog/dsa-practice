#include <bits/stdc++.h>
using namespace std;

int solve(int a, vector<vector<int> > &b) {
  vector<int> adj[a];
  for (int i = 0; i < b.size(); i++) {
    adj[b[i][0] - 1].push_back(b[i][1] - 1);
  }

  bool vis[a] = {false};
  queue<int> q;
  q.push(0);
  vis[0] = true;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (auto i : adj[node]) {
      if (!vis[i]) {
        vis[i] = true;
        q.push(i);
        if (i == a - 1) {
          return 1;
        }
      }
    }
  }

  return 0;
}

int main() { return 0; }
