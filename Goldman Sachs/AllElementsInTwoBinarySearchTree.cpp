//link to solution: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/submissions/872837284/


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
    vector<int> ans;
    void getelements(TreeNode* root){
        if(root==NULL){
            return;
        }
        ans.push_back(root->val);
        getelements(root->left);
        getelements(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        getelements(root1);
        getelements(root2);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
