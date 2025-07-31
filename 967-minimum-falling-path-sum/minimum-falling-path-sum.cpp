class Solution {
public:
    // int f(int i, int j, vector<vector<int>>& mat,vector<vector<int>>&dp) {
    //     int n = mat.size();
    //     int m = mat[0].size();
    //     if (i == 0)
    //         return mat[0][j];
    //     if (j < 0 || j >= m)
    //         return 1e9;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //             int left = mat[i][j] + f(i - 1, j - 1, mat,dp);

    //     int up = mat[i][j] + f(i - 1, j, mat,dp);

    //     int right = mat[i][j] + f(i - 1, j + 1, mat,dp);
    //     int d = min(up, left);
    //     return  dp[i][j]=min(d, right);
    // }
    //  for (int j = 0; j < m; j++) {
    //         ans = min(ans, f(n - 1, j, matrix,dp));
    //     }
    //     return ans;

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = 1e9;
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m));
        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int left = matrix[i][j];
                if (j - 1 >= 0)
                   left+= dp[i - 1][j - 1];
                   else left+=1e9;
                int up = matrix[i][j] + dp[i - 1][j];

                int right = matrix[i][j]; 
                if (j + 1 < m)  right+=dp[i - 1][j + 1];
                else right+=1e9;
                int d = min(up, left);
                dp[i][j] = min(d, right);
            }
        }
        int mini = dp[n - 1][0];
        for (int j = 1; j < m; j++) {
            mini = min(mini, dp[n - 1][j]);
        }
        return mini;
    }
};