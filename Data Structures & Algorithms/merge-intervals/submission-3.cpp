class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1)
            return intervals;
        
        auto startsEarly = [](const vector<int>& i1, const vector<int>& i2)
        {
            if(i1[0] != i2[0])
                return i1[0] <= i2[0];

            return i1[1] <= i2[1];
        };

        std::sort(intervals.begin(), intervals.end(), startsEarly);

        int i = 0;

        while(i < intervals.size() - 1)
        {
            if(intervals[i][1] >= intervals[i+1][0])
            {
                //vector<int> temp(2);
                //temp[0] = std::min(intervals[i][0], intervals[i+1][0]);
                //temp[1] = std::max(intervals[i][1], intervals[i+1][1]);
                //intervals[i] = temp;
                
                intervals[i][0] = std::min(intervals[i][0], intervals[i+1][0]);
                intervals[i][1] = std::max(intervals[i][1], intervals[i+1][1]);

                intervals.erase(intervals.begin() + i + 1);
                continue;
            }

            i++;
        }

        return intervals;
    }
};
