#include<bits/stdc++.h>
using namespace std;
struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
void inorder(TreeNode* root,int& k,int& result)
{
    if(!root) return;
    
    inorder(root->left,k,result);
    k--;
    if(k==0)
    {
        result = root->val;
        return;
    }
    inorder(root->right,k,result);
}
int findKthSmallest(TreeNode* root,int k)
{
    int result = -1;
    inorder(root,k,result);
    return result;
}
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
int main()
{
    vector<int>nums = {1,2,3,4,5,6,7,8};
    TreeNode* root = nullptr;
    for(const auto& num : nums)
    {
        root = constructBST(root,num);
    }
    int k;
    cin>>k;
    int res = findKthSmallest(root,k);
    cout<<"Kth smallest element : "<<res;
}
