# PA MIDTERM PREPARATION


## Agenda
* DP

Monede [description](#monede)

CMLSC [description](#cmlsc)

DP1 [description](#dp1)

DP2 [description](#dp2)

Knapsack [description](#knapsack) |  [Java code](#knapsack-1)

Matrix Chain Multiplication [description](#matrix-chain-multiplication) |  [Java code](#matrix-chain-multiplication-1)

* Graphs

BFS [description](#bfs) |  [Java code](#bfs-1)

DFS [description](#dfs) |  [Java code](#dfs-1)

Topological Sort [description](#topological-sort) |  [Java code](#topological-sort-khan)

SSC Tarjan [description](#scc-tarjan) |  [Java code](#scc-tarjan-1)

CV Tarjan [description](#cv-tarjan) |  [Java code](#cv-tarjan-1)

CE Tarjan [description](#ce-tarjan) |  [Java code](#ce-tarjan-1)

BCC [description](#bcc) |  [Java code](#bcc-1)

Dijkstra [description](#dijkstra) |  [Java code](#dijkstra-1)

Bellman - Ford [description](#bellman---ford) |  [Java code](#bellman---ford-1)

Floyd - Warshall [description](#floyd---warshall) |  [Java code](#floyd---warshall-1)

Johnson [description](#johnson) |  [Java code](#johnson-1)


## Labs
Lab 03
* Task1 - Monede
* Task2 - CMLSC

Lab 04
* Task1 - DP1
* Task2 - DP2

Lab 06
* ???

Lab 07
* Task1 - SCC
* Task2 - CV
* Task3 - CE
* Task4 - BCC

Lab 08
* Task1 - Dijkstra
* Task2 - Rebuild Path
* Task3 - Bellman - Ford

Lab 09
* Task1 - Floyd - Warshall
* Task2 - Johnson

## Descriptions
### CMLSC
Fie doi vectori cu numere intregi: v cu n elemente si w cu m elemente. Sa se gaseasca cel mai lung subsir comun (notat CMLSC) care apare in cei doi vectori. Se cere o solutie de complexitate optima. Daca exista mai multe solutii, se poate gasi oricare.

### Monede
Gigel are o colectie impresionanta de monede. El ne spune ca are n tipuri de monede, avand un numar nelimitat de monede din fiecare tip. Cunoscand aceasta informatie (data sub forma unui vector v cu n elemente), el se intreaba care este numarul minim de monede cu care poate plati o suma S.
### DP1
Fie un șir de numere naturale strict pozitive. Câte subșiruri (submulțimi nevide) au suma numerelor pară?

### DP2
Se dă o expresie booleană corectă cu n termeni. Fiecare din termeni poate fi unul din stringurile true, false, and, or, xor.

Numărați modurile în care se pot așeza paranteze astfel încât rezultatul să fie true. Se respectă regulile de la logică (tabelele de adevăr pentru operațiile and, or, xor).
### Matrix Chain Multiplication
Given the dimension of a sequence of matrices in an array arr[], where the dimension of the ith matrix is (arr[i-1] * arr[i]), the task is to find the most efficient way to multiply these matrices together such that the total number of element multiplications is minimum.
### Knapsack
Given N items where each item has some weight and profit associated with it and also given a bag with capacity W, [i.e., the bag can hold at most W weight in it]. The task is to put the items into the bag such that the sum of profits associated with them is the maximum possible.
### BFS
Breadth First Search (BFS) is a fundamental graph traversal algorithm. It involves visiting all the connected nodes of a graph in a level-by-level manner. 
### DFS
Depth First Traversal (or Search) for a graph is similar to Depth First Traversal (DFS) of a tree. The only catch here is, unlike trees, graphs may contain cycles, so a node might be visited twice. To avoid processing a node more than once, use a boolean visited array. 
### Topological Sort
Topological Sorted order: It is a linear ordering of vertices such that for every directed edge u -> v, where vertex u comes before v in the ordering.
### SCC Tarjan
A component is said to be strongly connected (SCC) if every vertex is reachable from every other vertex (in a ***directed*** graph). We will use a variation of the Tarjan's algorithm but Kosaraju's could also be used. 

 Time complexity: O(n + m)

### CV Tarjan
Cut Vertex (nod critic) is a vertex which, if removed (or "cut")--together with any incident edges-- disconnects the graph (***undirected***).

 Time complexity: O(n + m)

### CE Tarjan
An edge of an ***undirected*** graph whose deletion increases the graph's number of connected components.

 Time complexity: O(n + m)

### BCC
A biconnected graph (***undirected***) is a connected and "nonseparable" graph, meaning that if any one vertex were to be removed, the graph will remain connected. Therefore a biconnected graph has no articulation vertices (cut vertex).

 Time complexity: O(n + m)

### Dijkstra
 Dijkstra's algorithm finds the shortest path from one vertex to all other vertices. Costs must be ***positive***.

 Time complexity: O(E * log(V))

### Bellman - Ford
 Computes shortest paths from a single source vertex to all of the other vertices in a weighted oriented graph. Costs can be ***negative***. It also detects a negative cost cycle.

 Time complexity: O(E * V)
### Floyd - Warshall
 It is used to find the shortest paths between all pairs of nodes in a weighted graph. Can handle graphs with both positive and negative edge weights, making it a versatile tool for solving a wide range of network and connectivity problems. It's better suited for ***dense*** graphs. Costs must be ***positive***.

 Time complexity: O(V^3)

### Johnson
 Find the shortest paths between every pair of vertices in a given weighted directed Graph and weights may be ***negative***. It's better suited for ***sparse*** graphs.

 Time complexity: O(V * E * log(V))

## DP
### Matrix Chain Multiplication
```java
    // Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
    static int MatrixChainOrder(int p[], int n)
    {
        /* For simplicity of the 
        program, one extra row and
        one extra column are allocated in m[][].  0th row
        and 0th column of m[][] are not used */
        int m[][] = new int[n][n];
 
        int i, j, k, L, q;
 
        /* m[i, j] = Minimum number of scalar
        multiplications needed to compute the matrix
        A[i]A[i+1]...A[j] = A[i..j] where
        dimension of A[i] is p[i-1] x p[i] */
 
        // cost is zero when multiplying one matrix.
        for (i = 1; i < n; i++)
            m[i][i] = 0;
 
        // L is chain length.
        for (L = 2; L < n; L++) 
        {
            for (i = 1; i < n - L + 1; i++) 
            {
                j = i + L - 1;
                if (j == n)
                    continue;
                m[i][j] = Integer.MAX_VALUE;
                for (k = i; k <= j - 1; k++) 
                {
                    // q = cost/scalar multiplications
                    q = m[i][k] + m[k + 1][j]
                        + p[i - 1] * p[k] * p[j];
                    if (q < m[i][j])
                        m[i][j] = q;
                }
            }
        }
 
        return m[1][n - 1];
    }
```
### Knapsack
#### Matrix

```java
static int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[][] = new int[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w]
                    = max(val[i - 1]
                                + K[i - 1][w - wt[i - 1]],
                            K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

// Usage
knapSack(W, weight, profit, n);
```
#### Recursive

```java
// Returns the value of maximum profit
static int knapSackRec(int W, int wt[], int val[],
                        int n, int[][] dp)
{

    // Base condition
    if (n == 0 || W == 0)
        return 0;

    if (dp[n][W] != -1)
        return dp[n][W];

    if (wt[n - 1] > W)

        // Store the value of function call
        // stack in table before return
        return dp[n][W]
            = knapSackRec(W, wt, val, n - 1, dp);

    else

        // Return value of table after storing
        return dp[n][W]
            = max((val[n - 1]
                    + knapSackRec(W - wt[n - 1], wt, val,
                                    n - 1, dp)),
                    knapSackRec(W, wt, val, n - 1, dp));
}
static int knapSack(int W, int wt[], int val[], int N)
{

    // Declare the table dynamically
    int dp[][] = new int[N + 1][W + 1];

    // Loop to initially filled the
    // table with -1
    for (int i = 0; i < N + 1; i++)
        for (int j = 0; j < W + 1; j++)
            dp[i][j] = -1;

    return knapSackRec(W, wt, val, N, dp);
}

// Usage
knapSack(W, weight, profit, n);
```

#### Single row

```java
static int knapSack(int W, int wt[], int val[], int n)
{
    // Making and initializing dp array
    int[] dp = new int[W + 1];

    for (int i = 1; i < n + 1; i++) {
        for (int w = W; w >= 0; w--) {

            if (wt[i - 1] <= w)

                // Finding the maximum value
                dp[w]
                    = Math.max(dp[w], dp[w - wt[i - 1]]
                                            + val[i - 1]);
        }
    }
    // Returning the maximum value of knapsack
    return dp[W];
}

// Usage
knapSack(W, weight, profit, n);
```

## Graphs
### BFS
```java
void bfs(int startNode)
{
    // Create a queue for BFS
    Queue<Integer> queue = new LinkedList<>();
    boolean[] visited = new boolean[vertices];

    // Mark the current node as visited and enqueue it
    visited[startNode] = true;
    queue.add(startNode);

    // Iterate over the queue
    while (!queue.isEmpty()) {
        // Dequeue a vertex from queue and print it
        int currentNode = queue.poll();
        System.out.print(currentNode + " ");

        // Get all adjacent vertices of the dequeued
        // vertex currentNode If an adjacent has not
        // been visited, then mark it visited and
        // enqueue it
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.add(neighbor);
            }
        }
    }
}
```
### DFS
#### Recursive
```java
void DFSUtil(int v, boolean visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    System.out.print(v + " ");

    // Recur for all the vertices adjacent to this
    // vertex
    Iterator<Integer> i = adj[v].listIterator();
    while (i.hasNext()) {
        int n = i.next();
        if (!visited[n])
            DFSUtil(n, visited);
    }
}

// The function to do DFS traversal.
// It uses recursive DFSUtil()
void DFS(int v)
{
    // Mark all the vertices as
    // not visited(set as
    // false by default in java)
    boolean visited[] = new boolean[V];

    // Call the recursive helper
    // function to print DFS
    // traversal
    DFSUtil(v, visited);
}
```
#### Iterative
```java
void DFS(int s)
{
    // Initially mark all vertices as not visited
    Vector<Boolean> visited = new Vector<Boolean>(V);
    for (int i = 0; i < V; i++)
        visited.add(false);

    // Create a stack for DFS
    Stack<Integer> stack = new Stack<>();
        
    // Push the current source node
    stack.push(s);
        
    while(stack.empty() == false)
    {
        // Pop a vertex from stack and print it
        s = stack.peek();
        stack.pop();
            
        // Stack may contain same vertex twice. So
        // we need to print the popped item only
        // if it is not visited.
        if(visited.get(s) == false)
        {
            System.out.print(s + " ");
            visited.set(s, true);
        }
            
        // Get all adjacent vertices of the popped vertex s
        // If a adjacent has not been visited, then push it
        // to the stack.
        Iterator<Integer> itr = adj[s].iterator();
            
        while (itr.hasNext()) 
        {
            int v = itr.next();
            if(!visited.get(v))
                stack.push(v);
        }
            
    }
}
```
### Topological Sort (Khan)
```java
topologicalSort(List<List<Integer> > adj, int V)
{
    // Vector to store indegree of each vertex
    int[] indegree = new int[V];
    for (List<Integer> list : adj) {
        for (int vertex : list) {
            indegree[vertex]++;
        }
    }

    // Queue to store vertices with indegree 0
    Queue<Integer> q = new LinkedList<>();
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.add(i);
        }
    }
    List<Integer> result = new ArrayList<>();
    while (!q.isEmpty()) {
        int node = q.poll();
        result.add(node);
        // Decrease indegree of adjacent vertices as the
        // current node is in topological order
        for (int adjacent : adj.get(node)) {
            indegree[adjacent]--;
            // If indegree becomes 0, push it to the
            // queue
            if (indegree[adjacent] == 0)
                q.add(adjacent);
        }
    }

    // Check for cycle
    if (result.size() != V) {
        System.out.println("Graph contains cycle!");
        return new ArrayList<>();
    }
    return result;
}
```
### SCC Tarjan
### CV Tarjan
### CE Tarjan
### BCC
For all of these only dfs is changed a little

Graph is represented as:
```java
ArrayList<Integer> adj[]
```
```java
private ArrayList<ArrayList<Integer>> tarjan_bcc() {
    // STEP 1: initialize results
    parent = new int[n + 1];
    found = new int[n + 1];
    low_link = new int[n + 1];

    Arrays.fill(parent, -1);
    Arrays.fill(found, -1);
    Arrays.fill(low_link, -1);

    // STEP 2: visit all nodes
    ArrayList<ArrayList<Integer>> all_bccs = new ArrayList<>();
    timestamp = 0;
    for (int node = 1; node <= n; ++node) {
        if (parent[node] == -1) { // node not visited
            parent[node] = node; // convention: the parent of the root is actually the root

            // STEP 3: start a new DFS traversal this subtree
            dfs(node, all_bccs);
        }
    }

    return all_bccs;
}
```
### Dijkstra
Graph is represented as:
```java
ArrayList<Pair> adj[];
```
```java
public class DijkstraResult {
    List<Integer> d;
    List<Integer> p;

    DijkstraResult(List<Integer> _d, List<Integer> _p) {
        d = _d;
        p = _p;
    }
};

public class Pair implements Comparable<Pair> {
    public int destination;
    public int cost;

    Pair(int _destination, int _cost) {
        destination = _destination;
        cost = _cost;
    }

    public int compareTo(Pair rhs) {
        return Integer.compare(cost, rhs.cost);
    }
}
```
```java
private DijkstraResult dijkstra(int source, int nodes, ArrayList<Pair> adj[]) {
    List<Integer> d = new ArrayList<>();
    List<Integer> p = new ArrayList<>();

    // Initializam distantele la infinit
    for (int node = 0; node <= nodes; node++) {
        d.add(INF);
        p.add(0);
    }

    // Folosim un priority queue de Pair, desi elementele noastre nu sunt tocmai
    // muchii.
    // Vom folosi field-ul de cost ca si distanta pana la nodul respectiv.
    // Observati ca am modificat clasa Pair ca sa implementeze interfata Comparable.
    PriorityQueue<Pair> pq = new PriorityQueue<>();

    // Inseram nodul de plecare in pq si ii setam distanta la 0.
    d.set(source, 0);
    pq.add(new Pair(source, 0));

    // Cat timp inca avem noduri de procesat
    while (!pq.isEmpty()) {
        // Scoatem head-ul cozii
        int cost = pq.peek().cost;
        int node = pq.poll().destination;

        // In cazul in care un nod e introdus in coada cu mai multe distante (pentru ca
        // distanta pana la el se imbunatateste in timp), vrem sa procesam doar
        // versiunea sa cu distanta minima. Astfel, dam discard la intrarile din coada
        // care nu au distanta optima.
        if (cost > d.get(node)) {
            continue;
        }

        // Ii parcurgem toti vecinii.
        for (var e : adj[node]) {
            int neigh = e.destination;
            int w = e.cost;

            // Se imbunatateste distanta?
            if (d.get(node) + w < d.get(neigh)) {
                // Actualizam distanta si parintele.
                d.set(neigh, d.get(node) + w);
                p.set(neigh, node);
                pq.add(new Pair(neigh, d.get(neigh)));
            }
        }
    }

    // Toate nodurile ce au distanta INF nu pot fi atinse din sursa, asa ca setam
    // distantele
    // pe -1.
    for (int i = 1; i <= n; i++)
        if (d.get(i) == INF)
            d.set(i, -1);

    return new DijkstraResult(d, p);
}
```
From geeksforgeeks
```java
int minDistance(int dist[], Boolean sptSet[])
{
    // Initialize min value
    int min = Integer.MAX_VALUE, min_index = -1;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }

    return min_index;
}
// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int graph[][], int src)
{
    int dist[] = new int[V]; // The output array.
                                // dist[i] will hold
    // the shortest distance from src to i

    // sptSet[i] will true if vertex i is included in
    // shortest path tree or shortest distance from src
    // to i is finalized
    Boolean sptSet[] = new Boolean[V];

    // Initialize all distances as INFINITE and stpSet[]
    // as false
    for (int i = 0; i < V; i++) {
        dist[i] = Integer.MAX_VALUE;
        sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set
        // of vertices not yet processed. u is always
        // equal to src in first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of
        // the picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] != 0
                && dist[u] != Integer.MAX_VALUE
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

}
```
### Bellman - Ford
Graph is represented as
```java
ArrayList<Pair> adj[]
```
```java
public class BellmanFordResult {
    List<Integer> d;
    List<Integer> p;
    boolean hasCycle;

    BellmanFordResult(boolean _hasCycle, List<Integer> _d, List<Integer> _p) {
        hasCycle = _hasCycle;
        d = _d;
        p = _p;
    }
};

public class Pair implements Comparable<Pair> {
    public int destination;
    public int cost;

    Pair(int _destination, int _cost) {
        destination = _destination;
        cost = _cost;
    }

    public int compareTo(Pair rhs) {
        return Integer.compare(cost, rhs.cost);
    }
}

public class Edge {
    int node;
    int neigh;
    int w;

    Edge(int _node, int _neigh, int _w) {
        node = _node;
        neigh = _neigh;
        w = _w;
    }
};
```
```java
private BellmanFordResult bellman(int source, int nodes, List<Edge> edges) {
    // Initializam distantele catre toate nodurile cu infinit

    List<Integer> d = new ArrayList<>();
    List<Integer> p = new ArrayList<>();

    // Initializam distantele la infinit
    for (int node = 0; node <= nodes; node++) {
        d.add(INF);
        p.add(0);
    }

    // Setez sursa la distanta 0.
    d.set(source, 0);

    // Fac N - 1 relaxari.
    for (int i = 1; i <= nodes - 1; i++) {
        // Parcurg toate muchiile:
        for (var edge : edges) {
            int node = edge.node;
            int neigh = edge.neigh;
            int w = edge.w;
            // Se imbunatateste distanta?
            if (d.get(node) + w < d.get(neigh)) {
                // Actualizam distanta si parintele.
                d.set(neigh, d.get(node) + w);
                p.set(neigh, node);
            }
        }
    }

    // Verific daca mai poate fi updatata distanta.
    for (var edge : edges) {
        int node = edge.node;
        int neigh = edge.neigh;
        int w = edge.w;
        // Se imbunatateste distanta?
        if (d.get(node) + w < d.get(neigh)) {
            // Am gasit un ciclu de cost negativ.
            return new BellmanFordResult(true, new ArrayList<>(), new ArrayList<>());
        }
    }

    // Toate nodurile catre care distanta este inca INF nu pot fi atinse din
    // nodul source, deci le setam pe -1.
    for (int node = 1; node <= nodes; node++) {
        if (d.get(node) == INF) {
            d.set(node, -1);
        }
    }

    return new BellmanFordResult(false, d, p);
}

```
### Floyd - Warshall
Graph is represented using an adjacency matrix
```java
int w[][];
```

```java
public class RoyFloydResult {
    int d[][];
    int p[][];

    RoyFloydResult(int _d[][], int _p[][]) {
        d = _d;
        p = _p;
    }
}
```

```java
private RoyFloydResult royfloyd() {
    // Initializez matricea de distante cu matricea ponderilor.
    int d[][] = new int[n + 1][n + 1];
    int p[][] = new int[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = w[i][j];
            p[i][j] = 0;
        }
    }

    // Aplic Roy-Floyd
    for (int k = 1; k <= n; k++) {
        // Fixez nodul intermediar k
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) {
                    continue;
                }

                // Daca nu exista drum de la i la k sau de la k la j, sarim peste.
                if (d[i][k] == 0 || d[k][j] == 0) {
                    continue;
                }

                // Fixez cele doua capete ale drumului pe care le updatez (i, j).
                // Daca nu am drum sau daca obtin un cost mai mic intre i, j,
                // updatez.
                if (d[i][j] == 0 || d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = p[k][j];
                }
            }
        }
    }

    return new RoyFloydResult(d, p);
}
```
### Johnson
```java
// Codul e baban rau uita-te in lab mai bine
```
