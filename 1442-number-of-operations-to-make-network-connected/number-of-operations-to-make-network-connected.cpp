class Disjoint {
   

public:
 vector<int> rank, parent,size;
    Disjoint(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            size[i]=1;
        }
    }
    int findparent(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findparent(parent[node]);
    }

    void unionbyrank(int u, int v) {
        int ulp_u = findparent(u);
        int ulp_v = findparent(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionbysize(int u, int v) {
        int ulp_u = findparent(u);
        int ulp_v = findparent(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint ds(n);
        int cnt=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findparent(u)==ds.findparent(v)){
                cnt++;
            }
            else{
                ds.unionbysize(u,v);
            }
        }
        int cnt1=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)cnt1++;
        }
        int ans=cnt1-1;
        if(cnt>=ans){
            return ans;
        }
        else{
            return -1;
        }
    }
};