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
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        UnionFind dsu(m * n);

        int componentCount = m * n;

        vector<pair<int, int>> dirs = {{-1,0},{0,-1},{1,0},{0,1}};

        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j] == '0')
                {
                    componentCount--;
                    continue;
                }

                int currentCell = n * i + j;

                for(auto& [d1, d2] : dirs)
                {
                    int x = i + d1;
                    int y = j + d2;
                    if(x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == '1')
                    {
                        int currentNeighbor = n * x + y;
                        if(dsu.unite(currentCell, currentNeighbor))
                            componentCount--;
                    }
                }
            }

        return componentCount;
    }
};
