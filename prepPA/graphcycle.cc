#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited, vector<int>& parent, int& cycle_start, int& cycle_end) {
    visited[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            parent[neighbor] = node;
            if (dfs(neighbor, graph, visited, parent, cycle_start, cycle_end)) {
                return true;
            }
        } else if (neighbor != parent[node]) { // A cycle is found
            cycle_end = node;
            cycle_start = neighbor;
            return true;
        }
    }

    return false;
}

int main() {
    ifstream fin("gcycle.in");
    ofstream fout("gcycle.out");

    int N, M;
    fin >> N >> M;

    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int x, y;
        fin >> x >> y;
        graph[x].push_back(y);
    }

    vector<bool> visited(N + 1, false);
    vector<int> parent(N + 1, -1);
    int cycle_start = -1, cycle_end = -1;

    for (int i = 1; i <= N; ++i) {
        if (!visited[i] && dfs(i, graph, visited, parent, cycle_start, cycle_end)) {
            break;
        }
    }

    if (cycle_start == -1) {
        fout << "0\n";
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        fout << cycle.size() << '\n';
        for (int v : cycle) {
            fout << v << ' ';
        }
        fout << '\n';
    }

    fin.close();
    fout.close();

    return 0;
}