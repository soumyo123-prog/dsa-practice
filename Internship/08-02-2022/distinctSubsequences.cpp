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

int numDistinct(string s, string t) {
  const int MOD = 1e9 + 7;
  int n = s.length(), m = t.length();
  int dp[n + 1][m + 1];
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 1;
  }
  for (int i = 1; i <= m; i++) {
    dp[0][i] = 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = (dp[i - 1][j - 1] % MOD + dp[i - 1][j] % MOD) % MOD;
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return dp[n][m];
}

void solve() {
  string s, t;
  in s >> t;
  out numDistinct(s, t) endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();
  return 0;
}