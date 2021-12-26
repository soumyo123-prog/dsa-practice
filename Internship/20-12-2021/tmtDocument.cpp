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
  return;
}

void printArray(vector<int> &arr, int n) {
  for (int i = 0; i < n; i++) {
    out arr[i] << " ";
  }
  cout endl;
  return;
}

int sumArray(vector<int> &arr, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  return sum;
}

string solve() {
  int n;
  in n;
  string s, yes = "YES", no = "NO";
  in s;

  int k = n / 3;
  vint a1, a2, a3;
  rep(i, 0, n) {
    if (s[i] == 'T') {
      if (a1.size() < k) {
        a1.pb(i);
      } else {
        a3.pb(i);
      }
    } else {
      a2.pb(i);
    }
  }

  if (a1.size() == a2.size() && a2.size() == a3.size() && a3.size() == k) {
    bool flag = true;
    rep(i, 0, k) {
      if (a1[i] < a2[i] && a2[i] < a3[i]) continue;
      flag = false;
      break;
    }
    if (flag) return yes;
  }
  return no;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  in t;
  while (t--) {
    out solve() endl;
  }

  return 0;
}