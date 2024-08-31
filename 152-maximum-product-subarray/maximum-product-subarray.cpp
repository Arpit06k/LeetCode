class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int n=nums.size();
        int ans=INT_MIN;
        long long pre=1;
        long long suff=1;
        for(int i=0;i<n;i++){
            if(pre==0)
            pre=1;
            if(suff==0)
            suff=1;
            pre=pre*(long long)nums[i];
            suff=suff*(long long)nums[n-i-1];
            ans=max((long long)ans,max(pre,suff));
        }
        return (int)ans;
    }
};