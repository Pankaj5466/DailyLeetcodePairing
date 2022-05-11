class Solution {
public:
    typedef long long ll;
    string largestMultipleOfThree(vector<int>& digits) {
        vector<int> cnt(10);
        int sum=0;
        string ans;
        for(int x:digits){
            cnt[x]++;
            sum+=x;
        }
        bool done=false;        
        if(sum%3==1){
            int x=getOne(cnt, 1);
            if(x!=INT_MAX){
                cnt[x]--;
                sum-=x;
                done=true;
            }
            if(!done){
                int x=getTwo(cnt, 1);
                if(x==INT_MAX){
                    return "";
                }
                cnt[x%10]--;
                cnt[x/10]--;
                sum-=x%10+x/10;
                done=true;
            }
        }
        else if(sum%3==2){
            int x=getOne(cnt, 2);
            if(x!=INT_MAX){
                cnt[x]--;
                done=true;
                sum-=x;
            }
            if(!done){
                int x=getTwo(cnt, 2);
                if(x==INT_MAX){
                    return "";
                }
                cnt[x%10]--;
                cnt[x/10]--;
                sum-=x%10+x/10;
                done=true;
            }            
        }
        else{
            done=true;
        }
        if(accumulate(cnt.begin(), cnt.end(), 0)==0 || !done){
            return "";
        }
        if(sum==0){
            return "0";
        }
        return get(cnt);
        
    }
    
    string get(vector<int>& cnt){
        string res("");
        for(int i=10;i--;){
            if(cnt[i]<=0){
                continue;
            }
            res=res+string(cnt[i], char('0'+i));
        }
        return res;
    }
    
    int getTwo(vector<int>& cnt, int sum){
        
        int res=INT_MAX;
        for(int i=1;i<10;++i){
            if(cnt[i]>1 && 2*i%3==sum){
                res=min(res, i*10+i);
            }
            for(int j=1;j<i;++j){
                if(cnt[i] && cnt[j] && (i+j)%3==sum){
                    res=min(res, i*10+j);
                }
            }
        }

        return res;
        
    }
    
    int getOne(vector<int>& cnt, int sum){
        
        for(int i=1;i<10;++i){
            if(cnt[i]>0 && i%3==sum){
                return i;
            }
        }
        return INT_MAX;
        
    }
    
    
};