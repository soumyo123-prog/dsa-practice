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

int minCut(string s) {
  int n = s.length();

  bool isPal[n][n];
  memset(isPal, false, sizeof(isPal));

  for (int i = 0; i < n; i++) {
    isPal[i][i] = true;
    int l = i - 1, r = i + 1;
    while (l >= 0 && r < n && s[l] == s[r]) {
      isPal[l][r] = true;
      l--;
      r++;
    }
    l = i, r = i + 1;
    while (l >= 0 && r < n && s[l] == s[r]) {
      isPal[l][r] = true;
      l--;
      r++;
    }
    l = i - 1, r = i;
    while (l >= 0 && r < n && s[l] == s[r]) {
      isPal[l][r] = true;
      l--;
      r++;
    }
  }

  int dp[n];
  for (int i = 0; i < n; i++) {
    dp[i] = i;
  }

  for (int i = 0; i < n; i++) {
    for (int j = i; j >= 0; j--) {
      if (isPal[j][i]) {
        if (j > 0) {
          dp[i] = min(dp[i], 1 + dp[j - 1]);
        } else {
          dp[i] = 0;
        }
      }
    }
  }
  return dp[n - 1];
}

void solve() {
  string s;
  in s;
  out minCut(s) endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();
  return 0;
}