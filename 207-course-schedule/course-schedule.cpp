class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph1(numCourses);
        for (auto it : prerequisites) {
            graph1[it[0]].push_back(it[1]);
        }
    

    vector<int> indegree(numCourses, 0);
    for (int i = 0; i < numCourses; i++) {
        for (auto it : graph1[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {

        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : graph1[node]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
            }
        }


    }
    if(topo.size()==numCourses){
        return true;
    }
    else{
        return false;
    }

}
};