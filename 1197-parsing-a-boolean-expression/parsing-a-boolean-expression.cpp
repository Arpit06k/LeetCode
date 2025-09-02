class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>st;
        for(char ch:expression){
            if(ch==','||ch=='(') continue;
            if(ch=='t'||ch=='f'||ch=='&'||ch=='|'||ch=='!'){
                st.push(ch);
            }
            else if(ch==')'){
                bool hastrue=false;
                bool hasfalse=false;
                while(st.top()!='&' && st.top()!='|' &&st.top()!='!'){
                   
                     if(st.top()=='f')hasfalse=true;
                    if(st.top()=='t')hastrue=true;
                     st.pop();
                  
                }
                char op=st.top();
                st.pop();
                if(op=='!'){
                    st.push(hastrue?'f':'t');
                }
                else if(op=='&'){
                    st.push(hasfalse?'f':'t');
                }
                else{
                    st.push(hastrue?'t':'f');
                }
            }


        }
        return st.top()=='t';

    }
};