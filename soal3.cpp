#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    vector<vector<int>> grid(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }

    int sr, sc, fr, fc;
    cin >> sr >> sc;
    cin >> fr >> fc;

    vector<vector<int>> dist(r, vector<int>(c, -1));

    queue<pair<int, int>> q;
    dist[sr][sc] = 0;
    q.push({sr, sc});

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        int cr = cur.first;
        int cc = cur.second;

        if (cr == fr && cc == fc) {
            break;
        }

        for (int d = 0; d < 4; d++) {
            int nr = cr + dr[d];
            int nc = cc + dc[d];

            bool valid = (nr >= 0 && nr < r && nc >= 0 && nc < c);
            if (valid && grid[nr][nc] == 0 && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[cr][cc] + 1;
                q.push({nr, nc});
            }
        }
    }

    cout << dist[fr][fc] << "\n";
    return 0;
}