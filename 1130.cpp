class Solution {
public:
    int lr[50][50], dp[50][50];
    int mctFromLeafValues(vector<int>& nums) {
        
        for(int i=0;i<nums.size();++i){
            int mx=nums[i];
            for(int j=i;j<nums.size();++j){
                mx=max(mx, nums[j]);
                lr[i][j]=mx;
            }
        }
        memset(dp, -1, sizeof(dp));
        
        return solve(nums, 0, nums.size()-1);
        
    }
    
    int solve(vector<int>& nums, int l, int r) {
        
        if(l==r){
            return 0;
        }
        
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        
        int ans=INT_MAX;
        for(int i=l;i<r;++i){
            int res=solve(nums, l, i)+solve(nums, i+1, r)+lr[l][i]*lr[i+1][r];
            ans=min(ans, res);
            
        }
        
        return dp[l][r]=ans;
        
    }
};