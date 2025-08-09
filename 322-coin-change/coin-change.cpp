class Solution {
public:
    int f(int idx, vector<int>& coin, int amt,vector<vector<int>>& dp) {
        int n = coin.size();
        if (idx == 0) {
            if (amt % coin[idx] == 0)
                return amt / coin[idx];
            else
                return 1e9;
        }
        if(dp[idx][amt]!=-1)return dp[idx][amt];

        int nottake = f(idx - 1, coin, amt,dp);
        int take = INT_MAX;
        if (coin[idx] <= amt) {
            take = 1 + f(idx, coin, amt - coin[idx],dp);
        }
        return dp[idx][amt]= min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = f(n-1, coins, amount,dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};