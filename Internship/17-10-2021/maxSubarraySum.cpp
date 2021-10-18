#include <bits/stdc++.h>
using namespace std;

#define endl << "\n"
#define in cin >>
#define out cout <<
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vvi vector<vector<int>>
#define vi vector<int>

void solve() {
  int n, m;
  in n >> m;
  vector<uint64_t> arr;
  for (int i = 0; i < n; i++) {
    uint64_t x;
    in x;
    arr.pb(x);
  }

  set<uint64_t> st;
  st.insert(arr[0] % m);
  uint64_t ans = arr[0] % m, sum = arr[0] % m;

  for (int i = 1; i < n; i++) {
    uint64_t ta;
    sum = (sum + arr[i]) % m;
    st.insert(sum);
    if (st.upper_bound(sum) != st.end()) {
      ta = (sum - *st.upper_bound(sum) + m) % m;
      ans = max(ans, ta);
    } else {
      ans = max(ans, sum);
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