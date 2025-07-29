class Solution {
public:
int paths(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&obstacle){
        if(i>=0 && j>=0 && obstacle[i][j]==1){
            return 0;
        }
        if(i==0&&j==0){
            return 1;
        }
        if(i<0||j<0){
            return 0;
        }

        if(dp[i][j]!=-1)return dp[i][j];
        int up=paths(i-1,j,dp,obstacle);
        int left=paths(i,j-1,dp,obstacle);
        return dp[i][j]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1) return 0;
          vector<vector<int>>dp(m,vector<int>(n,-1));
            return paths(m-1,n-1,dp,obstacleGrid);
    }
};