// Print the decoded string without bracket :
// Sample input 1 :
// 3a2b3ab
// Sample output 1 :
// aaabbabab

// Code :
#include<bits/stdc++.h>
using namespace std;
void modifystring(string s)
{
    int n = s.length();
    string res = "";
    int count = 0;
    for(int i=0;i<n;i++)
    {
        count = 0;
        if(isdigit(s[i]))
        {
            count = s[i] - '0';
            string group;
            while(i+1<n && isalpha(s[i+1]))
            {
                group += s[i+1];
                i++;
            }
            for(int j=0;j<count;j++)
            {
                res = res.append(group);
            }
        }
        else if(isalpha(s[i]))
        {
            res.push_back(s[i]);
        }
    }
    cout<<res;
}
int main()
{
    string s;
    cin>>s;
    modifystring(s);
}
