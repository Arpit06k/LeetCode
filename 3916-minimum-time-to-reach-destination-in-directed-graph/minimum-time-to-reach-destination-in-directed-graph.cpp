class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<pair<long long, pair<long long, long long>>>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], {it[2], it[3]}});
        }
        priority_queue<pair<pair<long long, long long>, pair<long long, long long>>,
                       vector<pair<pair<long long, long long>, pair<long long, long long>>>,
                       greater<pair<pair<long long, long long>, pair<long long, long long>>>>
            q;

        q.push({{0, 0}, {0, 0}});
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        while (!q.empty()) {
            auto it = q.top();
            long long time = it.first.first;
            long long curr = it.first.second;
            long long start = it.second.first;
            long long end = it.second.second;

            q.pop();
            if (curr == n - 1)
                return time;

            if (time > dist[curr])
                continue;
            for (auto it : adj[curr]) {
                long long to = it.first;
                long long s = it.second.first;
                long long e = it.second.second;
                if (time > e)
                    continue;
                long long t = max(0LL,s - time);

               long long newtime =time+ t + 1;
                if (newtime < dist[to]) {
                    dist[to] = newtime;
                    q.push({{newtime, to}, {s, e}});
                }
            }
        }
        if (dist[n - 1] != LLONG_MAX) {
            return dist[n - 1];
        } else {
            return -1;
        }
    }
};