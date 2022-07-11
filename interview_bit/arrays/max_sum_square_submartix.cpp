#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &a, int b) {
  int n = a.size(), maxSum = INT_MIN;
  if (b == 1) {
    maxSum = max(maxSum, a[0][0]);
  }
  for (int i = 1; i < n; i++) {
    a[0][i] += a[0][i - 1];
    a[i][0] += a[i - 1][0];
    if (b == 1) {
      maxSum = max(maxSum, a[0][i] - a[0][i - 1]);
      maxSum = max(maxSum, a[i][0] - a[i - 1][0]);
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      a[i][j] = a[i][j - 1] + a[i][j] + a[i - 1][j] - a[i - 1][j - 1];
      if (i >= b - 1 && j >= b - 1) {
        int v1 = 0, v2 = 0, v3 = 0;
        if (j - b >= 0) {
          v1 = a[i][j - b];
        }
        if (i - b >= 0) {
          v2 = a[i - b][j];
        }
        if (i >= b && j >= b) {
          v3 = a[i - b][j - b];
        }
        maxSum = max(maxSum, a[i][j] - v1 - v2 + v3);
      }
    }
  }
  return maxSum;
}

int main() {
  vector<vector<int>> a = {{1, 1, 1, 1, 1},
                           {2, 2, 2, 2, 2},
                           {3, 8, 6, 7, 3},
                           {4, 4, 4, 4, 4},
                           {5, 5, 5, 5, 5}};
  cout << solve(a, 1) << endl;
  return 0;
}