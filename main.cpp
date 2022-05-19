1444#include<bits/stdc++.h>
using namespace std;


string solve(string s, int k){
  unordered_map<char, int> freq;

  for(auto c: s){
    freq[c]++;
  }

  priority_queue<pair<int, char> > pq;
  queue<pair< char, int> > q;

  for(auto e: freq){
    pq.push(make_pair(e.second, e.first));    
  }
  
  string ans;
  vector<int> idx(256, -1);
  while(!pq.empty()){
    auto e=pq.top();  pq.pop();
    idx[e.second]=ans.size();
    ans.push_back(e.second);
    e.first--;
    q.push( make_pair(e.second, e.first));

    if(q.size()>=k){
        if(q.front().second<=0){
           q.pop();
            continue;
        }
        pq.push(make_pair(q.front().second, q.front().first));
        q.pop();
    }
  }

  if(ans.size()!=s.size()){
    return "";
  }

  return ans;
  
}

int main()
{
    string str = "aabbacc";
    int k = 2;
    cout << solve(str, k) << endl;
    return 0;
}