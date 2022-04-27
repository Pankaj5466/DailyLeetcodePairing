class Solution {
public:
    typedef long long ll;
    vector<ll> dp[101][101];
    ll mod=1e9+7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        
        int m=board.size(), n=board[0].size();
        vector<ll> tmp=solve(board, m-1, n-1);
        vector<int> ans(2);
        ans[0]=tmp[0];
        ans[1]=tmp[1];
        if(ans[1]==0){
            ans[0]=0;
        }
        return ans;
        
    }
    
    vector<ll> solve(vector<string>& board, int i, int j){
        vector<ll> ans(2);
        if(i<0 || j<0 || board[i][j]=='X'){
            ans[0]=INT_MIN;
            return ans;
        }
        if(i==0 && j==0){
            ans[0]=0; ans[1]=1;
            return ans;
        }
        
        if(dp[i][j].size()==2){
            return dp[i][j];
        }
        vector<ll> res1=solve(board, i-1, j), res2=solve(board, i, j-1), res3=solve(board, i-1, j-1);
        ll mx=max(res1[0], max(res2[0], res3[0]));
        bool added=false;
        if(mx==res1[0]){
            ans[0]+=res1[0];
            ans[1]+=res1[1];
            added=true;
        }
        if(mx==res2[0]){
            if(!added)ans[0]+=res2[0];
            ans[1]+=res2[1];
            added=true;
        }
        if(mx==res3[0]){
            if(!added)ans[0]+=res3[0];
            ans[1]+=res3[1];
        }
        
        if(board[i][j]>='0' && board[i][j]<='9'){
            ans[0]+=board[i][j]-'0';
        }
        ans[1]%=mod;
        
        return dp[i][j]=ans;
    }
};
/*
"E12",
"1X1",
"21S"
*/

