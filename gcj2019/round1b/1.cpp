#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
  int T, p, q, x, y;
  char d;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cin >> p >> q;
    vi N(q + 1, 0);
    vi S = N, W = N, E = N;
    while (p--) {
      cin >> x >> y >> d;
      switch (d) {
        case 'N': N[y + 1] += 1; break;
        case 'S': S[y - 1] += 1; break;
        case 'W': W[x - 1] += 1; break;
        case 'E': E[x + 1] += 1; break;
      }
    }
    for (int i = 1; i <= q; ++i) {
      N[i] += N[i - 1], E[i] += E[i - 1];
    }
    for (int i = q - 1; i >= 0; --i) {
      S[i] += S[i + 1], W[i] += W[i + 1];
    }
    int max_y = 0, max_x = 0;
    for (int i = 0; i <= q; ++i) {
      max_y = max(max_y, N[i] + S[i]);
      max_x = max(max_x, W[i] + E[i]);
    }
    printf("Case #%d: ", t);
    for (int i = 0; i <= q; ++i) if (W[i] + E[i] == max_x) {
      printf("%d ", i);
      break;
    }
    for (int i = 0; i <= q; ++i) if (N[i] + S[i] == max_y) {
      printf("%d\n", i);
      break;
    }
  }
  return 0;
}
