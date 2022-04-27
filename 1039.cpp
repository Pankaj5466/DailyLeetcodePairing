class Solution {
public:
    unordered_map<long long, int> dp;
    vector<int> values;
    int minScoreTriangulation(vector<int>& values) {
        this->values=values;
        int n=values.size();
        vector<int> idx(n);
        for(int i=0;i<n;++i){
            idx[i]=i;
        }
        
        return _minScoreTriangulation(idx);
    }
    
    int _minScoreTriangulation(vector<int>& idx) {
        
        
        if(idx.size()==3){
            return values[idx[0]]*values[idx[1]]*values[idx[2]];
        }
        long long mask=0;
        for(int i=0;i<idx.size();++i){
            mask^=1ll<<idx[i];
        }
        if(dp.find(mask)!=dp.end()){
            return dp[mask];
        }
        
        vector<int> left, right=idx;
        right.erase(right.begin());
        int ans=values[idx[0]]*values[idx[1]]*values[idx.back()]+_minScoreTriangulation(right);

        left.push_back(idx[0]);
        left.push_back(idx[1]);
        right=idx;
        reverse(right.begin(), right.end());
        right.insert(right.begin(), right.back());
        right.pop_back();


        for(int i=2;i<idx.size()-1;++i){
            left.push_back(idx[i]);
            right.pop_back();
            ans=min(ans, _minScoreTriangulation(left)+_minScoreTriangulation(right));
        }
        
        return  dp[mask]=ans;
    }
};

/*
1, 1, 5, 1, 4
1, 4, 1, 5, 1
*/