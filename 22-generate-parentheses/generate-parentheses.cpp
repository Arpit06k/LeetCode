class Solution {
public:
void printF(int open,int close,string str,vector<string>& res){
    if(open==0&&close==0){
        res.push_back(str);
        return ;
    }
    if(open>0)
    printF(open-1,close,str+'(',res);
    if(close>open){
          printF(open,close-1,str+')',res);
    }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        printF(n,n,"",res);
        return res;

    }
};