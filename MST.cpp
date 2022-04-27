//https://leetcode.com/problems/min-cost-to-connect-all-points/

int getDistance(vector<int>&p1, vector<int>&p2)
{
    return abs(p1[0]-p2[0]) + abs(p1[1] - p2[1]);
}

void getMinDistanceNodeFromClustor(vector<int> &vec,vector<int>&visited ,int &u, int &w)
{
    u = -1;
    w = INT_MAX;
    
    for(int i=0;i<vec.size();i++)
    {
        if(visited[i] == 1)
            continue;
        if(vec[i] < w) //we found a node, which can be reached in less distance from {cluster} (minimum spanning tree cluster)
        {
            w = vec[i];
            u = i;
        }
    }
}

class Solution {
public:
    //Implementing Primes algorithm
    //Algorithm gist: keep growing your {cluster} group, by adding edge which has minimum weight , when connecting the cluster to some node 'u' (u is not in cluster)
    int minCostConnectPoints(vector<vector<int>>& arr) 
    {
        int V = arr.size();
        vector<int> minDis(V,INT_MAX); //distance to reach i(th) node from created cluster
        vector<int> visited(V,0);
        
        minDis[0] = 0;
        int sum = 0;
        
        int edgeUsed = 0;
        for(int i=0;i<V;i++) //IMPORTANT: either can be used for means => just run the below code V time, in each iteration, we will add ONE node to {cluster}, hence after V iteration, all NODE will be inside the cluster
        //while(edgeUsed < V) //this says, a minimum spaning tree connecting V node, will have V-1 edges
        {
            int u=-1,w=INT_MAX;
            getMinDistanceNodeFromClustor(minDis,visited,u,w); //{node_cluster} [unclustor_node] => {} -(w)-> u
            
            sum += w; //adding node 'u' to {cluster} will cost us w
            //IMPORTANT: understand that x --(w)--> u is the edge, and x is some node inside the cluster 
            
            edgeUsed++; //one more edge is utilized for connecting 'u' to {cluster}
            
            visited[u] = true; //u has been visited
            
            //Now Process all child of u
            for(int v = 0;v<V;v++) //u->v edge
            {
                if(visited[v] == 1)
                    continue; //Node 'v' is already in the {cluster}
                
                int w = getDistance(arr[u],arr[v]); //find the weight from u->v
                
                minDis[v] = min(minDis[v], w); //cost to reach 'v' can be decreased, as new node 'u' is added to {cluster}
            }
        }//edgeCount loop
        return sum;
    }
};