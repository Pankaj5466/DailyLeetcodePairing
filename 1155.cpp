class SolutionTwo {
public:
    long long mod=1e9+7, dp[31][1001];
    int numRollsToTarget(int n, int k, int target) {
        
        memset(dp, 0, sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=n;++i){
            for(int sum=target;sum>=1;--sum){
                for(int face=1;face<=k;++face){
                    if(sum<face){
                        continue;
                    }
                    dp[i][sum]+=dp[i-1][sum-face];
                    dp[i][sum]%=mod;
                }
            }
        }
        
        return dp[n][target];
                
    }
    
};