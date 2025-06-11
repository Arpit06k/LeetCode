    class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int i=0;
            int j=0;
            int maxlen=0;
            int n=nums.size();
            int zero=0;
            while(j<n){
            
            if(nums[j]==1){
            
                j++;
            }
            else{
                zero++;
                j++;
            }
            
                while(zero>k){
                
                    if(nums[i]==0){
                        zero--;
                    
                    }
                
                    i++;
                    
                
                }
                maxlen=max(maxlen,j-i);
            }
            return maxlen;
        }
    };