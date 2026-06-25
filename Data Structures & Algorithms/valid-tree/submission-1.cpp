class UnionFind
{
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
        else if(rank[rootY] < rank[rootX])
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

private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        UnionFind dsu(n);
        int count = n;
        
        for(const auto& edge : edges)
        {
            if(!dsu.unite(edge[0], edge[1]))
                return false;
            
            count--;
        }

        return count == 1;
    }
};
