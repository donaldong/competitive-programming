Buying Coke
===========
- https://open.kattis.com/problems/coke

#### Tags
- DP
- State Compression

#### Solution
- [c++](coke.cpp)

This problem has a clear recurrence relation. However, the naive DP approach
would have too many different states (`C * n1 * n5 * n10 = 375000000`). Also,
the number of states is bigger than this number since we can have more coins of
a certain type.

The key observation is the possible state transition (valid ways of
consuming/collecting different types of coins):
1. We can use `1` x `n10` and `3` x `n1` to get a `n5`.
2. We can use `1` x `n10` to get `2` x `n1`.
3. We can use `2` x `n5` to get `2` x `n1`.
4. We can use `1` x `n5` and `3` x `n1`.
If we run out of coins, since we know we have enough coins, to begin with, we
know we can still buy all the cokes by using `n1`s.
