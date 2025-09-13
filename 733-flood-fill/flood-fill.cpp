class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int init = image[sr][sc];
        if (init == color)
            return image;
        image[sr][sc] = color;

        queue<pair<int, int>> q;
        int n = image.size();
        int m = image[0].size();
        // vector<vector<int>>vis();
        q.push({sr, sc});
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nr = row + dx[d];
                int nc = col + dy[d];

                if (nr >= 0 && nr < n && nc < m && nc >= 0 &&
                    image[nr][nc] == init) {
                    image[nr][nc] = color;
                    q.push({nr,nc});
                }
                }
            }
           return image;
        }
    };