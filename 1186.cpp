class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n+1), right(n+2);
        left[0]=right[n+1]=-1e7;
        for(int i=1;i<=n;++i){
            left[i]=max(nums[i-1], nums[i-1]+left[i-1]);
        }
        
        for(int i=n;i>=1;--i){
            right[i]=max(nums[i-1], nums[i-1]+right[i+1]);
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;++i){
            ans=max(ans, nums[i-1]);
            ans=max(ans, left[i]);
            ans=max(ans, right[i]);
            ans=max(ans, left[i-1]+right[i]);
            ans=max(ans, left[i-1]+right[i+1]);
            
        }
        
        return ans;
    }
};