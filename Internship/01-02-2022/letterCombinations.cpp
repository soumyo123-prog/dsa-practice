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

string nums[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void helper(int i, string digits, string ans, vector<string> &res) {
  if (i == digits.length()) {
    res.push_back(ans);
    return;
  }

  string str = nums[(digits[i] - '0') - 2];
  for (int j = 0; j < str.length(); j++) {
    helper(i + 1, digits, ans + str[j], res);
  }
}

vector<string> letterCombinations(string digits) {
  vector<string> ans;
  if (digits.length() == 0) {
    return ans;
  }
  helper(0, digits, "", ans);
  return ans;
}

void solve() {
  string digits;
  in digits;
  vector<string> ans = letterCombinations(digits);
  for (auto i : ans) {
    out i << ' ';
  }
  cout endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}