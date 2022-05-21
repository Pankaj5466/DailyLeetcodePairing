class Solution {
public:
    typedef long long ll;
    ll dp[101][101];
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(), houses.end());
        memset(dp, -1, sizeof(dp));
        return solve(houses, k);
    }
    
    ll solve(vector<int>& houses, int k, int idx=0){

        if(k==1){
            ll ans=0, mid=(idx+houses.size()-1)/2;;
            for(int i=idx;i<houses.size();++i){
                ans+=abs(houses[i]-houses[mid]);
            }
            return ans;
        }
        
        if(dp[idx][k]!=-1){
            return dp[idx][k];
        }
        ll ans=INT_MAX;
        
        for(int i=idx;i<houses.size();++i){
            int cnt=houses.size()-i-1;
            int res=0, mid=(idx+i)/2;
            for(int j=idx;j<=i;++j){
                res+=abs(houses[j]-houses[mid]);
            }
            if(cnt==k-1){
                ans=min(ans, 1ll*res);
                break;
            }
            else ans=min(ans, res+solve(houses, k-1, i+1));
            
        }
        return dp[idx][k]=ans;
        
    }
};

/*
p =2
1 4 6 7
4-1

***        ***


*/