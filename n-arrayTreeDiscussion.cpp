
struct treeNode{
        vector<Node*> children;
        int val;
        Node(int val):val(val){};
};
typedef treeNode Node;
unordered_map<treeNode*,int> mMap;

int ans = INT_MIN;

int findAns(treeNode *root)
{
    if(root == nullptr)
        return 0;
    if(mMap[root] != INT_MIN)
        return mMap[root];
    
    int mChildVal = INT_MIN;
    
    vector<int> cSum;
    for(auto ch:root->children)
    {
        int val = findAns(ch);
        cSum.push_back(val);
    }
    sort(cSum.begin(),cSum.end(),greater());
    int a= (cSum.size() >= 1) ?cSum[0]:0;
    int b =  (cSum.size() >= 2)?cSum[1]:0; //add index check
    
    if(a<0)
        a=0;
    if(b<0)
        b = 0;
    
    int cVal = root->val + a+ b;
    ans = max(cVal,ans)
    
    mMap[root] = root->val + a;
    return mMap[root];
}