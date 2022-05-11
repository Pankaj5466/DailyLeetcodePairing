#define cc if(0)
class Solution {
    vector<vector<int>> g;
    int V;
    
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& arr)
    {
        set<pair<int,int>> mSet;
        for(int i=0;i<arr.size();i++)
        {
            int u = min(arr[i][0],arr[i][1]);
            int v = max(arr[i][0],arr[i][1]);
            //[0,3] , [3,0]
            mSet.insert({u,v});
            V = max(V,max(u,v));
            
        }
        
        this->V  = 100000 + 10;
        //V = V+10;
        g = vector<vector<int>>(V,vector<int>());
        
        for(auto it = mSet.begin(); it != mSet.end(); it++) //u->v, v->u
        {
            int u = it->first;
            int v = it->second;
            
            g[u].push_back(v); //u->v
            g[v].push_back(u); //v->v
        }
      
        
        
     cc   cout<<"Our Graph is ready!!!\n";
        vector<int> visited(V,0);
        for(int i=0;i<V;i++)
        //for(auto it = mSet.begin(); it != mSet.end(); it++)
        {
            //int i = it->first;
            if(visited[i] == true)
                continue;
            
      cc    printf("Connected Componenet at DFS at %d :: ",i);
            vector<int> cVec;
            DFS(i,visited,cVec); //cVec = connectedComponentVector
          //  cout<<"Connectd component is\n";
            sort(cVec.begin(),cVec.end());
            
        #if 0
            for(auto k:cVec)
                cout<<k<<" ";
            cout<<endl;
         #endif   
            if(cVec.size()<1)
                continue;
            
            
            string r;
            for(auto k:cVec)
                r.push_back(s[k]);
            sort(r.begin(),r.end());
            
            for(int i=0;i<cVec.size();i++)
                s[cVec[i]] = r[i]    ;
        }
        
        return s;
    }
    
    void DFS(int u, vector<int> &visited, vector<int>& cVec) //cVec = connectedComponentVector
    {
        if(visited[u] == true)
            return;
        
        visited[u] = true;
        cVec.push_back(u);
        
        //for all child of u
        for(auto v:g[u]) //u->v
        {
            if(visited[v] == false)
                DFS(v,visited,cVec);
        }
    }
};
/*
// ba [0,1]
ab

//ab [0,1]
ba

[1,3] , [3,6], [3,5] 
1->3->5->6 => get all char => sort them => repalce to original index in sorted order
8->78->67
{b,d,c,x,y}
*/