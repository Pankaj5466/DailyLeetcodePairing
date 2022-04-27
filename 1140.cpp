class Solution {
public:
    int dp[102][102], sums[102];
    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        memset(sums, 0, sizeof(sums));
        for(int i=piles.size();i--;){
            sums[i]=sums[i+1]+piles[i];
        }
        
        return solve(piles);
    }
    
     int solve(vector<int>& piles, int idx=0, int m=1){
         
         if(idx>=piles.size()){
             return 0;
         }
         if(dp[idx][m]!=-1){
             return dp[idx][m];
         }
                  
         int ans=0, sum=0;

         for(int i=idx;i<piles.size() && i<idx+2*m;++i){
             sum+=piles[i];
             ans=max(ans, sum+sums[i+1]-solve(piles, i+1, max(m, i-idx+1)));
         }
         
         return dp[idx][m]=ans;
         
     }
    
};