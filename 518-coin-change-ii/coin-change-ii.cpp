class Solution {
public:
int f(int idx, vector<int>& coin, int amt,vector<vector<int>>& dp) {
        if (idx == 0) {
            if(amt%coin[0]==0)return 1;
            else return 0;
        }
        if(dp[idx][amt]!=-1)return dp[idx][amt];

        int nottake = f(idx - 1, coin, amt,dp);
        int take = 0;
        if (coin[idx] <= amt) {
            take = f(idx, coin, amt - coin[idx],dp);
        }
        return dp[idx][amt]= take+ nottake;
}
         
    int change(int amount, vector<int>& coins) {
                int n = coins.size();

         vector<vector<int>>dp(n,vector<int>(amount+1,-1));
          int ans = f(n-1, coins, amount,dp);

        return ans;

    }
};