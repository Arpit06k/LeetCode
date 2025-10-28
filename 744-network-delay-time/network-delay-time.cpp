class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];
        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p;
        p.push({0, k});
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        while (!p.empty()) {
            auto it = p.top();
            int time = it.first;
            int node = it.second;
            p.pop();
            if(time>dist[node]) continue;
            for (auto it : adj[node]) {
                int adjnode = it.first;
                int newtime = it.second;

                if (newtime + time < dist[adjnode]) {
                    dist[adjnode] = newtime + time;
                    p.push({dist[adjnode],adjnode});
                }
            }
        }
        int mini = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9)
                return -1;
            else {
                mini = max(mini, dist[i]);
            }
        }
        return mini;
    }
};