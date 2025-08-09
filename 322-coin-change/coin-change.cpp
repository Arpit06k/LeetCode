class Solution {
public:
    // int f(int idx, vector<int>& coin, int amt,vector<vector<int>>& dp) {
    //     int n = coin.size();
    //     if (idx == 0) {
    //         if (amt % coin[idx] == 0)
    //             return amt / coin[idx];
    //         else
    //             return 1e9;
    //     }
    //     if(dp[idx][amt]!=-1)return dp[idx][amt];

    //     int nottake = f(idx - 1, coin, amt,dp);
    //     int take = INT_MAX;
    //     if (coin[idx] <= amt) {
    //         take = 1 + f(idx, coin, amt - coin[idx],dp);
    //     }
    //     return dp[idx][amt]= min(take, nottake);
    //        int ans = f(n-1, coins, amount,dp);
    //     return (ans >= 1e9) ? -1 : ans;
    // }
    int coinChange(vector<int>& coins, int amount) {
       int n = coins.size();
    vector<int>prev(amount+1,0),curr(amount+1,0);
    for (int amt = 0; amt <= amount; amt++) {
        if (amt % coins[0] == 0) {
            prev[amt] = amt / coins[0];
        } else {
            prev[amt] = 1e9; 
        }
    }

    for (int i = 1; i < n; i++) {
        for (int amt = 0; amt <= amount; amt++) {
            int nottake = prev[amt];
            int take = 1e9;
            if (coins[i] <= amt) {
                take = 1 + curr[amt - coins[i]];
            }
            curr[amt] = min(take, nottake); 
        }
        prev=curr;
    }

    int ans = prev[amount];
    return (ans >= 1e9) ? -1 : ans;
    }
};