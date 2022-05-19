class Solution {
public:
    typedef long long ll;
    ll mod=1e9+7;
    ll dp[501][51][2][2];
    string s1, s2, evil;
    vector<int> lps;
    int findGoodStrings(int n, string s1, string s2, string evil, int idx=0) {
        this->s1=s1;
        this->s2=s2;
        this->evil=evil;
        memset(dp, -1, sizeof(dp));
        ll ans=0;
        kmp();
        return solve(n);
    }
    
    ll solve(int n, int pos=0, int eidx=0, bool l=true, bool r=true){
        if(eidx==evil.size()){
            return 0;
        }
        
        if(pos==n){
            return 1;
        }
        if(dp[pos][eidx][l][r]!=-1){
            return dp[pos][eidx][l][r];
        }
        ll ans=0;
        char from=(l?s1[pos]:'a');
        char to=(r?s2[pos]:'z');
        
        for(char c=from; c<=to;++c){
            int new_eidx=eidx;
            
            while(new_eidx>0 && evil[new_eidx]!=c){
                new_eidx=lps[new_eidx-1];
            }
            if(evil[new_eidx]==c){
                new_eidx++;
            }
            
            ans+=solve(n, pos+1, new_eidx, l&&(c==from), r&&(c==to));
            ans%=mod;
            
        }
        
        return dp[pos][eidx][l][r]=ans;
        
    }
    
    int kmp(){
        int n=evil.size();
        lps.resize(n);
        int len=0;
        for(int i=1;i<n;++i){
            while(len>0 && evil[len]!=evil[i]){
                len=lps[len-1];
            }
            
            if(evil[len]==evil[i]){
                len++;
            }
            lps[i]=len;
        }
        
        return len;
        
    }

};