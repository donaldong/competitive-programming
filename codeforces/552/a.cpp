#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  vi nums(4);
  for (int i = 0; i < 4; ++i) cin >> nums[i];
  sort(nums.begin(), nums.end());
  printf("%d %d %d\n", nums[3] - nums[2], nums[3] - nums[1], nums[3] - nums[0]);
  return 0;
}
