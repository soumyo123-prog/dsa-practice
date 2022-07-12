#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 1;

int isNegativeWeightCycle(int n, vector<vector<int>> edges) {
  vector<int> dist(n, INF);
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < edges.size(); j++) {
      int u = edges[j][0], v = edges[j][1], wt = edges[j][2];
      if (dist[u] + wt < dist[v]) {
        dist[v] = dist[u] + wt;
      }
    }
  }

  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
    if (dist[u] + wt < dist[v]) {
      return true;
    }
  }

  return false;
}

int main() { return 0; }