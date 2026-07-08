class Solution {
public:
    void sink(vector<vector<int>>& grid, int i, int j, int& islandSize)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
            return;
        
        grid[i][j] = 0;
        islandSize++;

        sink(grid, i-1, j, islandSize);
        sink(grid, i+1, j, islandSize);
        sink(grid, i, j-1, islandSize);
        sink(grid, i, j+1, islandSize);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int biggestIsland = 0;
        
        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j] == 1)
                {
                    int islandSize = 0;
                    sink(grid, i, j, islandSize);
                    biggestIsland = max(biggestIsland, islandSize);
                }
            }

        return biggestIsland;        
    }
};
