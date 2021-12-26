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

void printArray(vector<ll> &arr, int n) {
  for (int i = 0; i < n; i++) {
    out arr[i] << " ";
  }
  cout endl;
  return;
}

void solve() {
  int n;
  in n;
  vector<pair<ll, ll>> arr;
  rep(i, 0, n) {
    ll x;
    in x;
    arr.pb(mp(x, i));
  }
  sort(arr.begin(), arr.end());
  reverse(arr.begin(), arr.end());

  vector<ll> ans(n + 1, 0);
  ans[0] = 0;
  ll pos = 1, neg = -1;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      ans[arr[i].second + 1] = pos;
      pos++;
    } else {
      ans[arr[i].second + 1] = neg;
      neg--;
    }
  }

  ll walk = 0;
  for (int i = 0; i < n; i++) {
    walk += 2 * arr[i].first * (abs(ans[arr[i].second + 1]));
  }

  out walk endl;
  printArray(ans, ans.size());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  in t;
  while (t--) {
    solve();
  }

  return 0;
}