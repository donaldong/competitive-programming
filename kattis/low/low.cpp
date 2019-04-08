#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi P;
int N, K;

bool possible(int d) {
  int n = 1, i = 2;
  while (n < N && i + 1 < P.size() && i <= 2 * n * K) {
    if (P[i + 1] - P[i] <= d) ++n, i += 2;
    else ++i;
  }
  return n == N;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> N >> K;
  P.resize(2 * N * K);
  for (auto &e : P) cin >> e;
  sort(P.begin(), P.end());
  int lo = P[1] - P[0], hi = 1e9;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (possible(mid)) hi = mid;
    else lo = mid + 1;
  }
  printf("%d\n", hi);
  return 0;
}
