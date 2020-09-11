
## The Heap Property 

### min heap 
the parent of any non-root node has a smaller value than the node itself meaning the smallest value is in the root.  

### max heap
the parent of any non-root node has a greater value than the node itself meaning the greatest value is in the root.

### What is a Heap ? 
a heap is a specialized tree-based data structure which is essentially an almost complete tree that satisfies the **heap property**.

## in-order tree Traversal

In-order (LNR) : 
1. Left tree.
2. current Node.
3. Right tree.


## Cartesian Tree 

Cartesian tree is a binary tree derived from a sequence of numbers. 
it has to be check the following three conditions : 
- It is a min heap 
- There is a node for each number in the sequence . 
- A symmetric (in-order) traversal of the tree results in the original sequence.


### Turning an array to a Cartesian Tree  

 8 | 9 | 6 | 2 | 4 | 5 | 3 | 7 | 

![Cartesian Tree](https://github.com/kiiboyane/Advanced-data-structures/blob/master/RMQ/min_heap.png) 

> An LCA in the cartesian tree is equivilent to the RMQ in the array . 
