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


//
// https://leetcode.com/problems/maximum-students-taking-exam/
// https://youtu.be/4nHdArZC7BA

// method #1 : memoization, O(m*4^n)
class Solution {
public:
    int rec(const vector<int>& broken, vector<vector<int>>& dp, int m, int n, int prevMask, int row) {
        if (row >= m) //we browsed all row!!
            return 0;

        if (dp[row][prevMask] >= 0)
            return dp[row][prevMask];

        int res = 0;
        for (int currMask = 0; currMask < (1 << n); currMask++) {
            if ((currMask & broken[row]) != 0) //current position seat is broken
				continue;
			if((currMask & (currMask << 1)) != 0) //there exist a student on left side of j  please note:(currMask = j)
                continue;
			
            if ((prevMask & (currMask << 1)) != 0 || (prevMask & (currMask >> 1)) != 0) //previous Mask is above row data [check if there is a student at (i-1,j-1), (i-1,j+1) [ i-1 ] data is in prevMask
                continue;

            int bitCnt = 0; //how many student sit in current row
            for (int t = currMask; t; t &= t - 1)
                bitCnt++;

            res = max(res, rec(broken, dp, m, n, currMask, row + 1) + bitCnt);
        }

        return dp[row][prevMask] = res;
    }

    int maxStudents(vector<vector<char>>& seats) {
        int m = int(seats.size());
        int n = int(seats[0].size());

        vector<int> broken(m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (seats[i][j] == '#')
                    broken[i] |= 1 << j;
            }
        }

        // dp[row][mask]
        vector<vector<int>> dp(m, vector<int>(1 << n, -1));
        return rec(broken, dp, m, n, 0, 0);
    }
};