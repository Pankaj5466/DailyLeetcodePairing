class Solution {
public:
    
    typedef long long ll;
    
    unordered_map<string, int> sIdx;
    unordered_map<ll, unordered_map<ll, ll > > dp;
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        
        for(int i=0;i<req_skills.size();++i){
            sIdx[req_skills[i]]=i;
        }
        
        vector<int> pMask;
        
        for(int i=0;i<people.size();++i){
            int mask=0;
            for(int j=0;j<people[i].size();++j){
                mask^=1ll<<sIdx[people[i][j]];
            }
            pMask.push_back(mask);
        }
        ll mask=solve(pMask, (1<<req_skills.size())-1);
        vector<int> ans;
        
        for(int i=0;i<pMask.size();++i){
            if(mask&(1ll<<i)){
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
    
    ll solve(vector<int>& people, int req, int cur=0, int idx=0){
        
        if((req&cur)==req){
            return 0ll;
        }
        if(idx>=people.size()){
            return (1ll<<62)-1;
        }
        
        if(dp[idx].find(cur)!=dp[idx].end()){
            return dp[idx][cur];
        }
        
        ll w=solve(people, req, cur, idx+1), wt=solve(people, req, cur|people[idx], idx+1);
        wt|=(1ll<<idx);
        dp[idx][cur]=(__builtin_popcountll(w)<__builtin_popcountll(wt)?w:wt);
        return dp[idx][cur];
    = }
};

/*

dp[000110011000000][j]=(1ll<<23)

110

*/