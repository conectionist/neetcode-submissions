class Solution {
public:
    void sink(vector<vector<char>>& grid, int i, int j)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';

        sink(grid, i-1, j);
        sink(grid, i+1, j);
        sink(grid, i, j-1);
        sink(grid, i, j+1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int islandCount = 0;
        
        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j] == '1')
                {
                    islandCount++;
                    sink(grid, i, j);
                }
            }

        return islandCount;
    }
};
