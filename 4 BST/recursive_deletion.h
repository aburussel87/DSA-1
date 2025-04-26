#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return nullptr;
        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        // found the node to be deleted
        else
        {
            // case 1-->node has no child
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root;
                return nullptr;
            }
            // case 2-->node has single child
            if (root->left == nullptr)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            if (root->right == nullptr)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            // case 3--> node has both child
            if (root->left != nullptr && root->right != nullptr)
            {
                // find the min of right subtree
                TreeNode *min = root->right;
                while (min->left != nullptr)
                {
                    min = min->left;
                }
                root->val = min->val;
                root->right = deleteNode(root->right, min->val);
            }
        }
        return root;
    }
};