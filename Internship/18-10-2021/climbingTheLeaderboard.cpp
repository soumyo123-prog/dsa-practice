#include <bits/stdc++.h>
using namespace std;

#define endl << "\n"
#define in cin >>
#define out cout <<
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vvi vector<vector<int>>
#define vi vector<int>

void initialize(vector<int> &arr, int n) {
  for (int i = 0; i < n; i++) {
    int x;
    in x;
    arr.pb(x);
  }
  return;
}

void printArray(vector<int> &arr, int n) {
  for (int i = 0; i < n; i++) {
    out arr[i] endl;
  }
  return;
}

void solve() {
  int n;
  in n;
  vector<int> ran;
  for (int i = 0; i < n; i++) {
    int x;
    in x;
    if (i == 0) {
      ran.pb(x);
    } else {
      if (x < *ran.rbegin()) {
        ran.pb(x);
      }
    }
  }

  int m;
  in m;
  vector<int> scr;
  initialize(scr, m);

  reverse(ran.begin(), ran.end());
  vector<int> res;

  int lci = 0;
  int ind = 0;
  while (ind < m) {
    while (lci < n && scr[ind] >= ran[lci]) {
      lci++;
    }
    if (lci < n) {
      res.pb(ran.size() - lci + 1);
    } else {
      res.pb(1);
    }
    ind++;
  }

  printArray(res, res.size());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}