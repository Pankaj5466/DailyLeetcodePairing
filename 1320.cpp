class Solution {
public:
    
    int dp[301][27][27];
    
    int getDist(char c1, char c2 ){
        int idx=c1-'A';
        int x11=idx/6;
        int y12=idx%6;
        
        idx=c2-'A';
        int x21=idx/6;
        int y22=idx%6;
        
        return abs(x11-x21)+abs(y12-y22);
    }
    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return solve(word, 0, 'Z'+1, 'Z'+1);
        
    }
    
    int solve(string& word, int idx, char f1, char f2){
        if(idx>=word.size()){
            return 0;
        }
        int i1=f1-'A';
        int i2=f2-'A';
        if(dp[idx][i1][i2]!=-1){
            return dp[idx][i1][i2];
        }
        int ans=INT_MAX;
        if(f1!='Z'+1){
            int dist=getDist(word[idx], f1);
            ans=min(ans,dist+solve(word, idx+1, word[idx], f2));
        }else{
            ans=min(ans,solve(word, idx+1, word[idx], f2));
        }
        if(f2!='Z'+1){
            int dist=getDist(word[idx], f2);
            ans=min(ans,dist+solve(word, idx+1, f1, word[idx]));
        }
        else{
            ans=min(ans, solve(word, idx+1, f1, word[idx]));
        }


        return dp[idx][i1][i2]=ans;
    }
};