class Solution {
public:
    bool fill(int row,int col ,vector<string>&mat,int n){
        int duprow=row;
        int dupcol=col;
        while(row>=0 && col>=0){
            if(mat[row][col]=='Q')return false;
            row--;
            col--;
        }
 row = duprow;
        col = dupcol;

        while(col>=0){
            if(mat[row][col]=='Q')return false;
            col--;
        }
 row = duprow;
        col = dupcol;

        while(row<n&&col>=0){
            if(mat[row][col]=='Q')return false;
            col--;
            row++;
        }
        return true;
    }



    void solve(int col,vector<string>& mat,vector<vector<string>>&ans,int n){
        if(col==n){
            ans.push_back(mat);
        }
        for(int row=0;row<n;row++){
            if(fill(row,col,mat,n)){
                mat[row][col]='Q';
                solve(col+1,mat,ans,n);
                mat[row][col]='.';      
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>mat(n,string(n,'.'));
       
        solve(0,mat,ans,n);
        return ans;
    }
};