## Tree(Non-linear)

### Concept

- root, child, parent
- Sibling: same parent
- Cousin: same grandparent
- Leaf: has no child
- ancestor, descendent
- Traversal: process of visiting each node in the tree exactly once in some order

### Property

- **N** nodes
- **N - 1** edges (one incoming edge for each node except the root)
- **Depth**: number of edges from root to the node
- **Height**: number of edges in longest path from node to a leaf
- **Height of tree with 1 node**: 0
- **Height of an empty tree**: -1
- **Height of tree**: height of root node
- **Binary tree**: a tree in which each node can have **at most 2** children
- **Strict/Proper binary tree**: each node can have **either 2 or 0** children
- **Complete binary tree**: all levels except possibly the last are completely filled and all nodes are as left as possible
- **Maximum number of nodes at level i**: 2^i
- **Perfect binary tree**: a complete binary tree in which all levels are full
- **Maximum number of nodes in a tree with height h**: 2^(h+1) - 1
- **Height of complete binary tree with N nodes**: floor(logN)
- **Balanced binary tree**: difference between height of left and right subtree for every node is not more than k (mostly 1)

### ADT

Traversal strategies: **breadth-first** and **depth-first**

Breadth-first: **Level-order**

Depth-first: **Pre-order**, **In-order**, **Post-order**

### Application

- Storing naturally hierarchical data (eg: file system)
- Organize data for quick search, insertion, deletion (eg: binary search tree)
- Trie (eg: dictionary)
- Network routing algorithm

------



## Binary Search Tree

### ADT

- Insert --- O(logn)
- Search --- O(logn)
- Remove --- O(logn)

### Comparison

|           | Array | LinkedList | Array(sorted) | BST(balanced) |
| :-------: | :---: | :--------: | :-----------: | :-----------: |
| Search(x) | O(n)  |    O(n)    |    O(logn)    |    O(logn)    |
| Insert(x) | O(1)  |    O(1)    |     O(n)      |    O(logn)    |
| Remove(x) | O(n)  |    O(n)    |     O(n)      |    O(logn)    |

### Concept

A binary tree in which for each node, value of all the nodes in left subtree is lesser or equal and value of all the nodes in right subtree is greater.
