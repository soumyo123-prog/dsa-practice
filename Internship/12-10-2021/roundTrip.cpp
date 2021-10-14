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

int st, en;
vector<int> cycle;

int find(int x, vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    if (x == arr[i]) {
      return i;
    }
  }
  return -1;
}

bool dfsHelper(int u, vector<int> adj[], vector<bool> &vis, int prev) {
  vis[u] = true;
  cycle.pb(u);
  for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
    if (!vis[*i]) {
      if (dfsHelper(*i, adj, vis, u)) {
        return true;
      }
    } else {
      if (prev != *i) {
        st = *i;
        en = u;
        cycle.push_back(*i);
        return true;
      }
    }
  }
  cycle.pop_back();
  return false;
}

void dfs(vector<int> adj[], int n) {
  vector<bool> vis(n, false);
  vector<int> prev(n, -1);

  bool found = false;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      if (dfsHelper(i, adj, vis, -1)) {
        found = true;
        int i1 = find(st, cycle), i2 = find(en, cycle);
        out i2 - i1 + 2 endl;
        for (int j = i1; j <= i2; j++) {
          out cycle[j] + 1 << " ";
        }
        out st + 1 << ' ' endl;
        break;
      }
    }
  }

  if (!found) {
    out "IMPOSSIBLE" endl;
  }
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

  dfs(adj, n);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}