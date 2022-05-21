class Solution {
public:
    int in[16];
    int dp[1<<15];
    vector<int> g[16];
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        memset(in, 0, sizeof(in));
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<relations.size();++i){
            in[relations[i][1]]++;
            g[relations[i][0]].push_back(relations[i][1]);
        }
        
        int mask=(1<<(n))-1, cnt=0;
        for(int i=1;i<=n;++i){
            if(g[i].size()==0 && in[i]==0){
                mask^=(1<<(i-1));
                cnt++;
            }
        }
        
        return solve(mask, k, n, cnt);
        
    }
    
    int solve(int h, int k, int n, int cnt){
        
        if(__builtin_popcount(h)==0){
            return cnt/k+(cnt%k!=0);
        }
        if(dp[h]!=-1){
            return dp[h];
        }
        
        vector<int> courses;
        for(int i=1;i<=n;++i){
            if(in[i]==0 && (h&(1<<(i-1)))){
                courses.push_back(i);
            }
        }
        int ans=INT_MAX;
        
        if(courses.size()<=k){
            for(auto u: courses){
                for(int v:g[u]){
                    in[v]--;
                }
                h^=(1<<(u-1));
            }
            int newcnt=cnt-(k-courses.size());
            ans=min(ans, 1+solve(h, k, n, max(0, newcnt)));
            
            for(auto u: courses){
                for(int v:g[u]){
                    in[v]++;
                }
                h^=(1<<(u-1));
            }
            
            return dp[h]=ans;
        }
        
        for(int mask=1;mask<(1<<courses.size());++mask){
            if(__builtin_popcount(mask)>k){
                continue;
            }
            vector<int> cur;
            for(int i=0;i<courses.size();++i){
                if(mask&(1<<i)){
                    cur.push_back(courses[i]);
                }
            }
            
            for(auto u: cur){
                for(int v:g[u]){
                    in[v]--;
                }
                h^=(1<<(u-1));
            }
            
            int newcnt=cnt-(k-cur.size());
            ans=min(ans, 1+solve(h, k, n, max(0, newcnt)));
            
            for(auto u: cur){
                for(int v:g[u]){
                    in[v]++;
                }
                h^=(1<<(u-1));
            }
            
        }
        
        return dp[h]=ans;
    }
};