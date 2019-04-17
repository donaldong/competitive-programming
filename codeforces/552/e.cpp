#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, k;
  cin >> n >> k;
  vi N(n);
  map<int, int> M;
  set<int> P;
  for (int i = 0; i < n; ++i) {
    cin >> N[i];
    M[N[i]] = i;
    P.insert(i);
  }
  bool f = true;
  while (!M.empty()) {
    auto itr = --M.end();
#ifdef DEBUG
    printf("at %d %d\n", itr->first, itr->second);
#endif
    for (int i = 0; i < k; ++i) {
      auto itr2 = P.upper_bound(itr->second);
      if (itr2 == P.end()) break;
#ifdef DEBUG
      printf("%d: up=%d\n", (int) f, *itr2);
#endif
      M.erase(N[*itr2]);
      if (!f) N[*itr2] *= -1;
      P.erase(itr2);
    }
    for (int i = 0; i < k; ++i) {
      auto itr2 = P.lower_bound(itr->second);
      if (itr2 == P.begin()) break;
      --itr2;
#ifdef DEBUG
      printf("%d: down=%d\n", (int) f, *itr2);
#endif
      M.erase(N[*itr2]);
      if (!f) N[*itr2] *= -1;
      P.erase(itr2);
    }
    if (!f) N[itr->second] *= -1;
    P.erase(itr->second), M.erase(itr), f = !f;
  }
  for (int i = 0; i < n; ++i) cout << (N[i] > 0 ? '1' : '2');
  cout << endl;
  return 0;
}
