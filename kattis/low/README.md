Low Power
=========
- https://open.kattis.com/problems/low

#### Tags
- Greedy
- Binary Search

#### Solution
- [c++](low.cpp)

Given the maximum differences among the chips, we can see if it's possible to
have N groups using the differences.

If we sort the batteries, we know there's no way to do better (forming chips)
than picking two consecutive elements since those two elements would be the two
minimums (aka the power of the chips). If the difference <= the maximum
differences, we can use them to power a machine.

if we can power `N` machines, then we can use the differences. So we can
perform a binary search to find the minimum max differences.
