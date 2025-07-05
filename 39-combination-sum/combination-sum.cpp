class Solution {
public:
    void printF(int i,vector<int>&ds ,vector<int>&nums,vector<vector<int>>&res,int target){
    
        if(i==nums.size()){
            if(target==0){
                res.push_back(ds);
              
            }
              return ;
        }
        if(nums[i]<=target){
             ds.push_back(nums[i]);
        printF(i,ds,nums,res,target-nums[i]);
             ds.pop_back();

        }
         printF(i+1,ds,nums,res,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> res;
        vector<int>ds;
    printF(0,ds,candidates,res,target);
    return res;
    }
};