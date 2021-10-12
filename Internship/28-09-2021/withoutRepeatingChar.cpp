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

int lengthOfLongestSubstring(string s) {
  int n = s.length();

  map<char, int> fi;
  for (int i = n - 1; i >= 0; i--) {
    fi[s[i]] = i;
  }

  map<char, int> mp;
  int base = -1;
  int ltn = 0;

  for (int i = 0; i < n; i++) {
    if (fi[s[i]] < base) {
      fi[s[i]] = i;
      if (mp[s[i]] > 0) {
        mp[s[i]]--;
      }
    }

    mp[s[i]]++;
    if (mp[s[i]] > 1) {
      ltn = max(ltn, i - base - 1);
      base = fi[s[i]];
      fi[s[i]] = i;
      mp[s[i]]--;
    } else if (i == n - 1) {
      ltn = max(ltn, i - base);
    }
  }

  return ltn;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  in s;
  out lengthOfLongestSubstring(s) endl;

  return 0;
}