class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> appearances;

        for(auto num : nums)
            if(appearances.contains(num))
                return true;
            else
                appearances.insert(num);

        return false;
    }
};