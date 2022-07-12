#include <bits/stdc++.h>
using namespace std;

int row[] = {-1, 0, 1, 0};
int col[] = {0, 1, 0, -1};

bool isValid(int x, int y, int n, int m) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(queue<pair<int, int>> &q, vector<vector<bool>> &vis,
         vector<vector<int>> &adj) {
  int n = adj.size(), m = adj[0].size();
  while (!q.empty()) {
    pair<int, int> curr = q.front();
    q.pop();
    vis[curr.first][curr.second] = true;
    for (int i = 0; i < 4; i++) {
      int x = curr.first + row[i], y = curr.second + col[i];
      if (isValid(x, y, n, m) && !vis[x][y] &&
          adj[x][y] >= adj[curr.first][curr.second]) {
        q.push(make_pair(x, y));
        vis[x][y] = true;
      }
    }
  }
}

int solve(vector<vector<int>> &adj) {
  int n = adj.size(), m = adj[0].size(), ans = 0;

  vector<vector<bool>> blue(n, vector<bool>(m, false));
  vector<vector<bool>> red(n, vector<bool>(m, false));

  queue<pair<int, int>> q1, q2;
  for (int i = 0; i < m; i++) {
    q1.push({0, i});
    q2.push({n - 1, i});
  }
  for (int j = 0; j < n - 1; j++) {
    q1.push({j + 1, 0});
    q2.push({j, m - 1});
  }

  bfs(q1, blue, adj);
  bfs(q2, red, adj);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (red[i][j] && blue[i][j]) {
        ans++;
      }
    }
  }

  return ans;
}

int main() {
  vector<vector<int>> adj = {
      {1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1},
      {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4},
  };
  cout << solve(adj) << endl;
  return 0;
}

//  [1, 2, 2, 3, 5]
//  [3, 2, 3, 4, 4]
//  [2, 4, 5, 3, 1]
//  [6, 7, 1, 4, 5]
//  [5, 1, 1, 2, 4]