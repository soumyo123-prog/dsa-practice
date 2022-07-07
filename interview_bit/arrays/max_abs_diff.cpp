#include <bits/stdc++.h>
using namespace std;

int maxArr(vector<int> &a) {
  int n = a.size();
  int m1 = INT_MAX, m2 = INT_MAX, m3 = INT_MIN, m4 = INT_MIN;
  for (int i = 0; i < n; i++) {
    m1 = min(m1, a[i] + i);
    m3 = max(m3, a[i] + i);
    m2 = min(m2, a[i] - i);
    m4 = max(m4, a[i] - i);
  }
  return max(m3 - m1, m4 - m2);
}

int main() { return 0; }