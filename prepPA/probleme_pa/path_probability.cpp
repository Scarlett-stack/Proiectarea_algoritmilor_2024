// https://www.hackerrank.com/contests/test-practic-recuperare-2022-90528/challenges/3-1-path-probability-grea/problem

#include <bits/stdc++.h>

#define NMAX 1005

double mat[NMAX][NMAX];
bool visited[NMAX][NMAX];

int main() {
    int n, m; 
    std::cin >> n >> m;

    int start_row, start_col;
    int end_row, end_col;

    std::cin >> start_row >> start_col;
    std::cin >> end_row >> end_col;

    mat[start_row][start_col] = 10000.0; 

    std::queue<std::pair<int, int>> q;
    q.push({start_row, start_col});

    std::vector<std::pair<int, int>> directions = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (visited[x][y]) {
            continue;;
        }

        visited[x][y] = true;   

        std::vector<std::pair<int, int>> neighs;
        for (auto &[dx, dy] : directions) {
            int new_x = x + dx;
            int new_y = y + dy;
            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m) {
                neighs.push_back({new_x, new_y});
            }
        }

        int size = neighs.size();
        double current_val = mat[x][y];
        // std::cout << x << " " << y << " " << size << "\n";

        for (auto &[neigh_x, neigh_y] : neighs) {
            if (!visited[neigh_x][neigh_y]) {
                mat[neigh_x][neigh_y] += 1.0 * current_val / neighs.size();
                q.push({neigh_x, neigh_y});
            }
        }

    }

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         std::cout << mat[i][j] << " ";
    //     }
    //     std::cout << "\n";
    // }
    std::cout << mat[end_row][end_col] << "\n";

    return 0;
}