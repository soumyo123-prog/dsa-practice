#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &a) {
  int n = a.size();
  vector<int> a1, a2;
  for (int i = 0; i < n; i++) {
    if (a[i] >= 0) {
      a1.push_back(a[i]);
    } else {
      a2.push_back(-a[i]);
    }
  }
  reverse(a2.begin(), a2.end());

  int i1 = 0, i2 = 0, i = 0;
  while (i1 < a1.size() && i2 < a2.size()) {
    if (a1[i1] < a2[i2]) {
      a[i++] = a1[i1++];
    } else {
      a[i++] = a2[i2++];
    }
  }
  while (i1 < a1.size()) {
    a[i++] = a1[i1++];
  }
  while (i2 < a2.size()) {
    a[i++] = a2[i2++];
  }

  for (i = 0; i < a.size(); i++) {
    a[i] *= a[i];
  }
  return a;
}

int main() { return 0; }