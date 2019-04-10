Battle of Pokenom
=================
- https://open.kattis.com/problems/battleofpokenom

#### Tags
- Brute Force

#### Solution
- [c++](battleofpokenom.cpp)

This problem could have many edge cases, and it may become difficult to capture
all of them. However, since `K <= 6` is small, we can use a brute force
approach to try all possible moves.

After a certain point, if all the moves will lead to the victory of a certain
player, then we've found the earliest `s`; given the `s`, we can also find the
minimal `c` by search a position which only has one valid sequence of moves in
the future.
