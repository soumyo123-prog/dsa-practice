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

long long maxPoints(vector<vector<int>>& points) {
  int n = points.size(), m = points[0].size();
  long long dp[n][m];
  for (int i = 0; i < m; i++) {
    dp[0][i] = points[0][i];
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<vector<int>> points = {{1, 5}, {2, 3}, {4, 2}};
  out maxPoints(points) endl;

  return 0;
}