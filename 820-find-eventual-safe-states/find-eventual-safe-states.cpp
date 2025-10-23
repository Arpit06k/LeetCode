class Solution {
public:
    bool dfs(int node,int n,vector<vector<int>>& graph,vector<int>&vis,vector<int>&pathvis,vector<int>&safe){
        vis[node]=1;
        pathvis[node]=1;

        for(auto it: graph[node]){
            if(!vis[it]){
                if(dfs(it,n,graph,vis,pathvis,safe)==true){
                    return true;
                }
            }
            else if(pathvis[it]){
                return true;
            }
        }
        safe[node]=1;
        pathvis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);

        vector<int>ans;
        vector<int>safe(n,0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,n,graph,vis,pathvis,safe);
            }
        }

        for(int i=0;i<n;i++){
            if(safe[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};