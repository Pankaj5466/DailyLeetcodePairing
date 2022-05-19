class Solution {
public:
    typedef long long ll;
    ll mod=1e9+7;
    vector<ll> topa, topi;
    ll dp[1025][41];
    int numberWays(vector<vector<int>>& hats) {
        topa.resize(10);
        topi.resize(41);
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<hats.size();++i){
            for(int j:hats[i]){
                topa[i]|=(1ll<<j);
                topi[j]=1;
            }
            // bitset<10> b(topa[i]);
            // cout<<b<<endl;
        }
        return solve((1<<hats.size())-1);
    }
    
    ll solve(int logg, int idx=0){
        
        if(logg==0){
            return 1;
        }
        
        if(idx>=topi.size()){
            return 0;
        }
        
        if(dp[logg][idx]!=-1){
            return dp[logg][idx];
        }
        if(topi[idx]==0){
            return solve(logg, idx+1);
        }
        
        ll ans=solve(logg, idx+1);;
        for(int i=0;i<10;++i){
            if((logg&(1<<i))==0){
                continue;
            }
            if(topa[i]&(1ll<<idx)){
                ans+=solve(logg^(1ll<<i), idx+1);
                ans%=mod;
            }
        }
        
        return dp[logg][idx]=ans;
        
        
    }
};