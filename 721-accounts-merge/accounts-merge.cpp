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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,int>mpp;
        Disjoint ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mpp.find(mail)==mpp.end()){
                    mpp[mail]=i;
                }
                else{
                    ds.unionbysize(i,mpp[mail]);
                }
            }
        }

        vector<vector<string>>final(n);
        for(auto it:mpp){
            string mail=it.first;
            int node=ds.findparent(it.second);
            final[node].push_back(mail);
        }

        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(final[i].size()==0)continue;
            sort(final[i].begin(),final[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:final[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};