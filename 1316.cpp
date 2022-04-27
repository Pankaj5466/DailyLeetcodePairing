class Solution {
public:
    typedef long long ll;
    ll dp[2002][2002];
    ll code[300], mod=1e9+7;
    int distinctEchoSubstrings(string text) {
        
        ll mul=1;
        for(int i='a';i<='z';++i){
            code[i]=mul;
            mul*=2;
        }
        
        unordered_set<ll> h;
        for(int i=0;i<text.size();++i){
            ll hash = 5381;
            for(int j=i;j<text.size();j++){
                hash = ((hash << 5) + hash) + text[j];
                hash%=mod;
                dp[i][j]=hash;
            }
        }

        for(int i=0;i<text.size();++i){
            for(int j=i;j<text.size();j++){
                int len=j-i+1;
                if(len&1){
                    continue;
                }
                if(dp[i][i+len/2-1]==dp[i+len/2][j]){
                    h.insert(dp[i][j]);
                }
            }
        }
        
        return h.size();
        
    }
};

/*

abcabcabc

abcabc=abc+abc

bca+bca
cab+cab


leetcodeleetcode

ee= e+e
leetcodeleetcode=leetcode+leetcode

*/