class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>>q;
        if(grid[0][0]==1 || grid[n-1][m-1]==1)return -1;
        q.push({1,{0,0}});
        dist[0][0]=1;

        while(!q.empty()){
            auto it=q.front();
            int dis=it.first;
            int row=it.second.first;
            int col=it.second.second;
            q.pop();
            if (row == n - 1 && col == m - 1) return dis;
            for(int r=-1;r<=1;r++){
                for(int c=-1;c<=1;c++){
                   int  nr=row+r;
                   int  nc=col+c;

                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0 && dis+1<dist[nr][nc]){
                        dist[nr][nc]=1+dis;
                        if(nr==n-1 && nc==m-1 ) return dis+1;
                        q.push({dis+1,{nr,nc}});
                    }
                }
            }
        }

        return -1;
    }
};