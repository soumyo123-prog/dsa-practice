#include <bits/stdc++.h>
using namespace std;

bool hotel(vector<int> &arrive, vector<int> &depart, int k) {
  vector<pair<int, int>> arr;
  for (int i = 0; i < arrive.size(); i++) {
    arr.push_back(make_pair(arrive[i], 0));
    arr.push_back(make_pair(depart[i], 1));
  }
  sort(arr.begin(), arr.end());

  int maxRooms = 0, currRooms = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i].second == 0) {
      currRooms++;
      maxRooms = max(currRooms, maxRooms);
    } else {
      currRooms--;
    }
  }

  return k >= maxRooms;
}

int main() {
  vector<int> arrive = {1, 2, 3}, depart = {2, 3, 4};
  cout << hotel(arrive, depart, 1) << endl;
  return 0;
}