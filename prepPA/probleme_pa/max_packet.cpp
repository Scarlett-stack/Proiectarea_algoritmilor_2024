// https://www.hackerrank.com/contests/test-practic-pa-2018-v1-deadbeef/challenges/test-1-2-2-max-packet-size-medie

#include <bits/stdc++.h>
using namespace std;


void dfs(int node, std::vector<bool> &visited, std::unordered_map<int, std::pair<int, int>> &neigh, std::vector<int> &current_component, int &min_cost) {
    visited[node] = true;
    current_component.push_back(node);
    
    // daca din mine mai pleaca o alta conexiune
    if (neigh.find(node) != neigh.end()) {
        int next = neigh[node].first;
        int cost = neigh[node].second;
        min_cost = std::min(min_cost, cost);
        dfs(next, visited, neigh, current_component, min_cost);
    }
}

/*
    [](auto &a, auto &b) {
        // aici compari doua elemente din vectorul tau
    }
    
    Ex1
    std::vector<int> v = {1, 6, 12, 7};
    std::sort(v.begin(), v.end(), [](auto &a, auto &b) {
        return a < b;
    }); // sortare crescatoare
    
    std::sort(v.begin(), v.end(), [](auto &a, auto &b) {
        return a > b;
    }); // sortare crescatoare
    
    
    Ex2
    std::vector<std::pair<int, int>> v = {
        {1, 2},
        {4, 6},
        {5, 3},
        {7, 8},
    };
    std::sort(v.begin(), v.end(), [](auto &a, auto &b) {
        return a.first < b.first;
    }); // sortare crescatoare dupa primul element
    
    std::sort(v.begin(), v.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    }); // sortare descrescatoare dupa al doilea element
    
     std::sort(v.begin(), v.end(), [](auto &a, auto &b) {
        return a.first + a.second < b.first + b.second;
    }); // sortare crescatoare dupa suma elementelor
    
    
*/

int main() {
	/* Cititi de la STDIN si afisati la STDOUT. Decomentati linia de mai jos daca
     * folositi cin/cout. Nu imbinati cin/cout cu scanf/printf in acest caz.
     */
	ios::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    
    // neigh[x] = {y, p} <=> exista o ruta de la x la y de cost p
    std::unordered_map<int, std::pair<int, int>> neigh;
    
    // unordered_map -> map nesortat
    // std::map tine cheile sortate
        // O(log n) - insert
        // O(log n) - find
        // O(log n) - remove
    // std::unordered_map tine cheile nesortate
        // O(1) - insert
        // O(1) - find
        // O(1) - remove
    
    // aceleasi diferente exista si intre unordered_set si set
    
    
    // std::set
        // insert(x) -> insereaza un element in vector
        // find -> 
            // s.find(5) != s.end() -> 5 exista in set
            // s.find(5) == s.end() -> 5 nu exista in set
            // s.erase(5) -> sterge 5 din set daca e prezent
    
    // la fel se foloseste si unordered_set
    
    // i apartine not_start => in i intra un alt nod
    std::unordered_set<int> not_start;
    
    for (int i = 0; i < m; ++i) {
        int x, y, p;
        std::cin >> x >> y >> p;
        neigh[x] = {y, p};
        not_start.insert(y);
    }
    
    std::vector<bool> visited(n);
    
    // all_components[i] = va contine o pereche intre un lant i (care e un vector de int) si un numar (care e costul minim pe acel lant)
    std::vector<std::pair<std::vector<int>, int> > all_components;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i] && (not_start.find(i) == not_start.end())) {
            std::vector<int> current_component;
            int min_cost = INT_MAX;
            dfs(i, visited, neigh, current_component, min_cost);
            if (current_component.size() == 1) {
                min_cost = 0;
            }
            all_components.push_back({current_component, min_cost});
        }
    }
    
    // all_components
    // {{1, 2, 5, 4}, 5} -> am lantul {1, 2, 5, 4} cu costul de transmisie 5
    // {{3, 6}, 2} -> am lantul {3, 6} cu costul de transmisie 2
    
    
    std::sort(all_components.begin(), all_components.end(), [](std::pair<std::vector<int>, int> &a, std::pair<std::vector<int>, int> &b) {
        return a.first[0] < b.first[0];
    });
    
    std::cout << all_components.size() << "\n";
    for (int i = 0; i < all_components.size(); ++i) {
        auto component = all_components[i].first;
        int cost = all_components[i].second;
        if (component.size() != 1) {
            // std::cout << component[0] << " " << component[component.size() - 1] << " " << min_price << "\n";
            std::cout << component.front() << " " << component.back() << " " << cost << "\n";
            
        } else {
            std::cout << component[0] << " " << component[0] << " " << cost << "\n";
        }
    }

    return 0;
}
