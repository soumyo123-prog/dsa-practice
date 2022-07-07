#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a) {
  int m1 = a[0], m2 = a[0];
  for (int i = 1; i < a.size(); i++) {
    m1 = min(m1, a[i]);
    m2 = max(m2, a[i]);
  }
  return m1 + m2;
}

int main() { return 0; }