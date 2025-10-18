class Solution {
public:
    void bfs(vector<vector<char>>& board, int i, int j, int n, int m) {
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        queue<pair<int, int>> q;
        q.push({i, j});

        board[i][j] = 'T';
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;

            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    board[nr][nc] == 'O') {
                    board[nr][nc] = 'T';
                    q.push({nr, nc});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                bfs(board, i, 0, n, m);
            }
            if (board[i][m - 1] == 'O') {
                bfs(board, i, m - 1, n, m);
            }
        }

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                bfs(board, 0, j, n, m);
            }
            if (board[n - 1][j] == 'O') {
                bfs(board, n - 1, j, n, m);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='T'){
                    board[i][j]='O';
                }
            }
        }
    }
};