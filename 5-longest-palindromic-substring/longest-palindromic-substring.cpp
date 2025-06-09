class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        int len=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            int low=i;
            int high=i;
            while(low>=0&&high<n&&s[low]==s[high]){
              int      currLen=high-low+1;
                      if (currLen > len) {
                    len = currLen;
                ans=s.substr(low,len);
                      }            
           
              low--;
            high++;

            }
          
        low=i;
        high=i+1;
          while(low>=0&&high<n&&s[low]==s[high]){
int currLen=high-low+1;
                      if (currLen > len) {
                    len = currLen;
                ans=s.substr(low,len);
                      }   
            low--;
            high++;
          }
        }
        return ans;
    }
};