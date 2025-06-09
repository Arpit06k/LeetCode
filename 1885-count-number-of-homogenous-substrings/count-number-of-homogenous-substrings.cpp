class Solution {
public:
    int countHomogenous(string s) {
          long long cnt=0;
             int MOD = 1e9 + 7;
             int i=0;
             while(i<s.size()){
                int j=i;
                while(j<s.size()&&s[j]==s[i])
                {
                    j++;
                }
                int len = j - i;
            cnt = (cnt + 1LL * len * (len + 1) / 2) % MOD;
            i = j;
             }
                        
            
        
        return cnt;
    
    }
};