class Solution {
public:
int goal(vector<int>& nums, int k){
    int l=0;
    int r=0;
    int n=nums.size();
    int cnt=0;
    map<int,int>mpp;
    while(r<n){
        mpp[nums[r]]++;
        while(l<=r&&mpp.size()>k){
            mpp[nums[l]]--;
            if(mpp[nums[l]]==0){
                mpp.erase(nums[l]);
            }
            l++;
        }
        cnt+=(r-l+1);
        r++;
    }
    return cnt;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return goal(nums,k)-goal(nums,k-1);
    }
};