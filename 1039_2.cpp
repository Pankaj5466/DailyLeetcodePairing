    int findAns(int l,int r, vector<int>& arr)
    {
        if(l>=r)
            return 0;
        if(dp[l][r] != 0)
            return dp[l][r];
        
        int mSum = INT_MAX;
        for(int k=l+1;k<r;k++)
        {
            int lSum = findAns(l,k,arr);
            int rSum = findAns(k,r,arr);
            if(lSum == INT_MAX)
                lSum = 0;
            if(rSum == INT_MAX)
                rSum = 0;
            
            int cSum = arr[l] * arr[k] * arr[r];           
            mSum = min(mSum,lSum+rSum+cSum);
        }
        
        int rVal = (mSum == INT_MAX) ? 0:mSum;
        dp[l][r] = mSum;
        
        return rVal;
    }