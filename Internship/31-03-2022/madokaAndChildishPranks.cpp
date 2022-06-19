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

void solve() {
  int n, m;
  in n >> m;

  vvint arr(n, vint(m, 0));
  rep(i, 0, n) {
    string s;
    in s;
    rep(j, 0, s.length()) { arr[i][j] = s[j] - '0'; }
  }

  if (arr[0][0] == 0) {
    vvint ans;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        if (arr[i][j] == 1) {
          if (i > 0) {
            ans.pb({i, j + 1, i + 1, j + 1});
          } else {
            ans.pb({i + 1, j, i + 1, j + 1});
          }
        }
      }
    }
    out ans.size() endl;
    rep(i, 0, ans.size()) {
      rep(j, 0, ans[i].size()) { out ans[i][j] << ' '; }
      cout endl;
    }
  } else {
    out - 1 endl;
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