class Solution {
    vector<vector<int>> dp;
    int solve(int idx,int m, vector<int>&arr)
    {
        if(idx >= arr.size())
            return 0;
        
    //    cout<<"idx: "<<idx<<endl;
        if(dp[idx][m] != -1)
            return dp[idx][m];
        
        int mStone = 0;
        int cStone = 0;
        int tSum  = 0;
        for(int i=idx;i<arr.size();i++)
            tSum += arr[i];
        
        for(int i=idx;i<idx + 2*m;i++)
        {
            if(i>=arr.size())
                break;
            
            cStone += arr[i];
            tSum = tSum - arr[i]; //<=
            
            int rStone = solve(i+1,max(i-idx+1,m),arr);
            mStone = max(mStone, tSum - rStone + cStone);
            
        }
        return dp[idx][m] = mStone;
    }
public:
    int stoneGameII(vector<int>& arr) {
        dp = vector<vector<int>>(110,vector<int>(110,-1));
        return solve(0,1,arr);
    }
};