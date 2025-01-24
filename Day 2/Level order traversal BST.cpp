#include<bits/stdc++.h>
using namespace std;
struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode* constructBST(TreeNode* root,int ele)
{
    if(root == nullptr)
    {
        return new TreeNode(ele);
    }
    else 
    {
        if(ele < root->val)
        {
            root->left = constructBST(root->left,ele);
        }
        else 
        {
            root->right = constructBST(root->right,ele);
        }
    }
    return root;
}
vector<vector<int>> levelorder(TreeNode* root)
{
    vector<vector<int>>result;
    if(root == nullptr) return result;
    
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int level = q.size();
        vector<int>currentlevel;
        for(int i=0;i<level;i++)
        {
            TreeNode* current = q.front();
            q.pop();
            
            currentlevel.push_back(current->val);
            
            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);
        }
        result.push_back(currentlevel);
    }
    return result;
}
int main()
{
    TreeNode* root = nullptr;
    vector<int>nums = {8,3,10,1,6,14,4,7,13};
    for(const auto& num : nums)
    {
        root = constructBST(root,num);
    }
    vector<vector<int>>result = levelorder(root);
    for(const auto& level : result)
    {
        for(const auto& num : level)
        {
            cout<<num<<" ";
        }
        cout<<endl;
    }
}
