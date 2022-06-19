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

const int MOD = 1e9 + 7;

void initialize(vector<int> &arr, int n) {
  for (int i = 0; i < n; i++) {
    int x;
    in x;
    arr.pb(x);
  }
}

void solve() {
  int n, x;
  in n >> x;
  vint arr;
  initialize(arr, n);

  ll dp[x + 1] = {0};
  dp[0] = 1;

  for (int i = 1; i <= x; i++) {
    for (int j = 0; j < n; j++) {
      if (i - arr[j] >= 0) {
        dp[i] = (dp[i] + dp[i - arr[j]]) % MOD;
      }
    }
  }

  out dp[x] endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}