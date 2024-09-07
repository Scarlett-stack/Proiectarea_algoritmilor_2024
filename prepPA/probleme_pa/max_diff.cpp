// https://www.hackerrank.com/contests/test-practic-pa-2018-v2-cafebabe-101/challenges/test-2-2-2-maxdif-usoara/problem

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
    
    int min_v = INT_MAX;
    int max_v = INT_MIN;
    
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
        min_v = std::min(min_v, v[i]);
        max_v = std::max(max_v, v[i]);
    }
    
    long long sum = 0;
    bool has_positive = false, has_negative = false;
    
    // has_positive = verific daca am numere pozitive
    // has_negative= verific daca am numere negative

    for (int i = 0; i < n; ++i) {
        if (v[i] > 0) {
            // pun v[i] in A
            sum += v[i];
            has_positive = true;
        } else {
            // pun v[i] in B
            sum -= v[i];
            has_negative = true;
        }
    }
    
    if (!has_negative) {
        // am doar numere pozitive, trebuie sa il pun pe cel mai mic in B
        sum = sum - 2 * min_v; // de ce scad 2 * min_v? Pentru ca am adaugat mai sus min_v
    } else if (!has_positive) {
        sum = sum + 2 * max_v;
    }
    
    std::cout << sum << "\n";
    

    return 0;
}