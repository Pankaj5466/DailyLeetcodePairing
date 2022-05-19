class Solution {
public:
    typedef long long ll;
    int sum[55][55];
    ll dp[55][55][11], mod=1e9+7;
    int ways(vector<string>& pizza, int k) {
        memset(dp, -1, sizeof(dp));
        for(int i=pizza.size();i--;){
            for(int j=pizza[i].size();j--;){
                sum[i][j]=(pizza[i][j]=='A') + sum[i][j+1]+sum[i+1][j]-sum[i+1][j+1];
            }
        }
        return solve(pizza, k);
    }
    
    int solve(vector<string>& pizza, int k, int i=0, int j=0){
        
        if(i>=pizza.size() || j>=pizza[i].size()){
            return 0;
        }
        
        if(k>sum[i][j]){
            return 0;
        }
        if(k==1){
            return 1;
        }
        
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        
        ll ans=0;
        for(int idx=i;idx<pizza.size()-1;++idx){
            int cnt=sum[i][j]-sum[idx+1][j];
            if(cnt==0){
                continue;
            }
            ans+=solve(pizza, k-1, idx+1, j);
            ans%=mod;
        }
        
        for(int jdx=j;jdx<pizza[i].size();++jdx){
            int cnt=sum[i][j]-sum[i][jdx+1];
            if(cnt==0){
                continue;
            }
            ans+=solve(pizza, k-1, i, jdx+1);
            ans%=mod;
        }
        
        return dp[i][j][k]=ans;
    }
};