class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int i = 0;
        int j = height.size() - 1;
        int leftMaxWallHeight = height[i];
        int rightMaxWallHeight = height[j];

        while(i <= j)
        {
            if(leftMaxWallHeight <= rightMaxWallHeight)
            {
                leftMaxWallHeight = max(leftMaxWallHeight, height[i]);
                water += leftMaxWallHeight - height[i];
                i++;
            }
            else
            {
                rightMaxWallHeight = max(rightMaxWallHeight, height[j]);
                water += rightMaxWallHeight - height[j];
                j--;
            }
        }

        return water;
    }
};
