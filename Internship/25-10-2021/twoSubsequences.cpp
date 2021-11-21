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

void solve() {
  string s;
  in s;

  bool arr[26] = {false};
  for (int i = 0; i < s.length(); i++) {
    arr[s[i] - 'a'] = true;
  }

  int i;
  for (i = 0; i < 26; i++) {
    if (arr[i]) break;
  }

  out char(i + 'a') << ' ';

  bool taken = false;
  for (int j = 0; j < s.length(); j++) {
    if (s[j] == char(i + 'a') && !taken) {
      taken = true;
    } else {
      out s[j];
    }
  }

  cout endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  in t;
  while (t--) {
    solve();
  }

  return 0;
}