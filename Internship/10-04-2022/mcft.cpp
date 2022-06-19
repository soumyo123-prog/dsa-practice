#include <bits/stdc++.h>
using namespace std;

#define endl << "\n"
#define in cin >>
#define out cout <<
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pint;
typedef vector<vector<int>> vvint;
typedef vector<int> vint;
typedef vector<pair<int, int>> vpint;
typedef vector<char> vchar;
typedef vector<string> vstring;
typedef map<int, int> mint;
typedef set<int> sint;

int dfs(int v, vector<int> g[], vector<bool> &vis, vector<int> c, int sum,
        int n) {
  out sum endl;
  if (v == n) {
    return sum;
  }
  vis[v] = true;

  int a1 = INT_MAX, a2 = INT_MAX, a3 = INT_MAX;
  if (!vis[g[v][0]]) {
    a1 = dfs(g[v][0], g, vis, c, sum + c[0], n);
  }
  if (!vis[g[v][1]]) {
    a2 = dfs(g[v][1], g, vis, c, sum + c[1], n);
  }
  if (!vis[g[v][2]]) {
    a3 = dfs(g[v][2], g, vis, c, sum + c[2], n);
  }

  return min(a1, min(a2, a3));
}

int mincostTickets(vector<int> &d, vector<int> &c) {
  vector<int> g[d.size() + 1];
  vector<bool> vis(d.size(), false);
  for (int i = 0; i < d.size() - 1; i++) {
    g[i].push_back(i + 1);
    g[i + 1].push_back(i);

    int i1 = lower_bound(d.begin(), d.end(), d[i] + 7) - d.begin();
    int i2 = lower_bound(d.begin(), d.end(), d[i] + 30) - d.begin();
    g[i].push_back(i1);
    g[i1].push_back(i);
    g[i].push_back(i2);
    g[i2].push_back(i);
  }
  for (int i = 0; i <= d.size(); i++) {
    out i << " : ";
    for (int j = 0; j < g[i].size(); j++) {
      out g[i][j] << ' ';
    }
    cout endl;
  }
  return dfs(0, g, vis, c, 0, d.size());
}

void solve() {
  vint days = {1, 4, 6, 7, 8, 20};
  vint costs = {2, 7, 15};
  out mincostTickets(days, costs) endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();
  return 0;
}

// ────────▓▓▓▓▓▓▓────────────▒▒▒▒▒▒
// ──────▓▓▒▒▒▒▒▒▒▓▓────────▒▒░░░░░░▒▒
// ────▓▓▒▒▒▒▒▒▒▒▒▒▒▓▓────▒▒░░░░░░░░░▒▒▒
// ───▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒░░░░░░░░░░░░░░▒
// ──▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░▒
// ──▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░▒
// ─▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░▒
// ▓▓▒▒▒▒▒▒░░░░░░░░░░░▒▒░░▒▒▒▒▒▒▒▒▒▒▒░░░░░░▒
// ▓▓▒▒▒▒▒▒▀▀▀▀▀███▄▄▒▒▒░░░▄▄▄██▀▀▀▀▀░░░░░░▒
// ▓▓▒▒▒▒▒▒▒▄▀████▀███▄▒░▄████▀████▄░░░░░░░▒
// ▓▓▒▒▒▒▒▒█──▀█████▀─▌▒░▐──▀█████▀─█░░░░░░▒
// ▓▓▒▒▒▒▒▒▒▀▄▄▄▄▄▄▄▄▀▒▒░░▀▄▄▄▄▄▄▄▄▀░░░░░░░▒
// ─▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░▒
// ──▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░▒
// ───▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▀▀░░░░░░░░░░░░░░▒
// ────▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░▒▒
// ─────▓▓▒▒▒▒▒▒▒▒▒▒▄▄▄▄▄▄▄▄▄░░░░░░░░▒▒
// ──────▓▓▒▒▒▒▒▒▒▄▀▀▀▀▀▀▀▀▀▀▀▄░░░░░▒▒
// ───────▓▓▒▒▒▒▒▀▒▒▒▒▒▒░░░░░░░▀░░░▒▒
// ────────▓▓▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░▒▒
// ──────────▓▓▒▒▒▒▒▒▒▒▒░░░░░░░░▒▒
// ───────────▓▓▒▒▒▒▒▒▒▒░░░░░░░▒▒
// ─────────────▓▓▒▒▒▒▒▒░░░░░▒▒
// ───────────────▓▓▒▒▒▒░░░░▒▒
// ────────────────▓▓▒▒▒░░░▒▒
// ──────────────────▓▓▒░▒▒
// ───────────────────▓▒░▒
// ────────────────────▓▒
