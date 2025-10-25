class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        vector<pair<int, int>> adj[n];
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int, pair<int, int>>> p;
        p.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        while (!p.empty()) {
            auto it = p.front();
            int k1 = it.first;
            int node = it.second.first;
            int dis = it.second.second;
            p.pop();
            for (auto it : adj[node]) {
                int adjnode = it.first;
                int newdis = it.second;

                if (newdis + dis < dist[adjnode] && k1 <= k) {
                    dist[adjnode] = newdis + dis;
                    p.push({k1 + 1, {adjnode, dis + newdis}});
                }
            }
        }
        if (dist[dst] == 1e9)
            return -1;
        else
            return dist[dst];
    }
};