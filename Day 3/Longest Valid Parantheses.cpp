#include<bits/stdc++.h>
using namespace std;
void findlen(string& s)
{
    stack<int>st;
    st.push(-1);
    int maxlen = 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
            st.push(i);
        else 
        {
            st.pop();
            if(st.empty())
                st.push(i);
            else
                maxlen = max(maxlen,i-st.top());
        }
    }
    cout<<maxlen;
}
int main()
{
    string s = ")()())";
    findlen(s);
}
