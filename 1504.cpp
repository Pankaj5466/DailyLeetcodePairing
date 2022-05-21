class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        
        int ans=0;
        vector<int> nums(mat[0].size());
        for(int i=0;i<mat.size();++i){
            for(int j=0;j<mat[i].size();++j){
                if(mat[i][j]==0){
                    nums[j]=0;
                    continue;
                }
                nums[j]++;
                
                int res=0, k=j, mnm=nums[k];
                while(k>=0){
                    mnm=min(mnm, nums[k]);
                    ans+=mnm;
                    k--;
                    
                }
            }
        }
        
        return ans;
    }
};

/*
1 1 1
1 1 1

3*2=6

*/