class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n ; j++)
                if(grid[i][j] == 0)
                    q.push({i,j});

        auto updateDistance = [&q, &grid, &m, &n](int ci, int cj, int i, int j)
        {
                if(i >= 0 && j >= 0 && i < m && j < n && grid[i][j] == INT_MAX)
                {
                    grid[i][j] = grid[ci][cj] + 1;
                    q.push({i,j});
                }
        };
            
        vector<pair<int, int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();

            updateDistance(i, j, i+1, j);
            updateDistance(i, j, i-1, j);
            updateDistance(i, j, i, j+1);
            updateDistance(i, j, i, j-1);
            
            // for(auto& [di, dj] : dirs)
            // {
            //     int i = ci + di;
            //     int j = cj + dj;

            //     if(i >= 0 && j >= 0 && i < m && j < n && grid[i][j] == INT_MAX)
            //     {
            //         grid[i][j] = grid[ci][cj] + 1;
            //         q.push({i,j});
            //     }
            // }
        }
    }
};
