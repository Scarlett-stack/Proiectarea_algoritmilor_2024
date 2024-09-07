// https://www.hackerrank.com/contests/test-practic-pa-2019-64563/challenges/test-1-2-2-conversie-valutara-medie

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

#define NMAX 105

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, m;
    std::cin >> n >> m;
    
    double cost[NMAX][NMAX];
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cost[i][j] = -1;
        }
    } 
    
    for (int i = 1; i <= n; ++i) {
        cost[i][i] = 1;
    }
    
    for (int i = 0; i < m; ++i) {
        int x, y;
        double price;
        std::cin >> x >> y >> price;
        cost[x][y] = price;
    }
    
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if ((cost[i][k] == -1) || (cost[k][j] == -1)) {
                    continue;
                }
                
                if (i == j) {
                    continue;
                }
                
                // assert(cost[i][k] >= 0);
                // assert(cost[k][j] >= 0);
            
                if (cost[i][k] * cost[k][j] >= cost[i][j]) {
                    cost[i][j] = cost[i][k] * cost[k][j];
                }
            }
        }
    }
    
    std::cout << std::fixed;
    std::cout << std::setprecision(10);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cout << cost[i][j] << " ";
        }
        std::cout << "\n";
    }
    
    return 0;
}