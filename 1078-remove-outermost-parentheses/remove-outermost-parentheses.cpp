
class Solution {

public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string ans;
     
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(c=='('){
                if(!st.empty()){
                    ans+=c;
                }
                st.push(c);
            }
            else{
                st.pop();
                if(!st.empty()){
                    ans+=c;
                }
            }


        }
    return ans;
    }
};