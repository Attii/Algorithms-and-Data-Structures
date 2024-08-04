// https://contest.yandex.ru/contest/25070/run-report/113755669/

/*
Idea for the solution was found here: [https://ru.stackoverflow.com/questions/1415293/Как-ускорить-проверку-оптимальности-графа](https://ru.stackoverflow.com/questions/1415293/%D0%9A%D0%B0%D0%BA-%D1%83%D1%81%D0%BA%D0%BE%D1%80%D0%B8%D1%82%D1%8C-%D0%BF%D1%80%D0%BE%D0%B2%D0%B5%D1%80%D0%BA%D1%83-%D0%BE%D0%BF%D1%82%D0%B8%D0%BC%D0%B0%D0%BB%D1%8C%D0%BD%D0%BE%D1%81%D1%82%D0%B8-%D0%B3%D1%80%D0%B0%D1%84%D0%B0)

--Principle of Operation--
The program uses a graph representation to check the optimality of the railroad map. Cities are 
represented as graph nodes, and roads are edges marked with types 'R' or 'B'. The program builds 
the graph and then checks for the presence of cycles for each type of edge separately using a modified 
depth-first search (DFS) method that evaluates the presence of paths with different types of roads between 
pairs of cities.

--Proof of Correctness--
We will prove the correctness of the algorithm by contradiction.

Assume that the railroad map is optimal. This means that for each pair of cities A and B, where A < B, 
there exists a route of only one type, either R or B.

Note that, based on the condition, for any A < n, where n is the number of vertices, there are always n-A 
routes described, thus from such an A, it is always possible to build some route to B, where A < B < n. This 
excludes situations where there is no route from A to B.

We perform an inversion of one type of edge, for example, R-type edges. After inversion:

- R-type edges will go from a city with a higher number to a city with a lower number.
- B-type edges will retain their original direction (from smaller to larger).

Then we apply DFS to search for cycles.

Assume the method found a cycle. A cycle in this context means the existence of a path that returns to 
the starting point, passing through edges of both types. However, by assumption, the map should be optimal, 
and such a path should not exist. Thus, this cycle must consist only of edges of one type, either R or B only.

If the cycle consisted of R and B edges, it would mean there exists a path between some cities using both types of 
roads, which contradicts the optimality of the map. This contradiction indicates that our initial hypothesis that 
the method could erroneously determine the map as non-optimal is incorrect.

If the method detects a cycle after edge inversion, it indeed indicates the non-optimality of the map, as it shows 
that it is possible to travel between some cities using both types of roads.

Therefore, the assumption of a possible error in the method is not confirmed, and the method is correct. This proves 
that if the method detects a cycle, the map is indeed not optimal, and conversely, if the method does not detect a cycle, 
the map is optimal.

P.S. The example from the code review is incorrect "1->3=>2->4=>1". Such a cycle can result from the graph 1->3, 1=>4, 2=>3, 2->4, 
but such a graph cannot result from the task condition, as it explicitly states that for any i < n, the condition holds: 
there are n-i edges. In the example, the edge 1->2 is missing.

--Time Complexity--
The program's complexity is determined by two main factors:

1. Building the graph: O(n^2), where n is the number of cities. This is because each city can have up to n-1 roads.
2. Cycle checking: O(V + E), where V is the number of vertices and E is the number of edges. In the worst case, 
each vertex is connected to every other vertex, leading to E = O(n^2).

The overall time complexity of the algorithm is O(n^2).

--Space Complexity--
The algorithm uses:

- A graph in the form of a vector of vectors to store edges: O(n^2) memory.
- A vector of colors for each vertex to track the visit status in DFS: O(n).

The overall space complexity is O(n^2) due to storing the graph, which is the largest memory requirement in the algorithm.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

enum Color {
    WHITE,
    GREY,
    BLACK
};

bool contain_cycle(int s, const vector<vector<bool>>& graph, vector<Color>& color) {
    stack<int> st;
    st.push(s);

    while (!st.empty()) {
        int v = st.top();
        if (color[v] == WHITE) {
            color[v] = GREY;
            for (size_t w = 1; w < graph.size(); ++w) {  
                if (graph[v][w]) {  
                    if (color[w] == GREY) {
                        return true;
                    }
                    if (color[w] == WHITE) {
                        st.push(w);
                    }
                }
            }
        } else {
            color[v] = BLACK;
            st.pop();
        }
    }
    return false;
}

bool is_cyclic(const vector<vector<bool>>& graph) {
    vector<Color> color(graph.size(), WHITE);
    
    for (size_t i = 1; i < color.size(); ++i) {
        if (color[i] == WHITE) {
            if (contain_cycle(i, graph, color)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));  

    string input;
    for (int i = 1; i < n; ++i) {
        cin >> input;
        for (size_t j = 0; j < input.size(); ++j) {
            if (input[j] == 'B') {
                graph[i][i + j + 1] = true;  
            } else if (input[j] == 'R') {
                graph[i + j + 1][i] = true;  
            }
        }
    }

    if (is_cyclic(graph)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }

    return 0;
}
