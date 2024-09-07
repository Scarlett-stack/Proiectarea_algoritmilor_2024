// https://www.hackerrank.com/contests/test-practic-recuperare-2022-90528/challenges/test-1-1-2-generare-siruri

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void back(int n, std::vector<int> &current_solution, std::vector<bool> &used) {
    if (current_solution.size() == n) {
        // pe cazul neoptimizat, deci va trebui sa testam
        // bool ok = true;
        // for (int i = 0; i < current_solution.size() - 1; ++i) {
        //     if ((current_solution[i] % 2) == (current_solution[i + 1] % 2)) {
        //         ok = false;
        //         break;
        //     }
        // }
        
        // if (ok) {
            for (auto elem : current_solution) {
                std::cout << elem << " ";
            }
            std::cout << "\n";
        // }
        return;
    }
    
    for (int i = 1; i <= n; ++i) {
        if (used[i]) {
            continue;
        }
        
        if (current_solution.size() != 0 && (current_solution.back() % 2) == (i % 2)) {
            continue;
        }
        
        // stiu ca elementul e nefolosit
        used[i] = true;
        current_solution.push_back(i);
        back(n, current_solution, used);
        current_solution.pop_back();
        used[i] = false;
    }
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    std::cin >> n;
    if (n == 0) {
        std::cout << "-1\n";
        return 0;
    }
    
    std::vector<int> current_solution;
    std::vector<bool> used(n + 1, false);
    back(n, current_solution, used);
    
    return 0;
}