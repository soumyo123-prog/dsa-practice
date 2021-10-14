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

void solve() {
  int n, m;
  in n >> m;

  vector<int> adj[n];
  vector<int> t(n, -1);

  for (int i = 0; i < m; i++) {
    int a, b;
    in a >> b;
    adj[a - 1].pb(b - 1);
    adj[b - 1].pb(a - 1);
  }

  bool bp = true;
  vector<bool> vis(n, false);

  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      queue<int> q;
      q.push(i);
      vis[i] = true;
      t[i] = 0;

      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
          if (!vis[*i]) {
            vis[*i] = true;
            q.push(*i);
            t[*i] = !(t[u]);
          } else {
            if (t[*i] == t[u]) {
              bp = false;
              break;
            }
          }
        }
        if (!bp) {
          break;
        }
      }
    }
  }

  if (bp) {
    for (int i = 0; i < t.size(); i++) {
      out t[i] + 1 << ' ';
    }
    cout endl;
  } else {
    out "IMPOSSIBLE" endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}