class Solution {
public:
    int rec(int amount, int n, vector<int> &coins){
        if(n==0){
            if(amount==0){
                return 0;
            }
            else{
                return 1e9;
            }
        }
        if(coins[n-1]<=amount){
            return min(1+rec(amount-coins[n-1],n,coins),rec(amount,n-1,coins));
        }
        return rec(amount,n-1,coins);
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans=rec(amount,coins.size(),coins);
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }
};
