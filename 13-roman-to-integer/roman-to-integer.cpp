class Solution {
public:
    int romanToInt(string s) {
           unordered_map<char, int> r = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int value=r[s.back()];
    for(int i=s.size()-2;i>=0;i--){
    

        if(r[s[i]]<r[s[i+1]]){
            value=value-r[s[i]];
        }
        else{
            value+=r[s[i]];
        }
    }
    return value;
    }
};