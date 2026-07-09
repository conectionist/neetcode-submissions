class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);

        dp[0] = 0;

        for(int currentAmount = 1 ; currentAmount <= amount ; currentAmount++)
            for(int coin : coins)
                if(coin <= currentAmount)
                    dp[currentAmount] = min(dp[currentAmount], dp[currentAmount - coin] + 1);

        if(dp[amount] == amount + 1)
            return -1;

        return dp[amount];
    }
};
