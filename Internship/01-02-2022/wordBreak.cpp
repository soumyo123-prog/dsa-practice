#include <bits/stdc++.h>
using namespace std;

#define endl << "\n"
#define in cin >>
#define out cout <<
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pint;
typedef vector<vector<int>> vvint;
typedef vector<int> vint;
typedef vector<pair<int, int>> vpint;
typedef vector<char> vchar;
typedef vector<string> vstring;
typedef map<int, int> mint;
typedef set<int> sint;

bool helper(map<string, pair<bool, int>> &dp, string s) {
  if (dp[s].second == 1) return dp[s].first;
  if (s.length() == 1) return false;

  for (int i = 1; i < s.length(); i++) {
    string s1 = s.substr(0, i), s2 = s.substr(i);

    bool a1 = dp[s1].first;
    bool a2;
    if (a1) {
      if (dp[s2].second == 1) {
        a2 = dp[s2].first;
      } else {
        a2 = helper(dp, s2);
      }
    } else {
      a2 = false;
    }

    dp[s].second = 1;
    dp[s].first = dp[s].first || (a1 && a2);
  }

  return dp[s].first;
}

bool wordBreak(string s, vector<string> dict) {
  map<string, pair<bool, int>> dp;
  for (int i = 0; i < dict.size(); i++) {
    dp[dict[i]] = make_pair(true, 1);
  }
  helper(dp, s);
  return dp[s].first;
}

void solve() {
  vector<string> dict = {"l", "e", "e", "t", "cod", "e"};
  string s = "leetcode";
  out wordBreak(s, dict) endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}