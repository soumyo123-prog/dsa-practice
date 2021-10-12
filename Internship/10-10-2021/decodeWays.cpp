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

int numDecodingsHelp(string s, unordered_map<string, int> &dp) {
  if (s.length() == 1) {
    if (s[0] == '0') {
      dp[s] = 0;
    } else {
      dp[s] = 1;
    }
    return dp[s];
  }
  if (s.length() == 2) {
    if (s[0] == '0') {
      dp[s] = 0;
    } else {
      if (s[1] == '0') {
        dp[s] = 1;
      } else {
        dp[s] = 2;
      }
    }
    return dp[s];
  }
  if (dp.find(s) != dp.end()) {
    return dp[s];
  }
  if (s[0] == 0) {
    dp[s] = 0;
    return 0;
  }
  if (s[1] == 0) {
    dp[s] = numDecodingsHelp(s.substr(2), dp);
    return dp[s];
  }

  int ans = 0;
  ans += numDecodingsHelp(s.substr(2), dp);
  ans += numDecodingsHelp(s.substr(1), dp);
  dp[s] = ans;
  return ans;
}

int numDecodings(string s) {
  unordered_map<string, int> dp;
  return numDecodingsHelp(s, dp);
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