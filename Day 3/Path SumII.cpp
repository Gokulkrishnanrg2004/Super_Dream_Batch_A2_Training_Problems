/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>>result;
        vector<int>path;
        dfs(root,targetSum,result,path);
        return result;    
    }
};
