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
    //  map<pair<int,int>, int> memo;

    // int f(vector<int>& a, int tar, int idx) {
    //     if (idx == 0) {
    //         if (a[0] == 0 && tar == 0) return 2;
    //         if (a[0] == tar || -a[0] == tar) return 1;
    //         return 0;
    //     }
        
    //     pair<int,int> key = {idx, tar};
    //     if (memo.find(key) != memo.end()) return memo[key];

    //     int left = f(a, tar - a[idx], idx - 1);
    //     int right = f(a, tar + a[idx], idx - 1);
    //     return memo[key] = left + right;
    //              return f(nums, target, n- 1);

    // }
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n=nums.size();

//         vector<vector<int>>dp(n,vector<int>(target+1,0));
//         dp[0][0]=2;
//         for(int i=0;i<=target;i++){
//             if(nums[0]==target ||-nums[0]==target) dp[0][i]=1;
//             else return dp[0][i]=0;
//         }
//     for(int idx=1;idx<n;idx++){
//         for(int tar=0;tar<=target;tar++){
//             int left=dp[idx-1,tar-nums[idx]];
//         int right=dp[idx-1,tar+nums[idx]];
//         return dp[idx][tar]=left+right;
//         }
//     }
// return dp[n-1][target];
//     }
// };



int mod =(int)1e9+7;

int findWays(vector<int> &num, int tar){
     int n = num.size();

    vector<int> prev(tar+1,0);
    
    if(num[0] == 0) prev[0] =2;  // 2 cases -pick and not pick
    else prev[0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=tar) prev[num[0]] = 1;  // 1 case -pick
    
    for(int ind = 1; ind<n; ind++){
        vector<int> cur(tar+1,0);
        for(int target= 0; target<=tar; target++){
            int notTaken = prev[target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = prev[target-num[ind]];
        
            cur[target]= (notTaken + taken)%mod;
        }
        prev = cur;
    }
    return prev[tar];
}

int countPartitions(int n, int d, vector<int>& arr){
    int totSum = 0;
    for(int i=0; i<n;i++){
        totSum += arr[i];
    }
    
    //Checking for edge cases
    if(totSum-d <0 || (totSum-d)%2 ) return 0;
    
    return findWays(arr,(totSum-d)/2);
}

 int findTargetSumWays(vector<int>& nums, int target) {
return countPartitions(nums.size(),target,nums);

 }};