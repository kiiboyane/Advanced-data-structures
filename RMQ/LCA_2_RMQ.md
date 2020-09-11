
##The Farach-Colton and Bender Algorithm

LCA and RMQ are equivalent. 

### Reducing an LCA Problem to RMQ . 
1. Reducing the problem to +/- RMQ : All the adjacent values differ by +/- 1 (Euler tour). 
2. Stores answer of all interva of length power of 2 (O(nlogn) space).
3. Indirection : devide the array into groups of (1/2)*logn length 
4. lookup tables 

