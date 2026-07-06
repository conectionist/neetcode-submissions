class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1)
            return stones[0];

        priority_queue<int> maxHeap;

        for(int stone : stones)
            maxHeap.push(stone);

        while(maxHeap.size() > 1)
        {
            int heaviest[2];

            for(int i = 0 ; i < 2 ; i++)
            {
                heaviest[i] = maxHeap.top();
                maxHeap.pop();
            }

            if(heaviest[0] > heaviest[1])
                maxHeap.push(heaviest[0] - heaviest[1]);
        }

        return maxHeap.size() == 1 ? maxHeap.top() : 0;
    }
};
