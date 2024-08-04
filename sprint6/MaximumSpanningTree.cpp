// https://contest.yandex.ru/contest/25070/run-report/113755669/

/*
--Principle of Operation--
The algorithm is based on a modified version of Prim's algorithm for constructing 
a Maximum Spanning Tree (MST). It starts with an arbitrary vertex and sequentially adds 
the heaviest edge connecting the tree to one of the remaining vertices until all vertices of 
the graph are added or until no more available edges remain.

The algorithm uses:
- `priority_queue` to store and quickly retrieve the maximum edges, allowing the addition of 
the heaviest edge to the spanning tree each time.
- An `is_added` flag array to track the state of each vertex's addition to the spanning tree, 
reducing memory consumption and simplifying vertex state management.

--Proof of Correctness--
The algorithm correctly constructs a Maximum Spanning Tree:

- At each step, the algorithm selects the maximum edge that can be added to the spanning tree without 
forming a cycle. This ensures that the included edges form a tree.
- The algorithm terminates when all vertices are added to the spanning tree or when no more edges are 
available for addition. If vertices remain unadded after the algorithm finishes, it means the graph is 
disconnected.

--Time Complexity--
- Adding edges to the priority queue: Each edge is added to the heap once, with the addition operation 
having a complexity of O(log m), where m is the number of edges.
- Extracting edges from the priority queue: For each of the n-1 added vertices, an edge extraction is required, 
with each extraction having a complexity of O(log m).

The overall time complexity of the algorithm is O((n + m) log m).

--Space Complexity--
- Storing the graph: An adjacency list requires O(m) memory.
- Additional data structures: `is_added` uses O(n) memory, and `priority_queue` can contain up to m edges, also 
requiring O(m) memory.

Thus, the total space complexity is O(m + n).
*/
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

struct Edge {
    int start, end, weight;
    bool operator < (const Edge& other) const {
        return weight < other.weight; 
    }
};

class Graph {
public:
    Graph(int n) : graph(n + 1), is_added(n + 1, false) {}

    void add_edge(int u, int v, int w) {
        graph[u].push_back({u, v, w});
        graph[v].push_back({v, u, w});
    }

    int findMaximumSpanningTree() {
        // Берём первую попавшуюся вершину
        add_vertex(1);

        while (!edges.empty()) {
            Edge e = edges.top();
            edges.pop();
            if (!is_added[e.end]) {
                maximum_spanning_tree.push_back(e);
                add_vertex(e.end);
            }
        }

        if (count(is_added.begin() + 1, is_added.end(), true) == graph.size() - 1) {
            int total_weight = 0;
            for (const auto& e : maximum_spanning_tree) {
                total_weight += e.weight;
            }
            return total_weight;
        } else {
            return -1;
        }
    }

private:
    vector<vector<Edge>> graph;
    vector<bool> is_added;
    priority_queue<Edge> edges;
    vector<Edge> maximum_spanning_tree;

    void add_vertex(int v) {
        is_added[v] = true;
        for (const auto& edge : graph[v]) {
            if (!is_added[edge.end]) {
                edges.push(edge);
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.add_edge(u, v, w);
    }

    int result = g.findMaximumSpanningTree();
    if (result == -1)
        cout << "Oops! I did it again" << endl; 
    else 
        cout << result << endl;

    return 0;
}

