class Solution {
public:
    unordered_map<int, int> dp[1001];
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth, int idx=0, int height=0) {
        
        if(idx>=books.size()){
            return 0;
        }
        
        if(dp[idx].find(height)!=dp[idx].end()){
            return dp[idx][height];
        }
        
        int w=0, mx=0, ans=INT_MAX;
        for(int i=idx;i<books.size();++i){
            w+=books[i][0];
            mx=max(mx, books[i][1]);
            if(w<=shelfWidth){
                ans=min(ans, mx+minHeightShelves(books, shelfWidth, i+1, height));
            }
        }
        
        return dp[idx][height]=ans;
    }

};

