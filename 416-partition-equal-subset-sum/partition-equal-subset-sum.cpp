class Solution {
public:
    // bool f(int i, vector<int>& a, int sum,vector<vector<int>>&dp) {
    //     if (sum == 0)
    //         return true;
    //     if (i >= a.size() || sum < 0)
    //         return false;

    //     if(dp[i][sum]!=-1)return dp[i][sum];
    //     bool pick =f(i + 1, a, sum - a[i],dp);

    // bool nonpick= f(i + 1, a, sum,dp);

    //     return dp[i][sum]=pick||nonpick;
    //             return f(0, nums, sum / 2,dp);

    // }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0)
            return false;

        sum = sum / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        // vector<int> dp(sum + 1, false);
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                bool nonpick = dp[i - 1][j];

                bool pick = false;
                if (j >= nums[i - 1]) {
                     pick = dp[i - 1][j - nums[i - 1]];
                }
                dp[i][j] = pick || nonpick;
            }
        }
        return dp[n][sum];
    }
};
