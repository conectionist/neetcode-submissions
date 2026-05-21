class Solution {
public:
    int trap(vector<int>& height) {
        //if(height.empty())
        //    return 0;

        int leftIndex = 0, rightIndex = height.size() - 1;
        int maxLeftWallHeight = 0, maxRightWallHeight = 0;
        int water = 0;

        while(leftIndex < rightIndex)
        {
            if(height[leftIndex] <= height[rightIndex])
            {
                maxLeftWallHeight = max(maxLeftWallHeight, height[leftIndex]);
                water += maxLeftWallHeight - height[leftIndex];
                leftIndex++;
            }
            else
            {
                maxRightWallHeight = max(maxRightWallHeight, height[rightIndex]);
                water += maxRightWallHeight - height[rightIndex];
                rightIndex--;
            }
        }

        return water;
    }
};
