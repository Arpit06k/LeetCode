class Solution {
public:
    int maxDepth(string s) {
        int depth=0;
        int d=0;
        for(char ch:s){
            if(ch=='('){
                depth++;
                d=max(d,depth);
            }
            else if(ch==')'){
                depth--;
            }
        }
        return d;
    }
};