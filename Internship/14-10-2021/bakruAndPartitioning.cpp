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

vector<int> XOR(100002, 0);
int c = 0;

void initialize(vector<int> &arr, int n) {
  for (int i = 0; i < n; i++) {
    int x;
    in x;
    arr.pb(x);
  }
  return;
}

void dfs(int u, vector<bool> &vis, vector<int> adj[], vector<int> val,
         int num) {
  vis[u] = true;

  for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
    if (!vis[*i]) {
      XOR[u] ^= val[*i];
      dfs(*i, vis, adj, val, num);
    }
  }

  if (XOR[u] == num) {
    c++;
    XOR[u] = 0;
  }
}

void solve() {
  int n, k;
  in n >> k;
  vector<int> arr;
  initialize(arr, n);

  vector<int> adj[n];
  for (int i = 1; i < n; i++) {
    int a, b;
    in a >> b;
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }

  string yes = "YES", no = "NO";

  int num = arr[0];
  for (int i = 1; i < n; i++) {
    num = num ^ arr[i];
  }

  if (num == 0) {
    out yes endl;
  } else {
    if (k == 2) {
      out no endl;
    } else {
      XOR.clear();
      c = 0;
      vector<bool> vis(n, false);
      dfs(0, vis, adj, arr, num);

      if (c >= 2) {
        out yes endl;
      } else {
        out no endl;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  in t;
  while (t--) {
    solve();
  }

  return 0;
}