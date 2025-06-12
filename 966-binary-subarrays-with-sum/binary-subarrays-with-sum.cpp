class Solution {
public:
int goal1(vector<int>& nums, int goal){
    int l=0;
    int r=0;
    int cnt=0;
    int sum=0;
    int n=nums.size();
    while(r<n){
        sum+=nums[r];
        while(l<=r&&sum>goal){
            sum=sum-nums[l];
            l++;
        }
        cnt+=(r-l+1);
r++;
    }
    return cnt;
}

    int numSubarraysWithSum(vector<int>& nums, int goal) {
    
        
        return goal1(nums,goal)-goal1(nums,goal-1);
    }
};