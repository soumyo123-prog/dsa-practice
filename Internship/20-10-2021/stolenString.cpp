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

  int c1[m] = {0};
  vector<pair<int, int>> cnt;
  vector<string> v1;

  for (int i = 0; i < n; i++) {
    string s;
    in s;
    v1.pb(s);
    for (int j = 0; j < m; j++) {
      c1[j] += int(s[j]);
    }
  }
  for (int i = 0; i < n - 1; i++) {
    string s;
    in s;
    for (int j = 0; j < m; j++) {
      c1[j] -= int(s[j]);
    }
  }

  string ans = "";
  for (int i = 0; i < m; i++) {
    ans += char(c1[i]);
  }

  out ans endl;
  out flush;
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