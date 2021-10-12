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

bool isSubsetSum(int n, int arr[], int sum) {
  bool dp[n + 1][sum + 1];
  dp[0][0] = 1;

  for (int i = 1; i <= n; i++) {
    dp[i][0] = 1;
  }
  for (int i = 1; i <= sum; i++) {
    dp[0][i] = 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sum; j++) {
      if (j - arr[i - 1] >= 0) {
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  return dp[n][sum];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  in n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    in arr[i];
  }
  int sum;
  in sum;

  out isSubsetSum(n, arr, sum) endl;

  return 0;
}