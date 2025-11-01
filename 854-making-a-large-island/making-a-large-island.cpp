class Disjoint {
public:
    vector<int> rank, parent, size;
    Disjoint(int n) {
        rank.resize(n , 0);
        parent.resize(n );
        size.resize(n );
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        Disjoint ds(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;
                int dx[] = {-1, 0, 1, 0};
                int dy[] = {0, 1, 0, -1};
                for (int k = 0; k < 4; k++) {
                    int nr = i + dx[k];
                    int nc = j + dy[k];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {
                        int node = i * n + j;
                        int nextnode = nr * n + nc;
                        ds.unionbysize(node, nextnode);
                    }
                }
            }
        }
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    continue;
                int dx[] = {-1, 0, 1, 0};
                int dy[] = {0, 1, 0, -1};
                set<int> ans;
                for (int k = 0; k < 4; k++) {
                    int nr = i + dx[k];
                    int nc = j + dy[k];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {
                        ans.insert(ds.findparent(nr * n + nc));
                    }
                }
                int total = 0;
                for (auto it : ans) {
                    total += ds.size[it];
                }
                maxi = max(maxi, total+1);
            }
        }
        //all 1
        for(int i=0;i<n*n;i++){
            maxi=max(maxi,ds.size[ds.findparent(i)]);
        }
        return maxi;
    }
};