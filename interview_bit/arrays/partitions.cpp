#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> arr, int n, int s, int e, int key) {
  while (s <= e) {
    int mid = s + (e - s) / 2;
    if (arr[n - 1] - arr[mid - 1] == key) {
      return mid;
    } else if (arr[n - 1] - arr[mid - 1] > key) {
      s = mid + 1;
    } else {
      e = mid - 1;
    }
  }
  return -1;
}

int solve(int a, vector<int> &b) {
  vector<int> pref(a, 0);
  pref[0] = b[0];
  for (int i = 1; i < a; i++) {
    pref[i] = pref[i - 1] + b[i];
  }

  int ans = 0;
  if (pref[a - 1] % 3 != 0) {
    return ans;
  }

  int sum = pref[a - 1] / 3;
  vector<int> v1, v2;
  if (pref[a - 1] == sum) {
    v2.push_back(0);
  }
  for (int i = 0; i < a; i++) {
    if (pref[i] == sum) {
      v1.push_back(i);
    }
    if (i > 0 && pref[a - 1] - pref[i - 1] == sum) {
      v2.push_back(i);
    }
  }

  for (int i = 0; i < v1.size(); i++) {
    int i1 = lower_bound(v2.begin(), v2.end(), v1[i] + 2) - v2.begin();
    ans += v2.size() - i1;
  }
  return ans;
}

int main() {
  vector<int> b = {1, 2, 3, 0, 3};
  cout << solve(b.size(), b) << endl;
  return 0;
}