#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode* constructTree(vector<int>& preorder,int preStart,int preEnd,
                        vector<int>& inorder,int inStart,int inEnd,
                        unordered_map<int,int>& inorderIndex)
{
    if(preStart > preEnd || inStart > inEnd) return nullptr;
    
    TreeNode* root = new TreeNode(preorder[preStart]);
    
    int rootIndex = inorderIndex[root->val];
    int lefTreeSize = rootIndex - inStart;
    
    root->left = constructTree(preorder,preStart+1,preStart+lefTreeSize,inorder,inStart,rootIndex-1,inorderIndex);
    root->right = constructTree(preorder,preStart+lefTreeSize+1,preEnd,inorder,rootIndex+1,inEnd,inorderIndex);
    
    return root;
}
TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder)
{
    unordered_map<int,int>inorderIndex;
    for(int i=0;i<inorder.size();i++)
    {
        inorderIndex[inorder[i]] = i;
    }
    int preIndex = preorder.size()-1;
    return constructTree(preorder,0,preIndex,inorder,0,inorder.size()-1,inorderIndex);
}
void printIn(TreeNode* root)
{
    if(root == nullptr) return;
    printIn(root->left);
    cout<<root->val<<" ";
    printIn(root->right);
}
void printPre(TreeNode* root)
{
    if(root == nullptr) return;
    cout<<root->val<<" ";
    printPre(root->left);
    printPre(root->right);
}
int main()
{
    vector<int>preorder = {3,9,20,15,7};
    vector<int>inorder = {9,3,15,20,7};
    TreeNode* root = buildTree(preorder,inorder);
    cout<<"Inorder traversal : ";
    printIn(root);
    cout<<endl;
    cout<<"Preorder traversal : ";
    printPre(root);
}
