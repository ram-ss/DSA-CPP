#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// memoization
int solveMem(vector<int>& nums,int i,vector<int>& dp)
    {
        if(i<0)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        return dp[i]=max(nums[i]+solveMem(nums,i-2,dp),solveMem(nums,i-1,dp));
    }
// tabulation
    int solveTab(vector<int>& nums,int n){
        vector<int> dp(n+1,0);
        dp[0]=nums[0];
        if(n==0){
            return dp[0];
        }
        for(int i=1;i<=n;i++){
            int maxi=INT_MIN;
            if(i-2>=0){
                maxi=max(maxi,dp[i-2]+nums[i]);
            }
            maxi=max(maxi,dp[i-1]);
            dp[i]=maxi;
        }
        return dp[n];
    }
// space optimized
int spaceOptimized(vector<int>& nums,int n){
        int cur=nums[0];
        if(n==0){
            return cur;
        }
        int pre=0;
        for(int i=1;i<=n;i++){
            int temp=nums[i]+pre;
            temp=max(temp,cur);
            pre=cur;
            cur=temp;
        }
        return cur;
    }
int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        // int t=solveMem(nums,n-1,dp);
        // int t=solveTab(nums,n-1);
        int t=spaceOptimized(nums,n-1);
        return t;
    }
int main(){
    vector<int> nums={1,2,3,4,5};
    cout<<rob(nums);
    return 0;
}