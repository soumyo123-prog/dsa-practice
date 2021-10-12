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

int findMaxPow(uint64_t x) {
  int ans = 0;
  while (x > 0) {
    x /= 2;
    ans++;
  }
  ans--;
  return ans;
}

uint64_t binpow(uint64_t a, uint64_t b, uint64_t m) {
  a %= m;
  uint64_t res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

void solve() {
  int n, k;
  in n >> k;

  int p = 0, t = k;
  while (t > 0) {
    t /= 2;
    p++;
  }
  p--;

  int m = 1000000007;

  uint64_t x1 = pow(2, p);
  uint64_t a1 = binpow(n, p, m);

  if (k == x1) {
    out a1 endl;
  } else {
    uint64_t diff = k - x1;
    uint64_t temp = diff;

    vector<int> v;

    while (diff > 0) {
      int maxPow = findMaxPow(diff);
      diff -= pow(2, maxPow);
      v.push_back(maxPow);
    }

    uint64_t ans = 0;
    for (int i = 0; i < v.size(); i++) {
      ans = (ans % m + binpow(n, v[i], m)) % m;
    }
    ans = (ans % m + a1 % m) % m;
    out ans endl;
  }
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