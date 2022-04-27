class Solution {
public:
    
    int dp[1002][1002];
    pair<int, pair<int, char> > mem[1002][1002];
    string shortestCommonSupersequence(string str1, string str2) {

        int n1=str1.size(), n2=str2.size();
        for(int i=1;i<=n1;++i){
            dp[i][0]=dp[i-1][0]+1;
            mem[i][0]=make_pair(i, make_pair(0, str1[i-1]));
            // dp[i][0].push_back(str1[i-1]);
            for(int j=1;j<=n2;++j){
                dp[0][j]=dp[0][j-1]+1;
                mem[0][j]=make_pair(0, make_pair(j-1, str2[j-1]));
                // dp[0][j].push_back(str2[j-1]);
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    mem[i][j]=make_pair(i-1, make_pair(j-1, str1[i-1]));
                    // dp[i][j].push_back(str1[i-1]);
                }
                else{
                    if(dp[i-1][j]< dp[i][j-1]){
                        dp[i][j]= dp[i-1][j]+1;
                        mem[i][j]=make_pair(i-1, make_pair(j, str1[i-1]));
                        // dp[i][j].push_back(str1[i-1]);
                    }else{
                        dp[i][j]= dp[i][j-1]+1;
                        mem[i][j]=make_pair(i, make_pair(j-1, str2[j-1]));
                        // dp[i][j].push_back(str2[j-1]);
                    }
                }
            }
        }
        
        string ans("");
        while(n1 || n2){
            ans.push_back(mem[n1][n2].second.second);
            int i=n1;
            n1=mem[n1][n2].first;
            n2=mem[i][n2].second.first;
            if(n1==0){
                reverse(ans.begin(), ans.end());
                return str2.substr(0, n2)+ans;
            }
            if(n2==0){
                reverse(ans.begin(), ans.end());
                return str1.substr(0, n1)+ans;
            }
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};