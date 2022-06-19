#include <bits/stdc++.h>
using namespace std;

#define endl << "\n"
#define in cin >>
#define out cout <<
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pint;
typedef vector<vector<int>> vvint;
typedef vector<int> vint;
typedef vector<pair<int, int>> vpint;
typedef vector<char> vchar;
typedef vector<string> vstring;
typedef map<int, int> mint;
typedef set<int> sint;

vector<int> leftSmaller(vector<int> ht) {
  vector<int> res;
  stack<int> st;
  for (int i = 0; i < ht.size(); i++) {
    while (!st.empty() && ht[st.top()] >= ht[i]) {
      st.pop();
    }
    if (st.empty()) {
      res.push_back(-1);
    } else {
      res.push_back(st.top());
    }
    st.push(i);
  }
  return res;
}

vector<int> rightSmaller(vector<int> ht) {
  vector<int> res(ht.size(), ht.size());
  stack<int> st;
  for (int i = ht.size() - 1; i >= 0; i--) {
    while (!st.empty() && ht[st.top()] >= ht[i]) {
      st.pop();
    }
    if (!st.empty()) {
      res[i] = st.top();
    }
    st.push(i);
  }
  return res;
}

int maximalArea(vector<int> ht) {
  int n = ht.size();
  vector<int> left = leftSmaller(ht), right = rightSmaller(ht);
  int maxArea = 0;
  for (int i = 0; i < n; i++) {
    int h = ht[i], b = right[i] - left[i] - 1;
    maxArea = max(maxArea, b * h);
  }
  return maxArea;
}

int maximalRectangle(vector<vector<char>> mat) {
  int n = mat.size(), m = mat[0].size();
  vector<int> bp(m, -1);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    vector<int> ht;
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == '0') {
        bp[j] = i;
      }
      ht.push_back(i - bp[j]);
    }
    ans = max(ans, maximalArea(ht));
  }

  return ans;
}

void solve() {
  vector<vector<char>> mat = {{'0'}};
  out maximalRectangle(mat) endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();
  return 0;
}