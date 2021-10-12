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
  stack<string> st;
  st.push("");

  int n;
  in n;
  while (n--) {
    int x;
    in x;

    switch (x) {
      case 1: {
        string str;
        in str;
        st.push(st.top() + str);
        break;
      }
      case 2: {
        int k;
        in k;
        st.push(st.top().substr(0, st.top().length() - k));
        break;
      }
      case 3: {
        int k;
        in k;
        out st.top()[k - 1] endl;
        break;
      }
      case 4: {
        st.pop();
        break;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}