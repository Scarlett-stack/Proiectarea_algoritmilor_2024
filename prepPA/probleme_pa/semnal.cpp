// https://www.hackerrank.com/contests/colocviu-a31f9e/challenges/test-1-1-1-semnal-usoara/copy-from/1378036211

#include <bits/stdc++.h>
using namespace std;

int main() {
	/* Cititi de la STDIN si afisati la STDOUT. Decomentati linia de mai jos daca
     * folositi cin/cout. Nu imbinati cin/cout cu scanf/printf in acest caz.
     */
	ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    int min_op = 0, max_op = 0;
    
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
        if (v[i] == 1) {
            max_op++;
        }
    }
    
    int i = 0;
    for (; i < n; ++i) {
        if (v[i] == 1) {
           i += 2; // luminez la dreapta pe v[i + 1] si v[i + 2]
            min_op++;
        }
    }
    
    std::cout << min_op << " " << max_op << "\n";
    
    return 0;
}