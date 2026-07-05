/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0)
            return 0;

        auto startsSooner = [](const Interval& i1, const Interval& i2)
        {
            return i1.start < i2.start;
        };

        std::sort(intervals.begin(), intervals.end(), startsSooner);

        priority_queue<int, vector<int>, std::greater<int>> minHeap;

        minHeap.push(intervals[0].end);

        for(int i = 1 ; i < intervals.size() ; i++)
        {
            auto& currentInterval = intervals[i];
            int firstEnd = minHeap.top();

            if(currentInterval.start >= firstEnd)
                minHeap.pop();
            
            minHeap.push(currentInterval.end);
        }

        return minHeap.size();
    }
};
