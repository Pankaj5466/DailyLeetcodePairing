class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        priority_queue<pair<int, int> > pq;
        vector<int> nums=grid[0], tmp=nums;
        
        for(int i=1;i<grid.size();++i){
            int f=-1, s=-1; getMinTwo(nums, f, s);
            for(int j=0;j<grid[i].size();++j){
                if(f!=j){
                    tmp[j]=grid[i][j]+nums[f];
                }
                else{
                    tmp[j]=grid[i][j]+nums[s];
                }
            }
            nums=tmp;
        }
        
        
        return *min_element(nums.begin(), nums.end());
        
        
    }
    void getMinTwo(vector<int>& nums, int& f, int& s){
        for(int i=0;i<nums.size();++i){
            if(f==-1){
                f=i;
            }
            else if(s==-1){
                s=i;
            }
            else if(nums[i]<nums[s]){
                s=i;
            }
            if(f!=-1 && s!=-1 && nums[f]>nums[s]){
                swap(f, s);
            }
        }
    }
};



