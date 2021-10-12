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

void printArray(vector<int> &arr, int n) {
  for (int i = 0; i < n; i++) {
    out arr[i] endl;
  }
}

void solve() {
  int n, m;
  map<string, int> m1;
  vector<int> res;

  in n;
  for (int i = 0; i < n; i++) {
    string x;
    in x;
    m1[x]++;
  }

  in m;
  for (int i = 0; i < m; i++) {
    string x;
    in x;
    res.pb(m1[x]);
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