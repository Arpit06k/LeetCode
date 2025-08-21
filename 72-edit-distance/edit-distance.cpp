class Solution {
public:
    // f(n-1,m-1) mini number of operation to convert s to t
    // if i reaches negatives means word1 exhausted so to convert word1 to wrod2
    // inert the rem character into word1 same if j gets exhausted
//     int f(int i, int j, string& word1, string& word2,vector<vector<int>>& dp) {
//         if (i < 0)
//             return j + 1;
//         if (j < 0)
//             return i + 1;
//         if(dp[i][j]!=-1)return dp[i][j];
//         if (word1[i] == word2[j])
//             return f(i - 1, j - 1, word1, word2,dp);

//         //to insert f(i,j-1);
//         //to delete f(i-1,j)
//         //to replace f(i-1,j-1)
//         return 1+ min(f(i,j-1,word1,word2,dp),min(f(i-1,j,word1,word2,dp),f(i-1,j-1,word1,word2,dp)));
//     }
//     int minDistance(string word1, string word2) {
//         int n = word1.size();
//         int m = word2.size();
//         vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
//         return f(n - 1, m - 1, word1, word2,dp);
//     }
// };



    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));

        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        
        for(int j=0;j<=m;j++){
            dp[0][j]=j;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else  dp[i][j] =1+ min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));

            }
        }
        return dp[n][m];
    }
};