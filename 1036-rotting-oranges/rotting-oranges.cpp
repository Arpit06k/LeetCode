class Solution {
public:
    int bfs(queue<pair<int, int>>& q, int n, int m,
            vector<vector<int>>& grid, int fresh) {
        int ans = 0;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            bool rott = false;

            int size = q.size();  

            for (int k = 0; k < size; k++) {
                auto [row, col] = q.front();
                q.pop();
        

            for (int d = 0; d < 4; d++) {
                int nr = row + dx[d];
                int nc = col + dy[d];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                    fresh--;
                    rott = true;
                }

            }
            }
            if (rott) {
                ans++;
            }
        }
        return fresh == 0 ? ans : -1;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue < pair<int, int>> q;

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1) {
                    cnt++;
                }
            }
        }

        return bfs(q, n, m, grid, cnt);
    }
};