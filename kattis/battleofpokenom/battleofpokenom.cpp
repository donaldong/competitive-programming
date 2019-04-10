#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

bool count(vi &S, int n, int k, int &a, int &b, int end) { // count the bits in `n`, if it is valid
  for (int i = 0; i <= k; ++i) {
    if ((n & (1 << i)) != (S[i] << i)) return false; // locked bits do not match
    if (S[i]) {
      if (i & 1) ++b;
      else ++a;
    }
  }
  for (int i = k + 1; i < end; ++i) {
    if (n & (1 << i)) {
      if (i & 1) ++b;
      else ++a;
    }
  }
  return true;
}

bool fixed(vi &S, int n) {
  int A = 0, B = 0, tie = 0, tot = 1 << S.size();
  for (int i = 0; i < tot; ++i) {
    int a = 0, b = 0;
    if (!count(S, i, n, a, b, S.size())) continue;
    if (a == b) return false; // it's fixed at position n only if we can ensure one player always win
    if (a > b) ++A;
    else ++B;
    if (A && B) return false; // both players have won. nope.
  }
  return true;
}

bool solve(vi &S, int c, int s, int A, int B) {
  int a, b, tot = 1 << s, k = 0;
  for (int i = 0; i < tot; ++i) { // 0 -> c is fixed, searching c -> s by brute force 
    a = b = 0;
    if (!count(S, i, c, a, b, s)) continue;
    if (a != A || b != B) continue;
    vi _S = S;
    int b = i;
    for (int j = 0; j < s; ++j) {
      _S[j] = b & 1;
      b >>= 1;
    }
    bool invalid = false;
    for (int j = 0; j + 1 < s; ++j) {
      if (fixed(_S, j)) { // found a new fix point before current fix point (S)
        invalid = true;
        break;
      }
    }
    if (invalid) continue;
    if (k) return false;
    ++k;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int K;
    cin >> K;
    vi S(2 * K);
    for (int i = 0; i < S.size(); ++i) {
      char c;
      cin >> c;
      S[i] = c == 'E';
    }
    int s, c, a = 0, b = 0;
    for (s = 0; s < S.size(); ++s) if (fixed(S, s)) {
      ++s;
      break;
    }
    for (int i = 0; i < s; ++i) if (S[i]) {
      if (i & 1) ++b;
      else ++a;
    }
    for (c = 0; c <= s; ++c) if (solve(S, c - 1, s, a, b)) break;
    printf("%d %d\n", s, c);
  }
  return 0;
}
