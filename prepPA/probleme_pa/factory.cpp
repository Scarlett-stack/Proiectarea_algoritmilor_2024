// https://www.hackerrank.com/contests/test-practic-2022-06318/challenges/2-2-factory-network-medie

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define NMAX 5005

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> adj[NMAX];
    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y; 
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    int source = 1;
    // conventie color = 0 (prod), color = 1 (cons)
    int num_prod = 0, num_cons = 0;
    
    // {nod, culoarea lui nod}
    std::queue<std::pair<int, int>> q;
    std::vector<bool> visited(n + 1, false); 
    
    q.push({source, 0});
    visited[source] = true;
        
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        
        int node = front.first;
        int color = front.second;
        
        if (color == 0) {
            num_prod++;
        } else {
            num_cons++;
        }
        
        for (auto neigh : adj[node]) {
            if (!visited[neigh]) {
                visited[neigh] = true;
                q.push({neigh, 1 - color});
            }
        }
    }
    
    std::cout << std::min(num_prod, num_cons) << "\n";
    
    return 0;
}
