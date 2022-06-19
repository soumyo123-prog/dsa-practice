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

bool isMatch(string s, string p) {
  int n = s.length(), m = p.length();
  bool dp[n + 1][m + 1];
  dp[0][0] = true;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = false;
  }
  bool flag = false;
  for (int i = 1; i <= m; i++) {
    if (p[i - 1] == '?' || (p[i - 1] >= 'a' && p[i - 1] <= 'z')) {
      flag = true;
    }
    if (!flag) {
      dp[0][i] = true;
    } else {
      dp[0][i] = false;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (p[j - 1] == '?') {
        dp[i][j] = dp[i - 1][j - 1];
      } else if (p[j - 1] == '*') {
        dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
      } else {
        if (s[i - 1] == p[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = false;
        }
      }
    }
  }

  return dp[n][m];
}

void solve() {
  string s, p;
  in s >> p;
  out isMatch(s, p) endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();
  return 0;
}