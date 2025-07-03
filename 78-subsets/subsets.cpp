class Solution {
public:
    void printF(int i,vector<int>&ds ,vector<int>&nums,vector<vector<int>>& res){
         if (i == nums.size()) {
        res.push_back(ds);
        return;
        }
        ds.push_back(nums[i]);
        printF(i+1,ds,nums,res);
        ds.pop_back();
             printF(i+1,ds,nums,res);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
     
          vector<vector<int>> res;
        vector<int>ds;
    printF(0,ds,nums,res);
    return res;
    }
};