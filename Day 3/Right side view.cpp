#include<bits/stdc++.h>
using namespace std;
struct TreeNode 
{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode* createBinaryTree(vector<int>& arr)
{
    if (arr.empty() || arr[0] == -1) return nullptr;
    
    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*>q;
    q.push(root);
    int i = 1;
    
    while(!q.empty() && i<arr.size())
    {
        TreeNode* current = q.front();
        q.pop();
        
        if(i<arr.size() && arr[i]!=-1)
        {
            current->left = new TreeNode(arr[i]);
            q.push(current->left);
        }
        i++;
        if(i<arr.size() && arr[i]!=-1)
        {
            current->right = new TreeNode(arr[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}
vector<int>rightside(TreeNode* root)
{
    vector<int>result;
    if(!root) return result;
    
    queue<TreeNode*>q;
    q.push(root);
    
    while(!q.empty())
    {
        int size = q.size();
        int rightmost = 0;
        for(int i=0;i<size;i++)
        {
            TreeNode* node = q.front();
            q.pop();
            rightmost = node->val;
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        result.push_back(rightmost);
    }
    return result;
}
int main()
{
    vector<int>nums = {1,2,3,4,-1,-1,-1,5};
    TreeNode* root = createBinaryTree(nums);
    vector<int>result = rightside(root);
    for(auto it : result)
    {
        cout<<it<<" ";
    }
    
}
