#include <bits/stdc++.h>
using namespace std;

void seg(vector<int> &a, int n) {
  int i1 = 0, i2 = n - 1;
  while (a[i1] <= 0) {
    i1++;
  }
  while (a[i2] > 0) {
    i2--;
  }
  while (i1 < i2) {
    swap(a[i1], a[i2]);
    do {
      i1++;
    } while (a[i1] <= 0);
    do {
      i2--;
    } while (a[i2] > 0);
  }
}

int firstMissingPositive(vector<int> &a) {
  int n = a.size();
  seg(a, n);
  reverse(a.begin(), a.end());

  int sz = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > 0) {
      sz++;
    } else {
      break;
    }
  }

  for (int i = 0; i < sz; i++) {
    if (abs(a[i]) <= sz && a[abs(a[i]) - 1] > 0) {
      a[abs(a[i]) - 1] = -a[abs(a[i]) - 1];
    }
  }

  for (int i = 0; i < sz; i++) {
    if (a[i] > 0) {
      return i + 1;
    }
  }

  return sz + 1;
}

int main() {
  vector<int> a = {1, 2, 0, -1, -3, 5, 4, 3, -9, 0, 8};
  cout << firstMissingPositive(a) << endl;
  return 0;
}