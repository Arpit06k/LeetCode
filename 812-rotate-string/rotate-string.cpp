class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i=0;i<s.size();i++){
            if(goal[i]==s[0]){
                string r=goal.substr(i)+goal.substr(0,i);
                if(s==r){
                    return true;
                }
              
            }
        }
   return false;
    }
};