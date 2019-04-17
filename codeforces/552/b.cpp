#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int solve(vi &N) {
  if (N.size() >= 4) return -1;
  if (N.size() == 1) return 0;
  if (N.size() == 2) {
    int d = N[1] - N[0];
    if (d & 1) return d;
    return d / 2;
  }
  int d1 = N[1] - N[0], d2 = N[2] - N[1];
  if (d1 == d2) return d1;
  return -1;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  vi N(n);
  for (auto &e : N) cin >> e;
  sort(N.begin(), N.end());
  auto end = unique(N.begin(), N.end());
  N.erase(end, N.end());
  cout << solve(N) << endl;
  return 0;
}
