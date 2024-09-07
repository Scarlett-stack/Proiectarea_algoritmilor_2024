#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <deque>

using namespace std;

class TarjanSccSolver {
private:
    int n;
    vector<vector<int>> graph;

    bool solved;
    int sccCount, id;
    vector<bool> visited;
    vector<int> ids, low, sccs;
    stack<int> st;

    const int UNVISITED = -1;

    void dfs(int at) {
        ids[at] = low[at] = id++;
        st.push(at);
        visited[at] = true;

        for (int to : graph[at]) {
            if (ids[to] == UNVISITED) {
                dfs(to);
            }
            if (visited[to]) {
                low[at] = min(low[at], low[to]);
            }
        }

        if (ids[at] == low[at]) {
            while (true) {
                int node = st.top();
                st.pop();
                visited[node] = false;
                sccs[node] = sccCount;
                if (node == at) break;
            }
            sccCount++;
        }
    }

public:
    TarjanSccSolver(vector<vector<int>>& graph) {
        if (graph.empty()) throw invalid_argument("Graph cannot be null.");
        this->graph = graph;
        this->n = graph.size();
        solved = false;
        sccCount = 0;
        id = 0;
        ids.assign(n, UNVISITED);
        low.assign(n, 0);
        sccs.assign(n, 0);
        visited.assign(n, false);
    }

    int getSccCount() {
        if (!solved) solve();
        return sccCount;
    }

    vector<int> getSccs() {
        if (!solved) solve();
        return sccs;
    }

    void solve() {
        if (solved) return;
        for (int i = 0; i < n; i++) {
            if (ids[i] == UNVISITED) {
                dfs(i);
            }
        }
        solved = true;
    }
};

vector<vector<int>> createGraph(int n) {
    return vector<vector<int>>(n);
}

void addEdge(vector<vector<int>>& graph, int from, int to) {
    graph[from].push_back(to);
}

int main() {
    int n = 6;
    vector<vector<int>> graph = createGraph(n);

    addEdge(graph, 0, 2);
    addEdge(graph, 4, 0);
    addEdge(graph, 0, 5);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 4, 5);
   // addEdge(graph, 5, 6);
   // addEdge(graph, 3, 7);
   // addEdge(graph, 7, 5);
   // addEdge(graph, 1, 2);
   // addEdge(graph, 7, 3);
   // addEdge(graph, 5, 0);

    TarjanSccSolver solver(graph);

    vector<int> sccs = solver.getSccs();
    unordered_map<int, vector<int>> multimap;
    for (int i = 0; i < n; i++) {
        multimap[sccs[i]].push_back(i);
    }

    cout << "Number of Strongly Connected Components: " << solver.getSccCount() << endl;
    for (const auto& entry : multimap) {
        cout << "Nodes: ";
        for (int node : entry.second) {
            cout << node << " ";
        }
        cout << "form a Strongly Connected Component." << endl;
    }

    return 0;
}
