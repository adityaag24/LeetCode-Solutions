/* Given various coins of denominations in a vector coins and the amount for which we need to give the change,
find the minimum number of coins required to give that change.
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int t[coins.size()+1][amount+1]; //Create matrix to fill values
        for(int i=0;i<=coins.size();i++){
            t[i][0] = 0;//Initialize the matrix such that for amount=0, no way we can give a change
        }
        for(int i=0;i<=amount;i++){
            t[0][i] = INT_MAX-1;//Initialize the matrix such that if we do not have denominations, we require an infinite amount of coins to get them.
        }
        for(int i=1;i<=coins.size();i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j){//If we can use coin with denomination coins[i-1] for amount j
                    t[i][j] = min(1+t[i][j-coins[i-1]],t[i-1][j]);//Either use it and check for other subproblem or do not take it.
                }else{
                    t[i][j] = t[i-1][j];//If we cant use it, we need to exclude it.
                }
            }
        }
        return (t[coins.size()][amount] >= 2147483646)?-1:t[coins.size()][amount];//Return -1 if solution is INT_MAX-1 or no. of coins in case of solution exists.
    }
};