class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>mpp1;
          map<char,char>mpp2;
          if(s.size()!=t.size())return false;
          for(int i=0;i<s.size();i++){
            char ch1=s[i];
            char ch2=t[i];
            if(mpp1.count(ch1)){
                if(mpp1[ch1]!=ch2)return false;
            }
            else{
                mpp1[ch1]=ch2;
            }
              if(mpp2.count(ch2)){
                if(mpp2[ch2]!=ch1)return false;
            }
            else{
                mpp2[ch2]=ch1;
            }


          }
          return true;
        
    }
};