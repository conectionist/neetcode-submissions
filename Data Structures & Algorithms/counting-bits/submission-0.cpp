class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        while(n > 0)
        {
            if(n & 1)
                count++;

            n >>= 1;
        }

        return count;
    }
    
    vector<int> countBits(int n) {
        if(n == 0)
            return {0};

        vector<int> results(n+1, 0);

        for(int i = 1 ; i <= n ; i++)
            results[i] = hammingWeight(i);
        
        return results;
    }
};
