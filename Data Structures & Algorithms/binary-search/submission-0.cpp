class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lower = 0;
        int upper = nums.size() - 1;
        int mid;

        while(lower <= upper)
        {
            mid = lower + (upper - lower)/2;

            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                upper = mid - 1;
            else
                lower = mid + 1;
        }

        return -1;
    }
};
