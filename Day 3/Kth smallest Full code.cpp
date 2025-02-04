#include<bits/stdc++.h>
using namespace std;
struct TreeNode 
{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode* createBST(TreeNode* root,int ele)
{
    if(root == nullptr)
    {
        return new TreeNode(ele);
    }
    else 
    {
        if(ele < root->val)
        {
            root->left = createBST(root->left,ele);
        }
        else if(ele > root->val) 
        {
            root->right = createBST(root->right,ele);
        }
    }
    return root;
}
void inorder(TreeNode* root,int& result,int& k)
{
    if(!root) return;
    
    inorder(root->left,result,k);
    k--;
    if(k==0)
    {
        result = root->val;
    }
    inorder(root->right,result,k);
}
int findKthSmallest(TreeNode* root,int k)
{
    if(!root) return 0;
    int result = -1;
    inorder(root,result,k);
    return result;
}
int main()
{
    TreeNode* root = nullptr;
    vector<int>nums = {5,3,6,2,4,-1,-1,1};
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]!=-1)
            root = createBST(root,nums[i]);
    }
    int k = 3;
    int result = findKthSmallest(root,k);
    cout<<result;
}
