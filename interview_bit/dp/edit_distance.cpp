#include <bits/stdc++.h>
using namespace std;

int minDistance(string a, string b) {
  int n = a.length(), m = b.length();
  int dp[n + 1][m + 1];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = max(i, j);
      } else {
        if (a[i - 1] == b[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
        }
      }
    }
  }
  return dp[n][m];
}

int main() { return 0; }