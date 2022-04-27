#include <iostream>
#include <string>
#include<cstring>
#include<map>
#include<vector>
using namespace std;

string rearrangeString(string s, int k) {
  map<int,int> count;
  int size = s.size();

  int mCount = 0;
  for(auto c:s)
    {
      int idx = c-  'a';
      count[idx]++;

      mCount = max(mCount,count[idx]);
    }
  int charCnt = 0;
  for(auto it = count.begin(); it != count.end(); it++)
    {
      if(it->second == mCount)
        charCnt++;
    }
  //Cover not found case
   if((mCount-1)*k+charCnt >size ){
     cout<<"Answer not possible\n";
    return "";
  }
  
  string ans(s.size(),'*');
  
  int idx = 0;

  int j=0;
  int idxCount = 0;
  //while(1)
    {
      for(auto it = count.rbegin(); it != count.rend(); it++)
        {
          char c = it->first + 'a';
          int cx = it->second;

          printf("char = %c, count  = %d\n",c,cx);

          for(int j=0;j<cx;j++)
            {
              ans[idx] = c;
              idx = (idx+k);
              if(idx > size-1)
              {
                idxCount++;
                idx = idxCount;
              }
              printf("tans = %s\n",ans.c_str());
            }
        }
    }
	return ans;
}

int main() {
  cout<<"Enter Main\n";
	string str = "aaadbbcc";
  int k = 3;
  cout<<"Printing Ans\n";
	cout << rearrangeString(str, k) << endl;
	return 0;
}