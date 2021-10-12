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
  int n, x;
  in n >> x;
  vector<int> arr;
  initialize(arr, n);

  vector<int> temp = arr;
  sort(temp.begin(), temp.end());

  string yes = "YES", no = "NO";

  if (temp == arr) {
    out yes endl;
  } else {
    if (x == n) {
      out no endl;
    } else {
      bool ans = true;
      for (int i = 0; i < n; i++) {
        if (temp[i] != arr[i]) {
          int left = i, right = n - 1 - i;
          if (left < x && right < x) {
            ans = false;
            break;
          }
        }
      }
      if (ans) {
        out yes endl;
      } else {
        out no endl;
      }
    }
  }
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