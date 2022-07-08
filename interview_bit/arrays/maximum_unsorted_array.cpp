#include <bits/stdc++.h>
using namespace std;

vector<int> subUnsort(vector<int> &a) {
  vector<int> t = a, result;
  sort(t.begin(), t.end());

  if (t == a) {
    result.push_back(-1);
    return result;
  }

  int i1 = 0, i2 = t.size() - 1, n = t.size();
  while (i1 < n && a[i1] == t[i1]) {
    i1++;
  }
  while (i2 >= 0 && a[i2] == t[i2]) {
    i2--;
  }
  result.push_back(i1);
  result.push_back(i2);
  return result;
}

int main() {
  vector<int> a = {1, 3, 2, 4, 5};
  vector<int> res = subUnsort(a);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << ' ';
  }
  cout << endl;
  return 0;
}