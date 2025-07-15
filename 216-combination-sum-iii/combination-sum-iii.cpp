class Solution {
public:
void printF(int k,int cnt,int idx ,int sum,int n,vector<int>&nums,vector<vector<int>>& ans ,vector<int>& ds){
       
        if(cnt==k){
            if(sum==n){
                ans.push_back(ds);
            
            }
            return;
        }
 if (idx >= nums.size() || sum > n || cnt > k) return;
    ds.push_back(nums[idx]);
    sum+=nums[idx];
    printF(k,cnt+1,idx+1,sum,n,nums,ans,ds);
    ds.pop_back();
    sum-=nums[idx];
    printF(k,cnt,idx+1,sum,n,nums,ans,ds);

}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums;
        for(int i=1;i<=9;i++){
            nums.push_back(i);
        }
        vector<vector<int>>ans;
        vector<int>ds;
        printF(k,0,0,0,n,nums,ans,ds);
        return ans;
    }
};