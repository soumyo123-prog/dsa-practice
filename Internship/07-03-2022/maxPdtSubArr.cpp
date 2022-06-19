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

int maxProduct(vector<int> &arr) {
  int maxeh = 1, mineh = 1, msf = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] > 0) {
      maxeh = maxeh * arr[i];
      mineh = min(1, mineh * arr[i]);
    } else if (arr[i] < 0) {
      int tmp = maxeh;
      maxeh = max(1, mineh * arr[i]);
      mineh = tmp * arr[i];
    } else {
      maxeh = 1;
      mineh = 1;
    }
    msf = max(msf, maxeh);
  }
  return msf;
}

void solve() {
  vint nums = {2, 6, -2, 4};
  out maxProduct(nums) endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();
  return 0;
}