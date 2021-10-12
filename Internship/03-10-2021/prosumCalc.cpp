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

int countNum(vector<int> arr, int x) {
  int ans = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == x) ans++;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  in n;
  vector<int> arr;
  initialize(arr, n);

  int fMax = INT_MIN, sMax = INT_MIN;
  for (int i = 0; i < n; i++) {
    fMax = max(fMax, arr[i]);
  }

  uint64_t cnt = countNum(arr, fMax);
  uint64_t ans = 0;

  if (cnt > 1) {
    ans = (cnt * (cnt - 1)) / 2;
  } else {
    for (int i = 0; i < n; i++) {
      if (arr[i] != fMax) {
        if (arr[i] > sMax) {
          sMax = arr[i];
        }
      }
    }
    uint64_t c = countNum(arr, sMax);
    ans = c;
  }
  out ans endl;
  return 0;
}