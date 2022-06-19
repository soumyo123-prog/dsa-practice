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

int numDecodings(string s) {
  int n = s.size();
  if (n == 0) return 0;
  if (s[0] == '0') return 0;

  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  dp[1] = 1;

  for (int i = 2; i <= n; i++) {
    if (s[i - 1] > '0') {
      dp[i] = dp[i - 1];
    }
    if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7')) {
      dp[i] += dp[i - 2];
    }
  }

  return dp[n];
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