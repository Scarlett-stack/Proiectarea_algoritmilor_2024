// https://www.hackerrank.com/contests/colocviu-321cab-1ac99f/challenges/zaruri

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MODULO 1000000007

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, f, x;
    std::cin >> n >> f >> x;
    
    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(x + 1, 0));
    
    for (int i = 1; i <= std::min(f, x); ++i) {
        dp[1][i] = 1;
    }
    
    // l - numarul aruncarii
    for (int l = 2; l <= n; ++l) {
        // roll - cat am dat la aruncarea curenta
        for (int roll = 1; roll <= f; ++roll) {
            // i - ce suma pot extinde
            for (int i = 1; i <= x; ++i) {
                if (roll > i) {
                    continue;
                }
                dp[l][i] = (dp[l][i] + dp[l - 1][i - roll]) % MODULO;
            }
        }
    }
    
    std::cout << dp[n][x] << "\n";
    
    return 0;
}

