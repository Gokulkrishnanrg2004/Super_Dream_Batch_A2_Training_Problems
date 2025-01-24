#include<bits/stdc++.h>
using namespace std;
struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode* constructTree(TreeNode* root,int num)
{
    if(root == nullptr)
    {
        return new TreeNode(num);
    }
    else 
    {
        if(num < root->val)
        {
            root->left = constructTree(root->left,num);
        }
        else 
        {
            root->right = constructTree(root->right,num);
        }
    }
    return root;
}
TreeNode* findMin(TreeNode* root)
{
    if(root == nullptr) nullptr;
    while(root && root->left)
    {
        root = root->left;
    }
    return root;
}
TreeNode* findMax(TreeNode* root)
{
    if(root == nullptr) nullptr;
    while(root && root->right)
    {
        root = root->right;
    }
    return root;
}
TreeNode* searchBST(TreeNode* root,int ele)
{
    if(root == nullptr || root->val == ele)
    {
        return root;
    }
    if(ele < root->val)
    {
        return searchBST(root->left,ele);
    }
    else 
    {
        return searchBST(root->right,ele);
    }
}
int main()
{
    vector<int>nums = {4,3,5,2,1,7};
    TreeNode* root = nullptr;
    for(const auto& num : nums)
    {
        root = constructTree(root,num);
    }
    TreeNode* minValue = findMin(root);
    cout<<"Minimum value in BST : "<<minValue->val<<endl;
    TreeNode* maxValue = findMax(root);
    cout<<"Maximum value in BST : "<<maxValue->val<<endl;
    TreeNode* findval = searchBST(root,8);
    if(findval)
    {
        cout<<"Found";
    }
    else
    {
        cout<<"Not found";
    }
}
