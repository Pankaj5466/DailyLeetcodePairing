////Additional Solution: https://github.com/bluedawnstar/youtube/blob/master/leetcode/1349%2C%20Maximum%20Students%20Taking%20Exam.cpp
class Solution {
public:
    int mask[9];
    unordered_set<int> all[8];
    int mem[8][1000];
    int maxStudents(vector<vector<char>>& seats) {
        
        memset(mask, 0, sizeof(mask));
        memset(mem, -1, sizeof(mem));
        
        for(int i=0;i<seats.size();++i){
            for(int j=0;j<seats[i].size();++j){
                if(seats[i][j]=='.'){
                    mask[i]|=(1<<j);
                }
            }
        }
        int m=seats.size(), n=seats[0].size();
        
        for(int i=0;i<m;++i){
            for(int mk=1;mk<(1<<n);++mk){
                int tmp=(mk&mask[i]);
                if(tmp&(tmp<<1)){
                    tmp=0;
                }
                all[i].insert(tmp);
            }
        }
    
        int ans=0;
        
        for(int cur: all[0]){
            ans=max(ans, __builtin_popcount(cur)+solve(cur, m, 1));
        }
        
        return ans;
    }
    
    int solve(int cur, int m ,int idx){
        if(idx>=m){
            return 0;
        }
        if(mem[idx][cur]!=-1){
            return mem[idx][cur];
        }
        int ans=0;
        for(int next: all[idx]){
            if((cur&(next<<1)) || (cur&(next>>1))){
                continue;
            }
            ans=max(ans, __builtin_popcount(next)+solve(next, m, idx+1)); 
        }
        
        return mem[idx][cur]=ans;
    }
    
};