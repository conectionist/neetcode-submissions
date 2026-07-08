class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<int>> dist(m, vector<int>(n, 0));

        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n ; j++)
                if(grid[i][j] == 2)
                    q.push({i,j});

        auto updateDistance = [&q, &grid, &dist, &m, &n, &count](int ci, int cj, int i, int j)
        {
            if(i >= 0 && j >= 0 && i < m && j < n && grid[i][j] == 1)
            {
                dist[i][j] = dist[ci][cj] + 1;
                q.push({i,j});
                count = max(count, dist[i][j]);
                grid[i][j] = 2;
            }
        };
            
        while(!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();

            updateDistance(i, j, i+1, j);
            updateDistance(i, j, i-1, j);
            updateDistance(i, j, i, j+1);
            updateDistance(i, j, i, j-1);
        }

        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n ; j++)
                if(grid[i][j] == 1)
                    return -1;

        return count;  
    }
};
