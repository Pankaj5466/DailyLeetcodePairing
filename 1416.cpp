class Solution {
public:
    typedef long long ll;
    ll mod=1e9+7;
    int d;
    string s;
    ll dp[100001];
    int numberOfArrays(string s, int k) {
        this->s=s;
        memset(dp, -1, sizeof(dp));
        d=log10(k)+2;
        
        return solve(k);
    }
    
    int solve(ll k, int idx=0) {
        if(idx>=s.size()){
            return 1;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        ll sum=0;
        ll ans=0;
        for(int i=idx;i<min((int)s.size(), idx+d);++i){
            sum=sum*10+s[i]-'0';
            if(sum==0){
                break;
            }
            if(sum>k){
                break;
            }
            ans+=solve(k, i+1);
            ans%=mod;
        }
        
        return dp[idx]=ans;
        
    }
};