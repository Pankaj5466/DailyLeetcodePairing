class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int ans=0, l=0, cnt=0;
        for(int r=0;r<nums.size();++r){
            cnt+=nums[r]==0;
            while(cnt>1){
                cnt-=(nums[l++]==0);
            }
            ans=max(ans, r-l);
        }
        
        return ans;
    }
};