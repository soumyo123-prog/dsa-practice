#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> arr, int n, int key, int s, int e) {
  int ans = -1;
  while (s <= e) {
    int mid = s + (e - s) / 2;
    if (arr[mid] <= key) {
      ans = mid;
      s = mid + 1;
    } else {
      e = mid - 1;
    }
  }
  return ans;
}

int solve(vector<int> &a, int b) {
  int n = a.size();
  int idx = 0, ans = 0;
  while (idx < n) {
    int s = max(0, idx - b + 1), e = min(n - 1, idx + b - 1);
    bool flag = false;
    while (e >= s) {
      if (a[e] == 1) {
        idx = e + b;
        flag = true;
        ans++;
        break;
      }
      e--;
    }
    if (!flag) {
      return -1;
    }
  }
  return ans;
}

int main() {
  vector<int> a = {0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1,
                   0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0};
  cout << solve(a, 12) << endl;
  return 0;
}