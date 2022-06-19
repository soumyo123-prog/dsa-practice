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
  vpint arr, temp;
  rep(i, 0, n) {
    int x;
    in x;
    arr.pb(mp(x, i));
  }
  temp = arr;
  sort(arr.begin(), arr.end());

  vector<ll> pref;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i].first;
    pref.pb(sum);
  }

  int ind = 1, ans = n - 1;
  for (int i = 0; i < n - 1; i++) {
    if (ind <= i) ind = i + 1;
    ll tmp = pref[i] + (pref[ind - 1] - pref[i]);
    while (ind < n && tmp >= arr[ind].first) {
      tmp += arr[ind].first;
      ind++;
    }
    if (ind == n) {
      ans = i;
      break;
    }
  }

  out n - ans endl;
  while (ans < n) {
    out temp[ans].second + 1 << ' ';
    ans++;
  }
  cout endl;
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