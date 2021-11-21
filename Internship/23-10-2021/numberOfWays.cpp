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

vector<long long> suff(vector<int> arr, int n) {
  vector<long long> ans(n, 0);
  ans[n - 1] = arr[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    ans[i] = arr[i] + ans[i + 1];
  }
  return ans;
}

void solve() {
  int n;
  in n;
  vector<int> arr;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    int x;
    in x;
    arr.pb(x);
    sum += arr[i];
  }

  if (sum % 3 != 0) {
    out 0 endl;
  } else {
    vector<long long> suf = suff(arr, n);

    vector<long long> helper(n, 0);
    if (suf[n - 1] * 3 == sum) {
      helper[n - 1] += 1;
    }
    for (int i = n - 2; i >= 0; i--) {
      if (suf[i] * 3 == sum) {
        helper[i] += helper[i + 1] + 1;
      } else {
        helper[i] += helper[i + 1];
      }
    }

    int s = 0, i = 0;
    long long ans = 0;
    for (i = 0; i <= n - 3; i++) {
      s += arr[i];
      if (s * 3 == sum) {
        ans += helper[i + 2];
      }
    }

    out ans endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}