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

void solve() {
  int n, r;
  in n >> r;

  float s = 0, e = 1000, PI = 3.14159;
  int err = 1e-6;
  while (s <= e) {
    float mid = s + float(e - s) / 2;
    float a1 = 2 * n * asin(mid / (mid + r)), a2 = 2 * PI;
    if (abs(a1 - a2) <= err) {
      out mid endl;
      break;
    } else if (a1 > a2)
      e = mid - 1;
    else
      s = mid + 1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(10);
  solve();
  return 0;
}