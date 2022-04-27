class Solution {
public:
    int dp[101][101][2];
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        
        memset(dp, 0, sizeof(dp));
        
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[i].size();++j){
                if(grid[i][j]==0){
                    continue;
                }
                
                dp[i+1][j+1][0]=dp[i][j+1][0]+1;
                dp[i+1][j+1][1]=dp[i+1][j][1]+1;
            }
        }
        
        int ans=0;
        for(int i=1;i<=grid.size();++i){
            for(int j=1;j<=grid[i-1].size();++j){
                int n=min(dp[i][j][0], dp[i][j][1]);
                while(n){
                    if(dp[i-n+1][j][1]>=n && dp[i][j-n+1][0]>=n){
                        ans=max(ans, n*n);
                        break;
                    }
                    n--;
                }
            }
        }
        
        return ans;
    }
};

/*
 [[1,1,1, 1]
 ,[1,0,1, 1]
 ,[0,1,1, 1]
 ,[1,1,1, 1]]

[[1,1,0,0]]
*/