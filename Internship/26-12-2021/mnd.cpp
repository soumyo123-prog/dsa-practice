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

int find_set(int v, int par[]) {
  if (v == par[v]) return v;
  return (par[v] = find_set(par[v], par));
}

void union_set(int a, int b, int par[], int size[]) {
  if (size[a] < size[b]) swap(a, b);
  par[b] = a;
  size[a] += size[b];
}

void solve() {
  int n, m1, m2;
  in n >> m1 >> m2;

  int par1[n], par2[n], size1[n], size2[n];
  rep(i, 0, n) {
    par1[i] = i;
    par2[i] = i;
    size1[i] = 1;
    size2[i] = 1;
  }

  while (m1--) {
    int u, v;
    in u >> v;
    u--, v--;
    int p1 = find_set(u, par1), p2 = find_set(v, par1);
    if (p1 != p2) union_set(p1, p2, par1, size1);
  }

  while (m2--) {
    int u, v;
    in u >> v;
    u--, v--;
    int p1 = find_set(u, par2), p2 = find_set(v, par2);
    if (p1 != p2) union_set(p1, p2, par2, size2);
  }

  int ans = 0;
  vpint res;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int p1, p2, p3, p4;
      p1 = find_set(i, par1), p2 = find_set(j, par1);
      p3 = find_set(i, par2), p4 = find_set(j, par2);

      if (p1 != p2 && p3 != p4) {
        union_set(p1, p2, par1, size1);
        union_set(p3, p4, par2, size2);
        ans++;
        res.pb(mp(i + 1, j + 1));
      }
    }
  }

  out ans endl;
  for (auto i : res) {
    out i.first << ' ' << i.second endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}