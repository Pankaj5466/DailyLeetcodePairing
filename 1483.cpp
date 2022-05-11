

class TreeAncestor {
public:
    
    /*
    
    1, 2, 3, 4, 5, 6, 7
    dp[3][2]=3+4+5+6
    dp[3][0]=3
    while(n){
        int k=log2(n);
        n-=1<<k;
        
    }
    
    node, 6-4=2
    node->4=node4
    node4=node4_1
`   2-2=0;
    */

    int dp[50001][32];
    
    TreeAncestor(int n, vector<int>& parent) {
        memset(dp, -1, sizeof(dp));
        
        int ln=log2(n)+2;
        for(int j=0;j<ln;++j){  // 2^0=1, 2^1=2, 
            for(int node=0;node<parent.size();++node){
                /*
                2^j=1 anc on dp[node][j], 
                */
                if(j==0){   // 2^j=2^0=1
                    dp[node][j]=parent[node];
                    continue;
                }
                // node 2^j= ans
                // node 2^(j-1)= nodej_1= 2^(j-1)
                // nodej_1 2^(j-1)= 2^(j-1)= 
                // 2^(j-1)+2^(j-1)=2*2^(j-1)=2^j
                if(dp[node][j-1]!=-1){
                    int nodej_1=dp[node][j-1];
                    dp[node][j]=dp[nodej_1][j-1];
                    // dp[node][j]=dp[node][j-1]+dp[i+(2^j)-1][j-1] for range sum
                }
            }
        }
        
    }
        
    int getKthAncestor(int node, int k) {
        
        /*
        dp[node][1],    dp[node][2],    dp[node][4], dp[node][8].....
        dp[node][j=0], dp[node][j=1], dp[node][j=2], dp[node][j=3]....
        
        dp[node_i][j=0]=parent[node]
        
        */
        while(k){
            int d=log2(k);  //k=5, d=2
            if(node==-1){
                break;
            }
            node=dp[node][d];
            k-=(1<<d);
        }
        
        return node;
        
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */