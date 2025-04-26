#include<iostream>
using namespace std;
#include<vector>
 //* Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
  right(right) {}
  };
 
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& list) {
        if (root == nullptr) {
            return;
        }

        inorder(root->left, list);
        list.push_back(root->val);
        inorder(root->right, list);
    }
    bool isValidBST(TreeNode* root) {
        bool is = true;
        if (root == nullptr)
            return false;
        vector<int> s;
        inorder(root, s);
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] >= s[i + 1]) {
                is = false;
                break;
            }
        }
        return is;
    }
};