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
  int n;
  char c;
  string s;
  in n >> c;
  in s;

  bool all = true;
  for (int i = 0; i < n; i++) {
    if (s[i] != c) {
      all = false;
      break;
    }
  }

  if (all) {
    out 0 endl;
  } else {
    if (s[n - 1] == c) {
      out 1 endl;
      out n endl;
    } else {
      vector<int> v1, v2;
      for (int i = 0; i < n; i++) {
        if (s[i] == c) {
          v1.pb(i + 1);
        } else {
          v2.pb(i + 1);
        }
      }

      int canDec = false;
      int ans = 2, x1 = n, x2 = n - 1;
      for (int i = 0; i < v1.size(); i++) {
        if (v1[i] == 1) {
          continue;
        }
        int t = v1[i] * 2;
        if (t > v2[v2.size() - 1]) {
          canDec = true;
          ans = 1;
          x1 = v1[i];
          break;
        }
      }

      out ans endl;
      if (canDec) {
        out x1 endl;
      } else {
        out x1 << ' ' << x2 endl;
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