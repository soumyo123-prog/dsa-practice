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

void printArray(vector<int> &arr, int n) {
  for (int i = 0; i < n; i++) {
    out arr[i] << " ";
  }
  cout endl;
  return;
}

int sumArray(vector<int> &arr, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  return sum;
}

bool isInterleaveHelper(int i, int j, vector<vector<int>> &dp, string s1,
                        string s2, string s3) {
  if (s1.length() == 0 && s2.length() == 0 && s3.length() == 0) {
    return (dp[i][j] = true);
  }

  if (dp[i][j] != -1) {
    return dp[i][j];
  }

  if (s1.length() > 0 && s2.length() > 0) {
    if (s1[0] == s3[0] && s2[0] == s3[0]) {
      return (dp[i][j] = isInterleaveHelper(i + 1, j, dp, s1.substr(1), s2,
                                            s3.substr(1)) ||
                         isInterleaveHelper(i, j + 1, dp, s1, s2.substr(1),
                                            s3.substr(1)));
    }
    if (s1[0] == s3[0]) {
      return (dp[i][j] = isInterleaveHelper(i + 1, j, dp, s1.substr(1), s2,
                                            s3.substr(1)));
    }
    if (s2[0] == s3[0]) {
      return (dp[i][j] = isInterleaveHelper(i, j + 1, dp, s1, s2.substr(1),
                                            s3.substr(1)));
    }
  } else {
    if (s1.length() > 0 && s1[0] == s3[0]) {
      return (dp[i][j] = isInterleaveHelper(i + 1, j, dp, s1.substr(1), s2,
                                            s3.substr(1)));
    }
    if (s2.length() > 0 && s2[0] == s3[0]) {
      return (dp[i][j] = isInterleaveHelper(i, j + 1, dp, s1, s2.substr(1),
                                            s3.substr(1)));
    }
  }
  return (dp[i][j] = false);
}

bool isInterleave(string s1, string s2, string s3) {
  if (s1.length() + s2.length() != s3.length()) {
    return false;
  }

  int m = s1.length(), n = s2.length();
  vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
  dp[0][0] = true;
  for (int i = 1; i <= m; i++) {
    if (s1[i - 1] == s3[i - 1]) {
      dp[i][0] = true;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (s2[i - 1] == s3[i - 1]) {
      dp[0][i] = true;
    }
  }

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      int k = i + j - 2;
      if (s1[i - 1] == s3[k] && s2[j - 1] == s3[k]) {
        dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
      } else {
        if (s1[i - 1] == s3[k]) {
          dp[i][j] = dp[i - 1][j];
        } else if (s2[j - 1] == s3[k]) {
          dp[i][j] = dp[i][j - 1];
        }
      }
    }
  }

  return dp[m - 1][n - 1];
}

void solve() {
  string s1, s2, s3;
  in s1 >> s2 >> s3;
  out isInterleave(s1, s2, s3) endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}