// Leetcode 394 : Decode string 
// Sample input :
// 3[a2[c]]
// Sample output :
// accaccacc

// Code :
class Solution {
public:
    string decodeString(string s) 
    {
        stack<int>numstack;
        stack<char>charstack;
        string temp="";
        string res="";

        for(int i=0;i<s.length();i++)
        {
            int count=0;
            if(s[i]>='0' && s[i]<='9')
            {
                while(s[i]>='0' && s[i]<='9')
                {
                    count = count * 10 + s[i]-'0';
                    i++;
                }
                i--;
                numstack.push(count);
            }
            else if(s[i]==']')
            {
                temp = "";
                count = numstack.top();
                numstack.pop();

                while(charstack.top() != '[')
                {
                    temp = charstack.top()+temp;
                    charstack.pop();
                }
                charstack.pop();

                for(int j=0;j<count;j++)
                {
                    res = res.append(temp);
                }
                for(int j=0;j<res.length();j++)
                {
                    charstack.push(res[j]);
                }
                res = "";
            }
            else 
            {
                charstack.push(s[i]);
            }
        }   
        while(!charstack.empty())
        {
            res = charstack.top() + res;
            charstack.pop();
        }
        return res;
    }
};
