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

using ull = unsigned long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  in t;
  while (t--) {
    int n;
    in n;

    int mod = 1000000007;

    ull ans = 1;
    int i = n + 1;
    while (i <= 2 * n) {
      ans = ans * i % mod;
      i++;
    }

    out ans % mod endl;
  }

  return 0;
}
