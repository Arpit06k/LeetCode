class Solution {
public:
 void printF(int ind,vector<int>&ds ,vector<int>&nums,vector<vector<int>>& res,int target){
            if(target==0){
        res.push_back(ds);
        return;
        }
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1])continue;
            if(nums[i]>target)break;
            ds.push_back(nums[i]);
            printF(i+1,ds,nums,res,target-nums[i]);
            ds.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
          sort(candidates.begin(),candidates.end());
          vector<vector<int>> res;
        vector<int>ds;
    printF(0,ds,candidates,res,target);
    return res;
    }
};