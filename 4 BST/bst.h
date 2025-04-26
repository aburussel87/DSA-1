#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    int count;
    int height;
    Node(int value)
    {
        height = 0;
        val = value;
        count = 1;
        left = nullptr;
        right = nullptr;
    }
};
Node* find(Node* node,int val);
//-->Recursive insertion
int upgradeheight(Node *node)
{
    if (node == nullptr)
    {
        return -1;
    }
    int leftheight = upgradeheight(node->left);
    int rightheight = upgradeheight(node->right);
    return node->height = max(leftheight, rightheight) + 1;
}

Node *insertNode(Node *node, int val)
{
    if (node == nullptr)
    {
        return new Node(val);
    }
    if (val < node->val)
    {
        node->left = insertNode(node->left, val);
    }
    else if (val > node->val)
    {
        node->right = insertNode(node->right, val);
    }
    else
    {
        node->count += 1;
    }
    node->height = upgradeheight(node);
    return node;
}

int inRange(Node* root, int start, int end)
{
    if(root == nullptr)
    {
        return 0;
    }
    int count = 0;
    count = count + inRange(root->left,start,end);
    if(root->val>=start && root->val<=end)
    {
        count++;
    }
    count = count + inRange(root->right,start,end);
    return count;
}
//--> Non recursive insertion
// Node *insertNode(Node *node, int val)
// {
//     if (node == nullptr)
//     {
//         node = new Node(val);
//         return node;
//     }

//     Node *temp = node;
//     Node *parent = nullptr;
//     while (temp != nullptr)
//     {
//         parent = temp;
//         if (val < temp->val)
//         {
//             temp = temp->left;
//         }
//         else if (val > temp->val)
//         {
//             temp = temp->right;
//         }
//         else
//         {
//             return node;
//         }
//     }
//     temp = new Node(val);
//     if (val < parent->val)
//     {
//         parent->left = temp;
//     }
//     else
//     {
//         parent->right = temp;
//     }
//     return node;
// }

//-->> Recursive deletion

Node *deleteNode(Node *root, int key)
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
        if (root->count > 1)
        {
            root->count -= 1;
            return root;
        }
        // case 1-->node has no child
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        // case 2-->node has single child
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // case 3--> node has both child
        if (root->left != nullptr && root->right != nullptr)
        {
            // find the min of right sub
            Node *min = root->right;
            while (min->left != nullptr)
            {
                min = min->left;
            }
            root->val = min->val;
            root->count = min->count;
            min->count = 1;
            root->right = deleteNode(root->right, min->val);
        }
    }
    root->height = upgradeheight(root);
    return root;
}

bool subListCheck(Node* node, int arr[], int k)
{
    Node* root = find(node,arr[0]);
    if(root == nullptr)
    {
        return false;
    }
    for(int i = 1; i<k; i++){
        if(arr[i]<root->val) root = root->left;
        else root = root->right; 
        if(!root || root->val != arr[i]) return false;
    }
    return true;
}

#include<vector>
bool isSubSeq(Node* root, int arr[], int k){
    // Get an inorder traversal of the bst
    //Store it in an array
    vector<int> bst;
    InOrder(root,bst);
    int n = bst.size();
    int i = 0; int j = 0;
    while(i < n && j < k){
        if(arr[j] == bst[i]) j++;
        i++;
    }
    if(j == k) return true;
    return false;
}

void InOrder(Node* root, vector<int> &bst){
    if(root == NULL){
        return;
    }
    InOrder(root->left,bst);
    bst.push_back(root->val);
    InOrder(root->right,bst);
}


Node *lca(Node *node, int v , int x)
{
    if (v < node->val && x < node->val)
    {
        return lca(node->left, v, x);
    }
    else if (v > node->val && x > node->val)
    {
        return lca(node->right, v, x);
    }
    else
    {
        return node;
    }
}

// -->>Non recursive deletion

// Node *deleteNode(Node *node, int val)
// {
//     if (node == nullptr)
//     {
//         return nullptr;
//     }
//     Node *temp = node;
//     Node *parent = nullptr;
//     while (temp != nullptr && temp->val != val)
//     {
//         parent = temp;
//         if (val < temp->val)
//         {
//             temp = temp->left;
//         }
//         else if (val > temp->val)
//         {
//             temp = temp->right;
//         }
//     }
//     if (temp == nullptr )
//         return node;
//      if(parent == nullptr){
//      delete temp;
//      return nullptr;
//      }
//     if (temp->left != nullptr && temp->right != nullptr)
//     {
//         //-->replacing with inorder successor

//         Node *t = temp->right;
//         Node *t_parent = temp;
//         while (t->left != nullptr)
//         {
//             t_parent = t;
//             t = t->left;
//         }
//         temp->val = t->val;
//         if (t_parent->left == t)
//         {
//             t_parent->left = t->right;
//         }
//         else
//         {
//             t_parent->right = t->right;
//         }
//         delete t;
//     }
//     else if (temp->left == nullptr || temp->right == nullptr)
//     {
//         Node *child = (temp->left != nullptr) ? temp->left : temp->right;
//         if (parent == nullptr)
//         {
//             return child;
//         }
//         else
//         {
//             if (temp == parent->left)
//             {
//                 parent->left = child;
//             }
//             else
//             {
//                 parent->right = child;
//             }
//         }
//     }
//     else
//     {
//         delete temp;
//         if (parent == nullptr)
//         {
//             return nullptr;
//         }
//     }
//     return node;
// }

Node *find(Node *node, int val)
{
    Node *temp = node;
    while (temp != nullptr)
    {
        if (val < temp->val)
        {
            temp = temp->left;
        }
        else if (val > temp->val)
        {
            temp = temp->right;
        }
        else
        {
            return temp;
        }
    }
    return temp;
}

int largest(Node* root){
    if(root == nullptr){
         return -1;
    }
    Node* temp = root;
    while(temp->right!= nullptr){
        temp = temp->right;
    }
    return temp->val;
}

int secondLargest(Node *root)
{
    if(root == nullptr || (!root->left && !root->right))
    return -1;
    Node* parent  = nullptr;
    Node* max = root;
    while(max->right != nullptr){
        parent = max;
        max = max->right;
    }
    if(max->left){
        return largest(max->left);
    }
    return parent->val;
}


void inOrder(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    inOrder(node->left);
    cout << node->val << " ";
    inOrder(node->right);
}

void preOrder(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    cout << node->val << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void postOrder(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    cout << node->val << " ";
}

void printTree(Node *root)
{
    if (root == nullptr)
    {
        cout << "_";
        return;
    }
    if (root->count > 1)
    {
        cout << root->val << "(" << root->height << ")" << "[" << root->count << "] ";
    }
    else
        cout << root->val << "(" << root->height << ")" << " ";
    if (root->left != nullptr || root->right != nullptr)
    {
        if (root->left != nullptr && root->right != nullptr)
        {
            cout << " (";
            printTree(root->left);
            cout << " , ";
            printTree(root->right);
            cout << ") ";
        }
        else if (root->right == nullptr)
        {
            cout << " (";
            printTree(root->left);
            cout << ",_)";
        }
        else
        {
            cout << " (_,";
            printTree(root->right);
            cout << ") ";
        }
    }
}