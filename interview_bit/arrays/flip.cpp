#include <bits/stdc++.h>
using namespace std;

vector<int> flip(string a) {
  int n = a.size(), i1 = 0, i2 = 0, i = 0, maxC = 0, c = 0, a1 = -1, a2 = -1;
  while (i < n) {
    if (a[i] == '0') {
      c++;
    } else {
      c--;
    }
    i2 = i;
    if (c > maxC) {
      a1 = i1;
      a2 = i2;
      maxC = c;
    }
    if (c < 0) {
      i1 = i + 1;
      i2 = i + 1;
      c = 0;
    }
    i++;
  }

  vector<int> ans;
  if (a1 != -1 && a2 != -1) {
    ans.push_back(a1 + 1);
    ans.push_back(a2 + 1);
  }
  return ans;
}

int main() {
  string s = "1101";
  vector<int> res = flip(s);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << endl;
  }
  return 0;
}