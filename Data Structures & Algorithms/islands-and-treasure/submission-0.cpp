class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        const int INF = INT_MAX;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;

        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n ; j++)
                if(grid[i][j] == 0)
                    q.push({i, j});

        vector<pair<int, int>> directions = 
        {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };

        while(!q.empty())
        {
            auto [ci, cj] = q.front();
            q.pop();

            for(const auto& [di, dj] : directions)
            {
                int i = ci + di;
                int j = cj + dj;

                if(i >= 0 && i < m && j >= 0 && j < n
                && grid[i][j] == INF)
                {
                    grid[i][j] = grid[ci][cj] + 1;
                    q.push({i, j});
                }
            }
        }
    }
};
