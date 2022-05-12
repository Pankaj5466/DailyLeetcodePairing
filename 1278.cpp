class Solution {
public:
    int cost[101][101], dp[101][101][101];
    int palindromePartition(string s, int k) {
        
        int n=s.size();
        memset(dp, -1, sizeof(dp));
        for(int len=1;len<=n;++len){
            for(int i=0;i<=n-len;++i){
                int j=i+len-1;
                for(int k=0;k<len/2;++k){
                    cost[i][j]+=(s[i+k]!=s[j-k]);
                }
            }
        }
        
        return solve(0, n-1, k);
    }
    
  
    int solve(int l, int r, int k){
        if(k==1){
            return cost[l][r];
        }
        
        if(r-l+1==k){
            return 0;
        }
        
        if(dp[l][r][k]!=-1){
            return dp[l][r][k];
        }
        
        int ans=INT_MAX;
        for(int idx=l;r-idx+1>=k;++idx){
            ans=min(ans, cost[l][idx]+solve(idx+1, r, k-1));
        }
        
        return dp[l][r][k]=ans;
    }
};