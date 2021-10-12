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

int bin_s(vector<int> arr, int x) {
  int e = arr.size() - 1, s = 0;
  int ans = -1;
  while (s <= e) {
    int mid = (s + e) / 2;
    if (arr[mid] == x) {
      return mid;
    } else if (arr[mid] < x) {
      ans = mid;
      s = mid + 1;
    } else {
      e = mid - 1;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, h;
  in n >> h;
  vector<int> arr;
  initialize(arr, n);

  sort(arr.begin(), arr.end());

  long long sum = 0, maxSum = 0, diff = 0;
  int p1 = 0, p2 = 0;
  while (p1 <= p2 && p2 < n) {
    sum += arr[p2];
    diff = arr[p2] - arr[p1];
    if (diff > h) {
      sum -= arr[p1];
      p1++;
    } else {
      maxSum = max(maxSum, sum);
      p2++;
    }
  }

  maxSum = max(maxSum, sum);
  out maxSum endl;

  return 0;
}