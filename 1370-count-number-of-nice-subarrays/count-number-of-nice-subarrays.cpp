class Solution {
public:
int goal1(vector<int>& nums, int goal){
    int l=0;
    int r=0;
    int cnt=0;
    int sum=0;
    int n=nums.size();
    while(r<n){
        sum+=nums[r]%2;
        while(l<=r&&sum>goal){
            sum=sum-nums[l]%2;
            l++;
        }
        cnt+=(r-l+1);
r++;
    }
    return cnt;
}

    int numberOfSubarrays(vector<int>& nums, int k) {
         return goal1(nums,k)-goal1(nums,k-1);
    }
};