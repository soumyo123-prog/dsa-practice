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

void initialize(vector<int> &arr, int n) {
  for (int i = 0; i < n; i++) {
    int x;
    in x;
    arr.pb(x);
  }
  return;
}

void solve() {
  int n;
  in n;
  vector<int> arr;
  initialize(arr, n);

  int dp[n + 1][n + 1];
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[0][i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    dp[i][0] = 0;
  }

  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= j; i++) {
      if (dp[i - 1][j - 1] + arr[i - 1] > 0) {
        dp[i][j] = max(dp[i - 1][j - 1] + arr[i - 1], dp[i - 1][j]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  int ans = 0;
  for (int i = n; i >= 1; i--) {
    if (dp[i][n] >= 0) {
      ans = i;
      break;
    }
  }
  out ans endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}