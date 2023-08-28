#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int solveMem(vector<int>& coins,int amount,vector<int> &dp){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }
        if(dp[amount]!=-1){
            return dp[amount];
        }
        int mini=INT_MAX;
        for(auto it:coins){
            int ans=solveMem(coins,amount-it,dp);
            if(ans!=INT_MAX){
                mini=min(mini,1+ans);
            }
        }
        return dp[amount]=mini;
    }
int solveTab(vector<int>& nums,int amount){
        vector<int> dp(amount+1,0);
        for(int i=1;i<=amount;i++){
            int mini=INT_MAX;
            for(int it:nums){
                if(i-it>=0){
                    mini=min(mini,dp[i-it]);
                }
            }
            if(mini!=INT_MAX){
                dp[i]=1;
            }
            dp[i]+=mini;
        }
        return dp[amount];
    }
    
// space optimization is not possible because dp[i-it] is not significant 

int coinChange(vector<int>& coins, int amount) {
        // vector<int> dp(amount+1,-1);
        // int t=solveMem(coins,amount,dp);
        int t=solveTab(coins,amount);
        if(t==INT_MAX){
            return -1;
        }
        return t;
    }
int main(){
    vector<int> nums={1,2,5};
    int amount=11;
    cout<<coinChange(nums,amount);
    return 0;
}

