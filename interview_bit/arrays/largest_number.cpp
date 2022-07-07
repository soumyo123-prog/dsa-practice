#include <bits/stdc++.h>
using namespace std;

bool comp(string a, string b) { return (b + a >= a + b); }

string largestNumber(vector<int> &a) {
  int n = a.size();
  vector<string> aux(n, "");
  for (int i = 0; i < n; i++) {
    vector<int> t1;
    int t2 = a[i];
    while (t2 > 0) {
      t1.push_back(t2 % 10);
      t2 /= 10;
    }
    for (int j = t1.size() - 1; j >= 0; j--) {
      aux[i] += t1[j] + '0';
    }
  }
  sort(aux.begin(), aux.end(), comp);
  string ans = "";
  for (int i = n - 1; i >= 0; i--) {
    ans += aux[i];
  }
  if (ans == "") {
    ans = "0";
  }
  return ans;
}

int main() {
  vector<int> a = {3, 30, 34, 5, 9};
  cout << largestNumber(a) << endl;
  return 0;
}