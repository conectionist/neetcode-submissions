class Solution {
public:
    vector<int> topoSort(vector<vector<int>> adj)
    {
        int n = adj.size();
        vector<int> inDegree(n, 0);

        for(int i = 0 ; i < n ; i++)
            for(const auto neighbor : adj[i])
                inDegree[neighbor]++;

        queue<int> q;

        for(int i = 0 ; i < n ; i++)
            if(inDegree[i] == 0)
                q.push(i);

        vector<int> topoSortedList;

        while(!q.empty())
        {
            auto current = q.front();
            q.pop();
            topoSortedList.push_back(current);

            for(const auto neighbor : adj[current])
            {
                inDegree[neighbor]--;

                if(inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        return topoSortedList;
    }

    vector<vector<int>> buildAdjancencyList(int n, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> adj(n);

        for(auto& prereq : prerequisites)
            adj[prereq[0]].push_back(prereq[1]);
        
        return adj;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        auto topoSortedList = topoSort(buildAdjancencyList(numCourses, prerequisites));

        return topoSortedList.size() == numCourses;
    }
};
