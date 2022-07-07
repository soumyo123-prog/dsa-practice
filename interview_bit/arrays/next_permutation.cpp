#include <bits/stdc++.h>
using namespace std;

void swapElements(vector<int> &arr, int i, int j) {
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

vector<int> nextPermutation(vector<int> &a) {
  int n = a.size(), idx = n;
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] < a[i + 1]) {
      idx = i;
      break;
    }
  }

  if (idx == n) {
    reverse(a.begin(), a.end());
    return a;
  }

  int idxNg = idx + 1;
  for (int i = idxNg; i < n; i++) {
    if (a[i] > a[idx] && a[i] < a[idxNg]) {
      idxNg = i;
    }
  }
  swapElements(a, idx, idxNg);
  reverse(a.begin() + idx + 1, a.end());
  return a;
}

int main() {
  vector<int> a = {769, 533};
  nextPermutation(a);
  return 0;
}