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

void initialize(vector<ll> &arr, int n) {
  for (int i = 0; i < n; i++) {
    ll x;
    in x;
    arr.pb(x);
  }
  return;
}

void solve() {
  int n;
  in n;
  vector<ll> k, h;
  initialize(k, n);
  initialize(h, n);

  vector<pair<ll, bool>> dam(n, mp(0, false));
  dam[n - 1].first = h[n - 1];
  dam[n - 1].second = true;

  for (int i = n - 2; i >= 0; i--) {
    ll d = dam[i + 1].first, diff = k[i + 1] - k[i];
    if (d <= diff) {
      dam[i].first = h[i];
      dam[i].second = true;
    } else {
      dam[i].first = max(h[i], d - diff);
      dam[i].second = false;
    }
  }

  ll curr = dam[0].first, ans = (curr * (curr + 1)) / 2;
  for (int i = 1; i < n; i++) {
    if (dam[i - 1].second == true) {
      curr = dam[i].first;
      ans += (curr * (curr + 1)) / 2;
    } else {
      ll tmp = curr;
      curr += k[i] - k[i - 1];
      ans += ((curr - tmp) * (curr + tmp + 1)) / 2;
    }
  }

  out ans endl;
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