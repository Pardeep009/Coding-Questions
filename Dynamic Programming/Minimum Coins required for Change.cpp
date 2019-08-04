/*
  Problem Link:-> https://leetcode.com/problems/coin-change/
  
  You are given coins of different denominations and a total amount of money amount.
  Write a function to compute the fewest number of coins that you need to make up that amount. 
  If that amount of money cannot be made up by any combination of the coins, return -1.

  Example 1:
  Input: coins = [1, 2, 5], amount = 11
  Output: 3 
  Explanation: 11 = 5 + 5 + 1
 
  Example 2:
  Input: coins = [2], amount = 3
  Output: -1
  
*/

class Solution {
public:
    
    int minchange(vector<int>& coins,int amount,vector<int>& ans)
    {
        ans[0]=0;
        for(int rupay=1;rupay<=amount;rupay++)
        {
            for(int i=0;i<coins.size();i++)
            {
                if(coins[i]<=rupay)
                {
                    int small = ans[rupay-coins[i]];
                    if(small!=INT_MAX)
                    {
                        ans[rupay] = min(small+1,ans[rupay]);
                    }
                }
                else
                    break;
            }
        }
        return ans[amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> ans(amount+1,INT_MAX);
        sort(coins.begin(),coins.end());
        int k = minchange(coins,amount,ans);
        if(k!=INT_MAX)
        {
            return k;
        }
        return -1;
    }
};
