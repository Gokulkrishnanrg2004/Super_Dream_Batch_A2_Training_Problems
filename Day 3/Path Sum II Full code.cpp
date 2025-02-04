#include<bits/stdc++.h>
using namespace std;
struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode* createBinaryTree(vector<int>& nums)
{
    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*>q;
    q.push(root);
    int i = 1;
    
    while(!q.empty() && i<nums.size())
    {
        TreeNode* current = q.front();
        q.pop();
        
        if(i<nums.size() && nums[i]!=-1)
        {
            current->left = new TreeNode(nums[i]);
            q.push(current->left);
        }
        i++;
        if(i<nums.size() && nums[i]!=-1)
        {
            current->right = new TreeNode(nums[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}
void dfs(TreeNode* root,int target,vector<vector<int>>& result,vector<int>& path)
{
    if(!root) return;
    path.push_back(root->val);
    
    if(!root->left && !root->right && root->val == target)
    {
        result.push_back(path);
    }
    dfs(root->left,target - root->val,result,path);
    dfs(root->right,target - root->val,result,path);
    
    path.pop_back();
}
vector<vector<int>> pathsum2(TreeNode* root,int target)
{
    vector<int>path;
    vector<vector<int>>result;
    dfs(root,target,result,path);
    return result;
}
int main()
{
    vector<int>nums = {5,4,8,11,-1,13,4,7,2,-1,-1,5,1};
    TreeNode* root = createBinaryTree(nums);
    int target = 22;
    vector<vector<int>>result = pathsum2(root,target);
    for(auto i : result)
    {
        for(auto j : i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
