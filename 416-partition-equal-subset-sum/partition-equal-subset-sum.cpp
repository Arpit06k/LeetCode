class Solution {
public:
    bool f(int i, vector<int>& a, int sum,vector<vector<int>>&dp) {
        if (sum == 0)
            return true;
        if (i >= a.size() || sum < 0)
            return false;

        if(dp[i][sum]!=-1)return dp[i][sum];
        bool pick =f(i + 1, a, sum - a[i],dp);

    bool nonpick= f(i + 1, a, sum,dp);

        return dp[i][sum]=pick||nonpick;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        if (sum % 2 != 0)
            return false;
        return f(0, nums, sum / 2,dp);
    }
};