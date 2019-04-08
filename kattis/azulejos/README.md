Azulejos
========
- https://open.kattis.com/problems/azulejos
#### Tags
- Greedy

#### Solution
- [c++](azulejos.cpp)
Sort the prices and break the ties using a greedy strategy: matching a front
row tile with the shortest back row tile which is still tall enough. We're
matching ties in two groups, each group has the same price. It's only possible
if the smaller group can have a full match.
