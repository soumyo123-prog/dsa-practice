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

void initialize(vector<int> &arr, int n) {
  for (int i = 0; i < n; i++) {
    int x;
    in x;
    arr.pb(x);
  }
  return;
}

long long sumArray(vector<int> &arr, int n) {
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  return sum;
}

void solve() {
  int n;
  in n;
  vector<int> arr;
  initialize(arr, n);

  long long sum = sumArray(arr, n);
  if ((2 * sum) % n != 0) {
    out 0 endl;
  } else {
    long long ans = 0;
    int s = (2 * sum) / n;

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      mp[arr[i]]++;
    }

    for (int i = 0; i < n; i++) {
      int req = s - arr[i];
      if (req >= arr[i]) {
        mp[arr[i]]--;
        ans += mp[req];
      }
    }

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