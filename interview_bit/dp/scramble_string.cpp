#include <bits/stdc++.h>
using namespace std;

int isScrambleUtil(string a, string b, map<pair<string, string>, int> &dp) {
  if (a == b) {
    return dp[make_pair(a, b)] = 1;
  }

  auto it = dp.find(make_pair(a, b));
  if (it != dp.end()) {
    return it->second;
  }

  string s1 = a, s2 = b;
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  if (s1 != s2) {
    return 0;
  }

  for (int i = 0; i < a.size() - 1; i++) {
    if (isScrambleUtil(a.substr(0, i + 1), b.substr(0, i + 1), dp) == 1 &&
        isScrambleUtil(a.substr(i + 1), b.substr(i + 1), dp) == 1) {
      return dp[make_pair(a, b)] = 1;
    }
    if (isScrambleUtil(a.substr(a.size() - i - 1, i + 1), b.substr(0, i + 1),
                       dp) == 1 &&
        isScrambleUtil(a.substr(0, a.size() - i - 1), b.substr(i + 1), dp)) {
      return dp[make_pair(a, b)] = 1;
    }
  }
  return dp[make_pair(a, b)] = 0;
}

int isScramble(const string a, const string b) {
  map<pair<string, string>, int> dp;
  return isScrambleUtil(a, b, dp);
}

int main() {
  cout << isScramble("phqtrnilf", "ilthnqrpf") << endl;
  return 0;
}