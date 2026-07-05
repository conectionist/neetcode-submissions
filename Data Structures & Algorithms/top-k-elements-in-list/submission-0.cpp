class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> minHeap;

        for(int num : nums)
            freq[num]++;

        for(const auto& [num, count] : freq)
        {
            minHeap.push({count, num});

            if(minHeap.size() > k)
                minHeap.pop();
        }

        vector<int> results;
        
        while(!minHeap.empty())
        {
            results.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return results;
    }
};
