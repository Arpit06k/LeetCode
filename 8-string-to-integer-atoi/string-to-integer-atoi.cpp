class Solution {
public:
    string trim(const string& str){
        int start=0;
        while(start<str.size()&&str[start]==' '){
            start++;
        }
        return str.substr(start);
    }
    int myAtoi(string s) {
    string new1=trim(s);
    int idx=0;
    int sign=1;
    if(new1[0]=='+'||new1[0]=='-'){
        if(new1[0]=='-')sign=-1;
        idx=1;
 }
string nums="";
while(idx<new1.size()&&isdigit(new1[idx])){
    nums+=new1[idx];
    idx++;
}
if(nums.empty())return 0;
 try {
            long long num = stoll(nums);
            num *= sign;

            if (num > INT_MAX) return INT_MAX;
            if (num < INT_MIN) return INT_MIN;

            return static_cast<int>(num);
        } catch (const std::out_of_range&) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
}};