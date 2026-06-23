#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int FR, FC;
long long jumlahJalur = 0;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void dfs(int r, int c) {
    if (r == FR && c == FC) {
        jumlahJalur++;
        return;
    }

    visited[r][c] = true; 

    for (int d = 0; d < 4; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];

        bool valid = (nr >= 0 && nr < R && nc >= 0 && nc < C);
        if (valid && grid[nr][nc] == 0 && !visited[nr][nc]) {
            dfs(nr, nc);
        }
    }

    visited[r][c] = false; 
}

int main() {
    cin >> R >> C;

    grid.assign(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    int sr, sc;
    cin >> sr >> sc;
    cin >> FR >> FC;

    visited.assign(R, vector<bool>(C, false));
    dfs(sr, sc);

    cout << jumlahJalur << "\n";
    return 0;
}