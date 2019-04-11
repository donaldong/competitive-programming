Safe Passage
============
- https://open.kattis.com/problems/safepassage

#### Tags
- DP
- Dijkstra

#### Solution
- [c++](safepassage.cpp)

We can treat this problem as a single source shortest path problem. Each state
is representted by `N` bits, 0 if the person is still here, or 1 if the person
reaches the other side. Then we can use Dijkstra's algorithm to find the
minimum cost for the final state (`N` x `1`).
