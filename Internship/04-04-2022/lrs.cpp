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

void initialize(vector<int> &arr, int n) {
  for (int i = 0; i < n; i++) {
    int x;
    in x;
    arr.pb(x);
  }
}

void printArray(vector<int> &arr, int n) {
  for (int i = 0; i < n; i++) {
    out arr[i] << " ";
  }
  cout endl;
}

int sumArray(vector<int> &arr, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  return sum;
}

/* Finds the length of the longest repeating subsequence */
int findLRSLength(string s) {
  int n = s.length();

  int dp[n + 1][n + 1];
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int i = 1; i <= n; i++) {
    dp[0][i] = 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (s[i - 1] == s[j - 1] && i != j) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }
    }
  }

  return dp[n][n];
}

void solve() { out findLRSLength("ATACTCGGA") endl; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}