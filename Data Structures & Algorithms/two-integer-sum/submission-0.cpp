class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> complements;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            int& num = nums[i];

            if(!complements.contains(target - num))
                complements[num] = i;
            else
                return {complements[target - num],i};
        }

        return {-1,-1};
    }
};
