#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, b, A, s, res = 0;
  cin >> n >> b >> A;
  int a = A;
  while (n--) {
    cin >> s;
    if (a || b) {
      if (s && b && a < A) --b, ++a, ++res;
      else if (s && a == A) --a, ++res;
      else if (!a) --b, ++res;
      else --a, ++res;
    } else break;
  }
  cout << res << endl;
  return 0;
}
