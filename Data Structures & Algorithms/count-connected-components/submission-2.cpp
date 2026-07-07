class Solution {
public:
    vector<vector<int>> buildAdjacencyList(int n, const vector<vector<int>>& edges)
    {
        vector<vector<int>> adj(n);

        for(const auto& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        return adj;
    }

    void bfs(int start, const vector<vector<int>>& adj, vector<bool>& visited)
    {
        queue<int> q;
        q.push(start);

        while(!q.empty())
        {
            auto current = q.front();
            q.pop();
            visited[current] = true;

            for(const auto neighbor : adj[current])
            {
                if(!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        auto adj = buildAdjacencyList(n, edges);
        vector<bool> visited(n, false);
        int count = 0;

        for(int i = 0 ; i < n ; i++)
        {
            if(!visited[i])
            {
                bfs(i, adj, visited);
                count++;
            }
        }

        return count;
    }
};
