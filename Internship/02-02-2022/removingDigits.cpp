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

void solve() {
  int n;
  in n;
  int dp[n + 1];
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = INT_MAX;
  }

  for (int i = 1; i <= n; i++) {
    int j = i;
    vint arr;
    while (j > 0) {
      arr.pb(j % 10);
      j /= 10;
    }
    for (int k : arr) {
      if (k != 0) {
        dp[i] = min(dp[i], 1 + dp[i - k]);
      }
    }
  }
  out dp[n] endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}