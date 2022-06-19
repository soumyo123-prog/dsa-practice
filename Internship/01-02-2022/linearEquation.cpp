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

int helper(vector<int> coeff, int i, int rhs, vector<vector<int>> &dp) {
  if (i == coeff.size()) {
    if (rhs == 0) {
      return dp[i][0] = 1;
    } else {
      return dp[i][0] = 0;
    }
  }
  if (rhs == 0) {
    return dp[i][0] = 1;
  }
  if (dp[i][rhs] != -1) {
    return dp[i][rhs];
  }

  int mx = rhs / coeff[i], ans = 0;
  for (int j = 0; j <= mx; j++) {
    ans += helper(coeff, i + 1, rhs - j * coeff[i], dp);
  }
  return dp[i][rhs] = ans;
}

int count(vector<int> coeff, int rhs) {
  int n = coeff.size();
  int dp[n + 1][rhs + 1];
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 1;
  }
  for (int i = 1; i <= rhs; i++) {
    dp[0][i] = 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= rhs; j++) {
      dp[i][j] = 0;
      if (rhs - j * coeff[i] >= 0) {
        dp[i][j] += dp[i - 1][rhs - j * coeff[i - 1]];
      }
    }
  }

  return dp[n][rhs];
}

void solve() {
  vector<int> coeff = {1, 3, 5, 7};
  int rhs = 8;
  out count(coeff, rhs) endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();
  return 0;
}