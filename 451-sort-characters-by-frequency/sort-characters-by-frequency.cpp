class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        vector<string>bucket(s.size()+1);
        for(auto& pair:mpp){
            bucket[pair.second]+=string(pair.second,pair.first);
        }
        string result="";
        for(int i=bucket.size()-1;i>=0;i--){
            if(!bucket.empty()){
                result+=bucket[i];
            }
        }

    return result;

    }
};