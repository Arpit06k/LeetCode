class Solution {
public:
    // int f(int i, int j, vector<vector<int>>& tri, vector<vector<int>>& dp) {
    //     int n = tri.size();
    //     if (i == n - 1)
    //         return tri[n - 1][j];
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     int left = tri[i][j] + f(i + 1, j, tri, dp);
    //     int right = tri[i][j] + f(i + 1, j + 1, tri, dp);
    //     return dp[i][j] = min(left, right);
    // }

            // return f(0, 0, triangle, dp);

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int left=triangle[i][j]+dp[i+1][j];
                int right=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(left,right);
                }
        }
        return dp[0][0];
    }
};