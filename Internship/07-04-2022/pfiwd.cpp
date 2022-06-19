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

void initialize(vector<int> &arr, int n) {
  for (int i = 0; i < n; i++) {
    int x;
    in x;
    arr.pb(x);
  }
}

void solve() {
  int n, k;
  in n >> k;
  vint arr;
  initialize(arr, n);
  vint rem;
  rep(i, 0, n) { rem.pb(arr[i] % k); }

  map<int, int> mp;
  rep(i, 0, n) { mp[rem[i]]++; }

  int ans = 0;
  rep(i, 0, n - 1) {
    if (mp[rem[i]] > 0) {
      mp[rem[i]]--;
      int rema = (k - rem[i]) % k;
      if (mp[rema] > 0) {
        ans += 2;
        mp[rema]--;
      } else {
        mp[rem[i]]++;
      }
    }
  }
  out ans endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}