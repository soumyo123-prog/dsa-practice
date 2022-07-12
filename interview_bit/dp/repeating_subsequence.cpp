#include <bits/stdc++.h>
using namespace std;

int anytwo(string a) {
  int n = a.size(), dp[n + 1][n + 1];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      } else {
        if (a[i - 1] == a[j - 1] && i != j) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
  }
  return dp[n][n] >= 2 ? dp[n][n] : 0;
}

int main() { return 0; }