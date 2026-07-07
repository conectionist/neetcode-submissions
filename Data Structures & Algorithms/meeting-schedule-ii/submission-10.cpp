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
        int n = intervals.size();

        if(n < 2)
            return n;

        auto startsEarly = [](const Interval& i1, const Interval& i2)
        {
            return i1.start < i2.start;
        };

        std::sort(intervals.begin(), intervals.end(), startsEarly);

        priority_queue<int, vector<int>, greater<int>> minHeap;

        minHeap.push(intervals[0].end);

        for(int i = 1 ; i < n ; i++)
        {
            int end = minHeap.top();

            if(intervals[i].start >= end)
                minHeap.pop();
            
            minHeap.push(intervals[i].end);
        }

        return minHeap.size();
    }
};
