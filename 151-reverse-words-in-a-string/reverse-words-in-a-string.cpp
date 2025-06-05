class Solution {
public:
    string reverseWords(string s) {
       int i=s.size()-1;
       string word="";
       string result="";
       while(i>=0){
        while(i>=0&&s[i]==' '){
            i--;
        }
        if(i<0)break;
        word="";
        while(i>=0&&s[i]!=' '){
            word=s[i]+word;
            i--;
        }
        if(!result.empty()){
            result+=" ";
        }
        result+=word;
       }
     
       return result ;
    }
    
};