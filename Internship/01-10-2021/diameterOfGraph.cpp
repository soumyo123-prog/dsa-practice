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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  in t;
  while (t--) {
    uint64_t n, m, k;
    in n >> m >> k;

    uint64_t maxEdges = n * (n - 1) / 2;
    uint64_t minEdges = n - 1;

    string ans, yes = "YES", no = "NO";

    if (m == 0) {
      if (n == 1) {
        if (k >= 2) {
          ans = yes;
        } else {
          ans = no;
        }
      } else {
        ans = no;
      }
    } else {
      if (m > maxEdges || m < minEdges) {
        ans = no;
      } else {
        if (m == minEdges) {
          if (m == 1 && k >= 3) {
            ans = yes;
          } else if (m >= 2 && k >= 4) {
            ans = yes;
          } else {
            ans = no;
          }
        } else if (m == maxEdges) {
          if (k >= 3) {
            ans = yes;
          } else {
            ans = no;
          }
        } else {
          if (k >= 4) {
            ans = yes;
          } else {
            ans = no;
          }
        }
      }
    }
    out ans endl;
  }
  return 0;
}