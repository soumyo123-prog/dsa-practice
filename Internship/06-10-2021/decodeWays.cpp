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

int numDecodings(string s) {
  int n = s.length();

  if (n == 1) {
    if (s[0] == '0') {
      return 0;
    }
    return 1;
  }

  if (n == 2) {
    int st = stoi(s);
    if (s[0] == '0') {
      return 0;
    }
    if (s[1] == '0') {
      if (st >= 30) {
        return 0;
      }
      return 1;
    }
    if (st > 26) {
      return 1;
    }
    return 2;
  }

  int dp[n + 1];
  for (int i = 0; i <= n; i++) {
    dp[i] = 0;
  }
  if (s[n - 1] != '0') {
    dp[n - 1] = 1;
  }
  bool noAns = false;

  for (int i = n - 2; i >= 0; i--) {
    if (s[i] == '0') {
      continue;
    }

    int st = stoi(s.substr(i, 2));
    if (s[i + 1] == '0') {
      if (st >= 30) {
        noAns = true;
        break;
      } else {
        dp[i] = dp[i + 2];
      }
    } else {
      if (st > 26) {
        dp[i] = dp[i + 1];
      } else {
        dp[i] = 2 + dp[i + 2];
      }
    }
  }
  if (noAns) {
    return 0;
  }
  return dp[0];
}

void solve() {
  string s;
  in s;
  out numDecodings(s) endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}