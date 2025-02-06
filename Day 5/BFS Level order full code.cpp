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
    if(nums.empty()) return nullptr;
    
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
vector<vector<int>>levelorder(TreeNode* root)
{
    vector<vector<int>>result;
    if(!root) return result;
    
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
    vector<int>nums = {1,2,3,4,5,6};
    TreeNode* root = createBinaryTree(nums);
    vector<vector<int>>result = levelorder(root);
    for(auto i : result)
    {
        for(auto j : i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
