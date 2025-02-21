/*
17. Letter Combinations of a Phone Number
Solved
Medium
Topics
Companies
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 
*/

//LETTER COMBINATION 

#include<bits/stdc++.h>
using namespace std;
vector<string>getAllComb(const string& str,const unordered_map<char,string>& mp)
{
    if(str.empty())
    {
        return {""};
    }
    
    char ch = str[0];
    string rem = str.substr(1);
    
    vector<string>res = getAllComb(rem,mp);
    vector<string>mres;
    
    string digit_str = mp.at(ch);
    for(char c : digit_str)
    {
        for(string s : res)
        {
            mres.push_back(c+s);
        }
    }
    return mres;
}
vector<string>letterComb(string digits)
{
    vector<string>res;
    unordered_map<char,string>mp;
    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";
    if(digits.size() == 0)
    {
        return res;
    }
    else 
    {
        res = getAllComb(digits,mp);
    }
    return res;
}
int main()
{
    string s;
    cin>>s;
    vector<string>res = letterComb(s);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
}
