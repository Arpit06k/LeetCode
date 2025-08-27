class Solution {
public:
    bool check(string& s1,string& s2){
        if(s1.size()!=s2.size()+1)return false;
        int i=0 ;
        int j=0;
        while(i<s1.size()){
            if(s1[i]==s2[j] && j<=s2.size()){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(i==s1.size() && j==s2.size()){
            return true;
        }
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
         sort(words.begin(), words.end(), [](string& a, string& b) {
            return a.size() < b.size();
        });
        int maxi = 1;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (check(words[i],words[prev])) {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};