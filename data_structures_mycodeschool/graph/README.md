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
- IntraCity road(weighed, undirected graph)
- InterCity road(weighted, directed graph)

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

### Representation

**Edge List**:

- Time Complexity: 
  - O(|E|) --- > costly, near square of |v^2| in finding adjacent nodes or checking if given nodes are connected
- Space Complexity: 
  - O(|V| + |E|)



**Adjacency Matrix**:

- Time Complexity:

  - Finding adjacent nodes: O(|V|)
  - Checking if two nodes are connected: O(1)

- Space Complexity:

  - O(|V|^2)

- Usage:

  - if graph is dense or |V|^2 is too less to matter



**Adjacency List**:

- Time Complexity:

  - Finding adjacent nodes: O(|V|) {in worst case}
  - Checking if two nodes are connected: O(|V|) {linear search, in worst case}

- Space Complexity:

  - O(|E| + |V|) {|E| << |V|^2 in most graphs}

- Usage:

  - if graph is sparse {social network}
