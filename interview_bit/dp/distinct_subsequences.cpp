#include <bits/stdc++.h>
using namespace std;

int numDistinctUtil(string a, string b, int i, int j, vector<vector<int>> &dp) {
  if (j == b.size()) {
    return 1;
  }
  if (i == a.size()) {
    return 0;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  if (a[i] == b[j]) {
    return dp[i][j] = numDistinctUtil(a, b, i + 1, j + 1, dp) +
                      numDistinctUtil(a, b, i + 1, j, dp);
  }
  return dp[i][j] = numDistinctUtil(a, b, i + 1, j, dp);
}

int numDistinct(string a, string b) {
  int n = a.size(), m = b.size();
  vector<vector<int>> dp(n, vector<int>(m, -1));
  return numDistinctUtil(a, b, 0, 0, dp);
}

int main() {
  cout << numDistinct("rabbbit", "rabbit") << endl;
  return 0;
}