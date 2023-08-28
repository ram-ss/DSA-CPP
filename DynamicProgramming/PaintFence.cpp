/*https://leetcode.com/discuss/interview-question/2155627/276-paint-fence*/

#include<iostream>
#include<vector>
        using namespace std;

// recursive 
int PaintFence(int n,int k){
  if(n==1){
    return k;
  }
  if(n==2){
    // k+k*(k-1)=>k^2
    return k*k;
  }
  int same=PaintFence(n-2,k);
  int diff=PaintFence(n-1,k);
  return (same+diff)*(k-1);
}
// memoisation 
int PaintFenceMemo(int n,int k,vector<int>& dp){
  if(n==1){
    return k;
  }
  if(n==2){
    // k+k*(k-1)=>k^2
    return k*k;
  }
  if(dp[n]!=-1){
    return dp[n];
  }
  int same=PaintFenceMemo(n-2,k,dp);
  int diff=PaintFenceMemo(n-1,k,dp);
  return dp[n]=(same+diff)*(k-1);
}
// tabulation
int PaintFenceTab(int n,int k){
  vector<int> dp(n+1,0);
  dp[1]=k;
  dp[2]=k*k;
  for(int i=3;i<=n;i++){
    dp[i]=(dp[i-1]+dp[i-2])*(k-1);
  }
  return dp[n];
}
// space optimized
int SpaceOptimized(int n,int k){
  int pre=k;
  int cur=k*k;
  if(n==1){
    return pre;
  }
  for(int i=3;i<=n;i++){
    int temp=(pre+cur)*(k-1);
    pre=cur;
    cur=temp;
  }
  return cur;
}
int main() {
  cout << "Paint Fence" << endl;
  int n=3;
  int k=3;
  cout<<PaintFence(n,k)<<endl;
  vector<int> dp(n+1,-1);
  cout<<PaintFenceMemo(n,k,dp)<<endl;
  cout<<PaintFenceTab(n,k)<<endl;
  cout<<SpaceOptimized(n,k)<<endl;
  return 0;
}