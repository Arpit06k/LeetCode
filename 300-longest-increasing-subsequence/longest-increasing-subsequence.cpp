// class Solution {
// public:
//     int f(int i, int prev, vector<int>& nums, int n, vector<vector<int>>& dp)
//     {
//         if (i == n)
//             return 0;
//         if (dp[i][prev + 1] != -1)
//             return dp[i][prev + 1];
//         int len = 0 + f(i + 1, prev, nums, n, dp);
//         if (prev == -1 || nums[i] > nums[prev]) {
//             len = max(len, 1 + f(i + 1, i, nums, n, dp));
//         }
//         return dp[i][prev + 1] = len;
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int>(n, -1));
//         return f(0, -1, nums, n, dp);
//     }
// };

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
//         for (int prev = 0; prev <= n; prev++) {
//             dp[n][prev] = 0;
//         }
//         for (int i = n - 1; i >= 0; i--) {
//             for (int prev = 0; prev <= n; prev++) {
//                 int len = 0 + dp[i + 1][prev];
//                 if (prev == 0|| nums[i] > nums[prev-1]) {
//                     len = max(len, 1 + dp[i + 1][i + 1]);
//                 }
//                 dp[i][prev] = len;
//             }
//         }
//         return dp[0][0];
//     }
// };



// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//        vector<int>next(n + 1, 0),curr(n+1,0);
//         for (int i = n - 1; i >= 0; i--) {
//             for (int prev = 0; prev <= n; prev++) {
//                 int len = 0 + next[prev];
//                 if (prev == 0|| nums[i] > nums[prev-1]) {
//                     len = max(len, 1 + next[i + 1]);
//                 }
//                 curr[prev] = len;
//             }
//             next=curr;
//         }
//         return curr[0];
//     }
// };


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi=1;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i]){
                    dp[i]=max(dp[i],1+dp[prev]);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};


