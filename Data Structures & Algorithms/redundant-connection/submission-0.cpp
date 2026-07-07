class UnionFind
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) : parent(n), rank(n, 0)
    {
        for(int i = 0 ; i < n ; i++)
            parent[i] = i;
    }

    bool unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if(rootX == rootY)
            return false;

        if(rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if(rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }

        return true;
    }

    int find(int x)
    {
        if(x != parent[x])
            parent[x] = find(parent[x]);

        return parent[x];
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> lastEdge;

        unordered_set<int> nodes;
        for(const auto& edge : edges)
        {
            nodes.insert(edge[0]);
            nodes.insert(edge[1]);
        }

        UnionFind dsu(nodes.size());

        for(const auto& edge : edges)
        {
            if(!dsu.unite(edge[0] - 1, edge[1] - 1))
                lastEdge = edge;
        }

        return lastEdge;
    }
};
