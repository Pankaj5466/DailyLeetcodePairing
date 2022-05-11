

//#ifdef cc 1
class Solution {
public:
   /* void print(stack<char> st)
    {
        while(!st.empty())
        {
            char ch=st.top();
            cout<<ch;
            st.pop();
        }
        cout<<endl;
    }*/
    bool backspaceCompare(string s, string t)
    {
     string s1; //good make it string
     string s2;
       for(int i=0;i<s.length();i++)
       {
           if(s[i]!='#')
            s1.push_back(s[i]);
           else if(!s1.empty())
             s1.pop_back(); //BUG1: what happen if there is no char??
         // ex:  ##pc
       }
      /* cout<<"Printing s1"<<endl;
       print(s1);
       cout<<endl;*/
       for(int i=0;i<t.length();i++)
       {
           
            if(t[i]!='#')
             s2.push_back(t[i]);
          else if(!s2.empty())
             s2.pop_back();
       }
      /* cout<<"Printing s2:"<<endl;
       print(s2);
       cout<<endl;*/
     
       
          return s1 == s2;
    }
};