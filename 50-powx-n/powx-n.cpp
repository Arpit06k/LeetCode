class Solution {
public:
    double help(double x,long long n){
        if(n==0)return 1;

        double half=help(x,n/2);
        if(n%2==0){
            return half*half;
        }
        else{
            return half*half*x;
        }
    }
    double myPow(double x, int n) {
      long long nn=n;
      if(nn<0){
        x=1/x;
        nn=-nn;
      }
      return help(x,nn);
    }
};