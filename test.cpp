//Are they top-down or bootom-approach difference
//https://leetcode.com/problems/greatest-sum-divisible-by-three/discuss/927253/step-by-step%3A-top-down-greater-bottom-up-greater-optimised-DP-U-should-do-a-recursive-solution-first

int findSubsetV1(int idx,vector<int>&vec,int tSum)
{
    if(idx>=arr.size()) //all index utlizlied => return tSum
    {
       return tSum;  //
        cout<<tSum<<endl;
    }
    
    int in =findSubsetV1(idx+1,arr,tSum+arr[idx]);
    int ex = findSubsetV1(idx+1,arr,tSum);
    
    
}

int findSubsetV2(int idx,vector<int>&vec)
{
    if(idx>=arr.size())
    {
        return 0; //there is no element => tSum should be zero
    }
    
    int in = arr[idx] + findSubsetV2(idx+1,arr);
    int ex = findSubsetV2(idx+1,arr);
    
    cout<<in<<" "<<ex<<endl;
    
}