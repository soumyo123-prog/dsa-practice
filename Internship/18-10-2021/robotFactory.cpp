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

int N, M;
int dp[1001][1001];
bool vis[1001][1001];
int currSize = 0;
vector<int> sizes;

int row[] = {-1, 0, +1, 0};
int col[] = {0, +1, 0, -1};

int fBit[] = {3, 2, 1, 0};
int sBit[] = {1, 0, 3, 2};

bool isValidTransition(int i1, int j1, int i2, int j2, int ind) {
  if (i2 < 0 || i2 >= N || j2 < 0 || j2 >= M) {
    return false;
  }

  int x1 = dp[i1][j1];
  int x2 = dp[i2][j2];

  if ((x1 & (1 << fBit[ind])) || (x2 & (1 << sBit[ind]))) {
    return false;
  }
  return true;
}

void dfsHelper(int i, int j) {
  currSize++;
  vis[i][j] = true;

  for (int k = 0; k < 4; k++) {
    if (isValidTransition(i, j, i + row[k], j + col[k], k) &&
        !vis[i + row[k]][j + col[k]]) {
      dfsHelper(i + row[k], j + col[k]);
    }
  }
}

void dfs() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (!vis[i][j]) {
        dfsHelper(i, j);
        sizes.pb(currSize);
        currSize = 0;
      }
    }
  }

  sort(sizes.begin(), sizes.end());
  reverse(sizes.begin(), sizes.end());
  for (int i = 0; i < sizes.size(); i++) {
    out sizes[i] << ' ';
  }
  cout endl;
}

void solve() {
  int n, m;
  in n >> m;

  N = n;
  M = m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      in dp[i][j];
    }
  }

  dfs();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}