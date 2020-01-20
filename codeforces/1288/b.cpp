#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main() {
  int t, a, b;
  ull res;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    res = log10(b + 1);
    printf("%lld\n", res * a);
  }
  return 0;
}
