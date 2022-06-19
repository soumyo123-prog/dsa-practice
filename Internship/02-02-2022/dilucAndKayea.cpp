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
  string s;
  in s;

  double cd = 0, ck = 0;
  vector<pair<double, int>> slp;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'D') {
      cd++;
    } else {
      ck++;
    }
    if (ck == 0) {
      slp.pb(mp(INT_MAX, i));
    } else {
      slp.pb(mp(cd / ck, i));
    }
  }
  sort(slp.begin(), slp.end());

  int ans[n];
  ans[slp[0].second] = 1;
  for (int i = 1; i < n; i++) {
    if (slp[i].first == slp[i - 1].first) {
      ans[slp[i].second] = ans[slp[i - 1].second] + 1;
    } else {
      ans[slp[i].second] = 1;
    }
  }

  for (int i = 0; i < n; i++) {
    out ans[i] << ' ';
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