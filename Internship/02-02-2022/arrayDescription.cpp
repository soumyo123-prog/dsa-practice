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

void initialize(vector<int> &arr, int n) {
  for (int i = 0; i < n; i++) {
    int x;
    in x;
    arr.pb(x);
  }
}

void solve() {
  int n, m;
  in n >> m;
  vint arr;
  initialize(arr, n);

  int dp[n][m + 1];
  if (arr[0] == 0) {
    for (int i = 1; i <= m; i++) {
      dp[0][i] = 1;
    }
  } else {
    for (int i = 1; i <= m; i++) {
      if (i == arr[0]) {
        dp[0][i] = 1;
      } else {
        dp[0][i] = 0;
      }
    }
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      if (arr[i] == 0 || arr[i] == j) {
        dp[i][j] = dp[i - 1][j];
        if (j >= 2) {
          dp[i][j] += dp[i - 1][j - 1];
        }
        if (j <= m - 1) {
          dp[i][j] += dp[i - 1][j + 1];
        }
      } else {
        dp[i][j] = 0;
      }
    }
  }

  out dp[n - 1][arr[n - 1]] endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}