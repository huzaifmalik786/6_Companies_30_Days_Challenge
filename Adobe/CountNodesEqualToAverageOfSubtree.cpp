//link to solution: https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/submissions/878788829/


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

    pair<int,int> solve(TreeNode* root, int& ans){
        if(root==NULL){
            return {0,0};
        }
        pair<int,int> left= solve(root->left, ans);
        pair<int,int> right= solve(root->right,ans);
        if(root->val==(left.first+right.first+root->val)/(left.second+right.second+1)){
            ans++;
        }
        return {left.first+right.first+root->val,left.second+right.second+1};
    }

    int averageOfSubtree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ans=0;
        solve(root,ans);
        return ans;
    }
};
