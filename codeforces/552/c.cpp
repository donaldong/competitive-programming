#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

vll N(3);
vll M = {0, 1, 2, 0, 2, 1, 0}; // monday -> sunday

ll solve(int d, ll w) {
  vll R = N;
  int i = 0;
  while (true) {
    if (R[M[d % 7]]) ++i, --R[M[d % 7]], ++d;
    else break;
  }
  return w * 7 + i;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  for (auto &e : N) cin >> e;
  ll res = 0, weeks = min(N[0] / 3, N[1] / 2);
  weeks = min(weeks, N[2] / 2);
  N[0] -= 3 * weeks, N[1] -= 2 * weeks, N[2] -= 2 * weeks;
  for (int i = 0; i < 7; ++i) {
    res = max(res, solve(i, weeks));
  }
  cout << res << endl;
  return 0;
}
