class Solution {
public:
    // int f(int i,int buy,vector<int>&prices,int n,vector<vector<int>>&dp){
    //     if(i==n)return 0;
    //     long long profit=0;

    //     if(dp[i][buy]!=-1) return dp[i][buy];
    //     if(buy==1){
    //         profit=max(-prices[i]+f(i+1,0,prices,n,dp),0+f(i+1,1,prices,n,dp));
    //     }
    //     else{
    //         profit=max(prices[i]+f(i+1,1,prices,n,dp),0+f(i+1,0,prices,n,dp));
    //     }
    //     return profit;
    // }
    // return f(0,1,prices,n,dp);

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));

        dp[n][0] = dp[n][1] = 0;
    long long profit=0;
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                 if(buy==1){
            profit=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
        }
        else{
            profit=max(prices[i]+dp[i+1][1],0+dp[i+1][0]);
        }
        dp[i][buy]= profit;
            }
        }
        return dp[0][1];
    }
};
