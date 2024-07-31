// https://contest.yandex.ru/contest/25070/run-report/113755669/

/*
--Принцип работы--
  Данный алгоритм основан на модифицированной версии алгоритма Прима для 
построения максимального остовного дерева (Maximum Spanning Tree). 
Он начинается с произвольной вершины и последовательно добавляет к остову 
наиболее тяжёлое ребро, соединяющее дерево с одной из оставшихся вершин, 
пока не добавятся все вершины графа или пока не закончатся доступные 
рёбра.

Алгоритм использует:
    'priority_queue' для хранения и быстрого извлечения максимальных рёбер, 
  что позволяет каждый раз добавлять в остов ребро с максимальным весом.
    Массив флагов 'is_added' для отслеживания состояния добавления каждой 
  вершины в остов, что уменьшает потребление памяти и упрощает управление 
  состоянием вершин.

--Доказательство корректности--
Алгоритм корректно строит максимальное остовное дерево:

  Алгоритм выбирает на каждом шаге максимальное ребро, которое можно 
добавить к остову без образования цикла. Это гарантирует, что включаемые 
рёбра образуют дерево.
  Алгоритм завершается, когда все вершины добавлены в остов, или когда 
больше нет рёбер для добавления. Если после завершения работы алгоритма 
остались недобавленные вершины, это означает, что граф несвязен.

--Временная сложность--
  Добавление рёбер в приоритетную очередь: Каждое ребро добавляется в 
кучу один раз, операция добавления имеет сложность O(log m), где m - 
количество рёбер.
  Извлечение рёбер из приоритетной очереди: Для каждой из n−1 добавленной 
вершины потребуется извлечь ребро, каждое извлечение имеет сложность 
O(log m).

Итоговая временная сложность алгоритма составляет O((n + m)log m).

--Пространственная сложность--
4. Пространственная сложность
  Хранение графа: Для хранения списка смежности требуется O(m) памяти.
  Дополнительные структуры данных: is_added использует O(n) памяти, 
priority_queue может содержать до m рёбер, что также требует O(m) памяти.

Таким образом, общая пространственная сложность составляет O(m+n).
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

