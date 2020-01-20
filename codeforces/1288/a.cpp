#include <bits/stdc++.h>
using namespace std;

int calc(int x, int d) {
  if (x < 0) return 1e9;
  int r = d % (x + 1) ? 1 : 0;
  return r + d / (x + 1) + x;
}

int dec(unsigned long long x, int d) {
  ++x;
  x *= x;
  if (d == x) return -1;
  return d > x;
}

bool possible(int n, int d) {
  int lo = 0, hi = d - 1, x, r;
  while (lo <= hi) {
    x = (lo + hi) / 2;
    if (calc(x, d) <= n) return true;
    r = dec(x, d);
    if (r < 0) break;
    if (r) lo = x + 1;
    else hi = x - 1;
  }
  return false;
}

int main() {
  int T, n, d;
  cin >> T;
  while (T--) {
    cin >> n >> d;
    printf("%s\n", possible(n, d) ? "YES" : "NO");
  }
  return 0;
}
