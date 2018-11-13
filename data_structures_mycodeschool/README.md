## Introduction to data structures

A data structure is a way to store and organize data in a computer, 
so that it can be used efficiently.

we will talk about data structures as:

* Mathematical/Logical models or Abstract Data Type (ADT)
* Concrete Implementation

## List

### ADT

- Empty list has size 0
- Insert --- O(n) | Add --- O(n)
- Remove --- O(n)
- Count --- O(1)
- Read/Modify element at a position --- O(1)
- Specify data type

### Implementation

#### Array

If list is **full of array**, create a larger array of **double size of the previous array** and copy all the elements from the previous array into the new array, then free the memory for the previous array.

#### LinkedList

Get the address of the first node and treasure hunt.

#### Comparison

|                      |        Array        |                      LinkedList                       |
| :------------------: | :-----------------: | :---------------------------------------------------: |
|  Cost of accessing  |        O(1)         |                         O(n)                          |
| Memory requiremenets |     Fixed size      | No unused memory need memory for pointer var |
|  Cost of inserting  | O(n)/O(1);O(n)/O(n) |  O(1)/O(n)/O(n)(position at beginning, end, middle)   |
|Easy to use|Yes|No|

#### Doubly LinkedList

Linked list can be divided to two types: singly linked list and doubly linked list.

Advantages: Reverse look-up.

Disadvantages: Extra memory for pointer to previous node.

#### Circular LinkedList

------



## Stack(LIFO)

### ADT

A list with the restriction that insertion and deletion can be performed **only from one end**, called the top.

- Push --- O(1)
- Pop --- O(1)
- Top --- O(1)
- IsEmpty --- O(1)

### Implementation

#### Array

#### LinkedList

Implement stack by using **insert at the beginning** of linked list.

### Application

- Reverse a string or linkedlist
- Parenthesis balanced checked
- Infix Postfix Prefix

------



## Queue(FIFO)

### ADT

A list or collection with the restriction that **insertion can be performed at one end (rear)**, and deletion **can be performed at other end (front)**.

- Enqueue --- O(1)
- Dequeue --- O(1)
- Front --- O(1)
- IsEmpty --- O(1)

### Implementation

#### Array

- circular array
- front and rear (tail)

#### LinkedList

tail pointer to the last node


### Application

- Printer queue
- Process scheduling
- simulating wait

------



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

### Implementation

#### Array(used for heap)

#### LinkedList(dynamically created nodes)

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

------



## Graph(Non-linear)

### Concept

A graph G is an ordered pair of a set V of vertices and a set E of edges. **G = (V, E)**, this is a ordered pair.

**Two** types of graphs:

- A directed graph or **digraph**
- An undirected graph

And

- A weighted graph
- An unweighted graph

**Examples**:

- Social network (unweighted, undirected graph)
- Web page(unweighted, directed graph)
- IntroCity road(weighed, undirected graph)
- IntraCity road(weighted, directed graph)

### Property

- |V|: number of vertices
- |E|: number of edges
- **Walk**: a sequence of vertices where each adjacent pair is connected by an edge
- **closed walk**: starts and ends at same vertex
- **simple circle**: no repetition other than start and end
- **acyclic graph**: a graph with no cycle
- **Path**: a **walk** in which no vertices (and thus no edges) are repeated
- **Trail**: a **walk** in which no edges are repeated
- **Self loop**: if it involves only 1 vertex
- **Multiedge** or Paralle edge: if it occurs more than once in a graph
- **Strong connected** graphs: if there is path from any vertex to any other vertex

Number of edges in a simple graph(no self loop or multiedge):

if |V| = n, then:

- 0 <= |E| <= n(n - 1), if **directed**
- 0 <= |E| <= n(n - 1) / 2, if **undirected** 
- **Dense** -> too many edges
- **Sparse** -> few edges