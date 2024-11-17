#include <iostream>
#include <queue>

using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;
    
    Node(int x)
    {
        this->val = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* createTree(Node* root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    
    if(data == -1)
    {
        return NULL;
    }
    root = new Node(data);
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = createTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = createTree(root->right);
    
    return root;
}

// Level Order Traversal
void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty())
    {
        Node* front = q.front();
        q.pop();
        
        if(front == NULL) { // old level complete traverse
            cout << endl;
            if(!q.empty()) { // queue still has some child nodes
                q.push(NULL);
            }
        }
        else
        {
            cout << front->val << " ";
            if(front->left)
            {
                q.push(front->left);
            }
            if(front->right)
            {
                q.push(front->right);
            }
        }
        
    }
}

// InOrder (LNR)
void inorder(Node* root)
{
    // base case
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// PreOrder (NLR)
void preorder(Node* root)
{
    // base case
    if(root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    inorder(root->left);
    inorder(root->right);
}

// PostOrder (LRN)
void postorder(Node* root)
{
    // base case
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    inorder(root->right);
    cout << root->val << " ";
}

int main() {
    
    Node* root = NULL;
    root = createTree(root);
    // dfs(root);
    inorder(root);
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1








