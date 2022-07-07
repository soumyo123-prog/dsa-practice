#include <bits/stdc++.h>
using namespace std;

vector<int> findPerm(const string s, int n) {
  vector<int> aux;
  int num = 0, minEl = num;
  aux.push_back(num);
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == 'I') {
      num++;
    } else {
      num--;
    }
    aux.push_back(num);
    minEl = min(minEl, num);
  }
  int diff = 1 - minEl;
  for (int i = 0; i < n; i++) {
    aux[i] += diff;
  }
  return aux;
}

int main() { return 0; }