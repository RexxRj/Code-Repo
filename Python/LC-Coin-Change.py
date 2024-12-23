class Solution:

    def solve(self,ind,coins,amount,dp):

        if ind == -1 or amount == 0:
            if amount == 0:
                return 0
            else:
                return 1e9
        if dp[ind][amount] != -1:
            return dp[ind][amount]

        if coins[ind]>amount:
            dp[ind][amount] = self.solve(ind-1,coins,amount,dp)
            return dp[ind][amount]

        dp[ind][amount] = min(1 + self.solve(ind,coins,amount - coins[ind],dp), 
        self.solve(ind-1,coins,amount,dp))
        return dp[ind][amount]

    def coinChange(self, coins: List[int], amount: int) -> int:
        
        dp = [[-1 for _ in range(amount+1)] for _ in range(len(coins))] #Creates independent rows always use
        #dp = [[-1]*(amount+1)]*len(coins) DO NOT USE - Creates shallow copies where each row are same 
        #and any modification of one row changes all rows

        ans = self.solve(len(coins)-1,coins,amount,dp)

        return -1 if ans == 1e9 else ans

