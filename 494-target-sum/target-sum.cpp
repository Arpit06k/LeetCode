class Solution {
public:
    // int f(vector<int>& a,int tar,int idx,vector<vector<int>>&dp){
    //     if(idx==0){
    //         if (a[0] == 0 && tar == 0) return 2;
    //         if (a[0] == tar || -a[0] == tar) return 1;
    //         return 0;
    //     }
    //     if(dp[idx][tar]!=-1)return dp[idx][tar];
    //     int left=f(a,tar-a[idx],idx-1,dp);
    //     int right=f(a,tar+a[idx],idx-1,dp);
    //     return dp[idx][tar]=left+right;
    // }
     map<pair<int,int>, int> memo;

    int f(vector<int>& a, int tar, int idx) {
        if (idx == 0) {
            if (a[0] == 0 && tar == 0) return 2;
            if (a[0] == tar || -a[0] == tar) return 1;
            return 0;
        }
        
        pair<int,int> key = {idx, tar};
        if (memo.find(key) != memo.end()) return memo[key];

        int left = f(a, tar - a[idx], idx - 1);
        int right = f(a, tar + a[idx], idx - 1);
        return memo[key] = left + right;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
         return f(nums, target, n- 1);
    }
};