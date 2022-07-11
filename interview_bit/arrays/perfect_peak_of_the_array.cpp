#include <bits/stdc++.h>
using namespace std;

int perfectPeak(vector<int> &a) {
  int n = a.size();
  int leftMax[n];
  leftMax[0] = a[0];

  for (int i = 1; i < n; i++) {
    leftMax[i] = max(leftMax[i - 1], a[i - 1]);
  }

  int rightMin = INT_MAX;
  for (int i = n - 1; i >= 0; i--) {
    if (leftMax[i] < a[i] && rightMin > a[i]) {
      return 1;
    }
    rightMin = min(rightMin, a[i]);
  }

  return 0;
}

int main() { return 0; }