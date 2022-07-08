#include <bits/stdc++.h>
using namespace std;

vector<int> wave(vector<int> &a) {
  sort(a.begin(), a.end());
  for (int i = 0; i < a.size() - 1; i += 2) {
    int tmp = a[i];
    a[i] = a[i + 1];
    a[i + 1] = tmp;
  }
  return a;
}

int main() { return 0; }