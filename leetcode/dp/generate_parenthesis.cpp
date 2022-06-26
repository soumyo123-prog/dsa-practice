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
    out arr[i] << ' ';
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

void printYesOrNo(bool flag) {
  if (flag) {
    out "YES" endl;
  } else {
    out "NO" endl;
  }
}

bool isBalanced(string s) {
  stack<char> st;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(') {
      st.push(s[i]);
    } else {
      if (!st.empty() && st.top() == '(') {
        st.pop();
      } else {
        return false;
      }
    }
  }
  return st.empty();
}

void genParHelper(int len, string s, vector<string> &arr) {
  if (len == 0) {
    if (isBalanced(s)) arr.push_back(s);
    return;
  }
  genParHelper(len - 1, s + '(', arr);
  genParHelper(len - 1, s + ')', arr);
}

vector<string> generateParenthesis(int n) {
  vector<string> ans;
  genParHelper(2 * n, "", ans);
  return ans;
}

void solve() {
  vector<string> arr = generateParenthesis(8);
  for (string s : arr) {
    out s endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  in t;
  while (t--) {
    solve();
  }
  return 0;
}

// ────────▓▓▓▓▓▓▓────────────▒▒▒▒▒▒
// ──────▓▓▒▒▒▒▒▒▒▓▓────────▒▒░░░░░░▒▒
// ────▓▓▒▒▒▒▒▒▒▒▒▒▒▓▓────▒▒░░░░░░░░░▒▒▒
// ───▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒░░░░░░░░░░░░░░▒
// ──▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░▒
// ──▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░▒
// ─▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░▒
// ▓▓▒▒▒▒▒▒░░░░░░░░░░░▒▒░░▒▒▒▒▒▒▒▒▒▒▒░░░░░░▒
// ▓▓▒▒▒▒▒▒▀▀▀▀▀███▄▄▒▒▒░░░▄▄▄██▀▀▀▀▀░░░░░░▒
// ▓▓▒▒▒▒▒▒▒▄▀████▀███▄▒░▄████▀████▄░░░░░░░▒
// ▓▓▒▒▒▒▒▒█──▀█████▀─▌▒░▐──▀█████▀─█░░░░░░▒
// ▓▓▒▒▒▒▒▒▒▀▄▄▄▄▄▄▄▄▀▒▒░░▀▄▄▄▄▄▄▄▄▀░░░░░░░▒
// ─▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░▒
// ──▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░░▒
// ───▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▀▀░░░░░░░░░░░░░░▒
// ────▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░▒▒
// ─────▓▓▒▒▒▒▒▒▒▒▒▒▄▄▄▄▄▄▄▄▄░░░░░░░░▒▒
// ──────▓▓▒▒▒▒▒▒▒▄▀▀▀▀▀▀▀▀▀▀▀▄░░░░░▒▒
// ───────▓▓▒▒▒▒▒▀▒▒▒▒▒▒░░░░░░░▀░░░▒▒
// ────────▓▓▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░▒▒
// ──────────▓▓▒▒▒▒▒▒▒▒▒░░░░░░░░▒▒
// ───────────▓▓▒▒▒▒▒▒▒▒░░░░░░░▒▒
// ─────────────▓▓▒▒▒▒▒▒░░░░░▒▒
// ───────────────▓▓▒▒▒▒░░░░▒▒
// ────────────────▓▓▒▒▒░░░▒▒
// ──────────────────▓▓▒░▒▒
// ───────────────────▓▒░▒
// ────────────────────▓▒