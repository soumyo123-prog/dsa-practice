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

int minPathSum(vector<vector<int>> &grid) {
  int n = grid.size(), m = grid[0].size();

  int dp[n][m];
  dp[n - 1][m - 1] = grid[n - 1][m - 1];

  for (int i = m - 2; i >= 0; i--) {
    dp[n - 1][i] = grid[n - 1][i] + dp[n - 1][i + 1];
  }
  for (int i = n - 2; i >= 0; i--) {
    dp[i][m - 1] = grid[i][m - 1] + dp[i + 1][m - 1];
  }

  for (int i = n - 2; i >= 0; i--) {
    for (int j = m - 2; j >= 0; j--) {
      dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
    }
  }

  return dp[0][0];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  out minPathSum(grid) endl;

  return 0;
}