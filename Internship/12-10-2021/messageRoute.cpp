#include <bits/stdc++.h>
using namespace std;

#define endl << "\n"
#define in cin >>
#define out cout <<
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vvi vector<vector<int>>
#define vi vector<int>

void printArray(vector<int> &arr, int n) {
  for (int i = 0; i < n; i++) {
    out arr[i] << " ";
  }
  cout endl;
  return;
}

void solve() {
  int n, m;
  in n >> m;

  vector<int> adj[n];
  for (int i = 0; i < m; i++) {
    int a, b;
    in a >> b;
    adj[a - 1].pb(b - 1);
    adj[b - 1].pb(a - 1);
  }

  vector<int> prev(n, -1), dist(n, INT_MAX);
  vector<bool> vis(n, false);
  dist[0] = 1;
  vis[0] = true;

  bool found = false;
  queue<int> q;
  q.push(0);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
      if (!vis[*i]) {
        vis[*i] = true;
        q.push(*i);
        if (dist[u] != INT_MAX && dist[*i] > dist[u] + 1) {
          dist[*i] = dist[u] + 1;
          prev[*i] = u;
        }
        if (*(i) == n - 1) {
          found = true;
          break;
        }
      }
    }
    if (found) {
      break;
    }
  }

  if (!found) {
    out "IMPOSSIBLE" endl;
  } else {
    out dist[n - 1] endl;
    vector<int> res;
    int num = n - 1;
    while (num != 0) {
      res.pb(num + 1);
      num = prev[num];
    }
    res.pb(1);
    reverse(res.begin(), res.end());
    printArray(res, res.size());
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}