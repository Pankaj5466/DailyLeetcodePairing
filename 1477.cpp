class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        
        int sum=0;
        int ans=INT_MAX;
        set<pair<int, int> > seg; 
        unordered_map<int, int> idx;
        idx[0]=-1;
        int minm=INT_MAX;
        for(int i=0;i<arr.size();++i){
            sum+=arr[i];
            int rem=sum-target;
            if(idx.find(rem)!=idx.end()){
                int l=idx[rem]+1, r=i;
                for(auto e:seg){
                    if(e.first>=l){
                        break;
                    }
                    ans=min(ans, r-l+1+e.first-e.second+1);
                }
                if(r-l+1<minm){
                    seg.insert(make_pair(r, l));
                    minm=r-l+1;
                }
            }
            idx[sum]=i;
        }
        
        return ans==INT_MAX?-1:ans;
        
    }
};

/*
pre[i]-pre[j]=subarray sum from [j+1, i]

pre[i]-pre[j]=target
pre[i]-target = pre[j]

*/

class Solution {
public:
    typedef long long ll;
    int minSumOfLengths(vector<int>& arr, int target) {
        
        int sum=0;
        ll ans=INT_MAX;
        vector<ll> seg(arr.size()+1, INT_MAX); 
        unordered_map<int, int> idx;
        idx[0]=0;
        int minm=INT_MAX;
        for(int i=1;i<=arr.size();++i){
            sum+=arr[i-1];
            int rem=sum-target;
            if(idx.find(rem)!=idx.end()){
                seg[i]=i-idx[rem];
                ans=min(ans, seg[i]+seg[idx[rem]]);
            }
            seg[i]=min(seg[i], seg[i-1]);
            idx[sum]=i;
        }
        
        return ans==INT_MAX?-1:ans;
        
    }
};

/*
pre[i]-pre[j]=subarray sum from [j+1, i]

pre[i]-pre[j]=target
pre[i]-target = pre[j]

*/