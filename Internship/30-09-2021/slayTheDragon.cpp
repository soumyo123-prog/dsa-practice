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

typedef unsigned long long ull;

ull initialize(vector<ull> &arr, int n) {
  ull sum = 0;
  for (int i = 0; i < n; i++) {
    ull x;
    in x;
    arr.pb(x);
    sum += x;
  }
  return sum;
}

ull just_smaller(vector<ull> arr, ull x) {
  int s = 0, e = arr.size() - 1;
  ull ans = 0;
  while (s <= e) {
    int mid = (s + e) / 2;
    if (arr[mid] > x) {
      e = mid - 1;
    } else if (arr[mid] <= x) {
      ans = arr[mid];
      s = mid + 1;
    }
  }
  return ans;
}

ull just_greater(vector<ull> arr, ull x) {
  int s = 0, e = arr.size() - 1;
  ull ans = 0;
  while (s <= e) {
    int mid = (s + e) / 2;
    if (arr[mid] >= x) {
      ans = arr[mid];
      e = mid - 1;
    } else if (arr[mid] < x) {
      s = mid + 1;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  in n;
  vector<ull> arr;
  ull sum = initialize(arr, n);
  sort(arr.begin(), arr.end());

  int m;
  in m;
  vector<pair<ull, ull>> drg;
  for (int i = 0; i < m; i++) {
    ull x, y;
    in x >> y;
    drg.pb(mp(x, y));
  }

  for (int i = 0; i < m; i++) {
    ull ans = 0;
    ull js = just_smaller(arr, drg[i].first);
    ull jg = just_greater(arr, drg[i].first);

    ull a1 = ULLONG_MAX, a2 = ULLONG_MAX;

    if (js != 0) {
      a1 = drg[i].first - js;
      ull remStr1 = sum - js;
      if (remStr1 < drg[i].second) {
        a1 += drg[i].second - remStr1;
      }
    }

    if (jg != 0) {
      a2 = 0;
      ull remStr2 = sum - jg;
      if (remStr2 < drg[i].second) {
        a2 += drg[i].second - remStr2;
      }
    }

    ans += min(a1, a2);
    out ans endl;
  }
  return 0;
}