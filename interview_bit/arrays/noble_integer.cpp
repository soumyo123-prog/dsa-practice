#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a) {
  sort(a.begin(), a.end());
  for (int i = 0; i < a.size() - 1; i++) {
    if (a[i] == a[i + 1]) {
      continue;
    }
    if (a.size() - i - 1 == a[i]) {
      return 1;
    }
  }
  if (*a.rbegin() == 0) {
    return 1;
  }
  return -1;
}

int main() { return 0; }