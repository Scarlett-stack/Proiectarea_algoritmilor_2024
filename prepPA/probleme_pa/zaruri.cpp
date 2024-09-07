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
    
    std::vector<std::vector<long long>> dp(2, std::vector<long long>(x + 1, 0));
    
    
    /*
        dp[2][x + 1];
        
        pentru aruncarea 1 folosesc linia dp[0] 
        
        codul din for
        
        pentru aruncarea 2 folosesc linia dp[1] (care depinde de linia dp[0])
            * acum, rezultatele cele mai recente sunt pe linia dp[1]
            * rezultatele de pe linia dp[0] nu imi mai trebuie, deci pot refolosi linia dp[0]
               * deci, trebuie sa fac zero-uri pe linia dp[0]
    
        pentru aruncarea 3 folosesc linia dp[0] (care depinde de linia dp[1])
            * acum, rezultatele cele mai recente sunt pe linia dp[0]
            * rezultatele de pe linia dp[1] nu iumi mai trebuie, deci pot refolosi linia dp[1]
                * deci, trebuie sa fac zero-uri pe linia dp[1]
    */
    
    
    /*
        Obtine suma x = 7 folosind n = 2 aruncari cu zaruri cu f = 10000 fete
        x < f
        
        Obtine suma x = 100 folosind n = 2 aruncari cu zaruri cu f = 10 fete

    */
    
    for (int i = 1; i <= std::min(f, x); ++i) {
        dp[0][i] = 1;
    }
    
    int num_line = 1;
    
    // l - numarul aruncarii
    for (int l = 2; l <= n; ++l) {
        // roll - cat am dat la aruncarea curenta
        for (int roll = 1; roll <= f; ++roll) {
            // i - ce suma pot extinde
            for (int i = roll; i <= x; ++i) {
                dp[num_line][i] = (dp[num_line][i] + dp[1 - num_line][i - roll]) % MODULO;
            }
        }
        
        num_line = 1 - num_line;
        for (int i = 1; i <= x; ++i) {
            dp[num_line][i] = 0;
        }
    }
    
    std::cout << dp[1 - num_line][x] << "\n";
    
    
    
    return 0;
}
