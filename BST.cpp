#include<bits/stdc++.h>

using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode *left, *right;
    TreeNode(int x = -1){
        // If x is provided then data = x, otherwise data = -1
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST{
    public
    TreeNode* root;
    // BST Constructor, initializing a BST
    BST(int data = -1){
        this->root = new TreeNode(data);
    }

    // BST: Insert: Insert a data in BST
    TreeNode* insert(int data){
        TreeNode *temp = this->root;
        while(temp->right != NULL and temp->left != NULL){
            if(temp->data == data){
                cout<<"BST already has this value";
                return this->root;
            }
            if(temp->data > data){
                temp = temp->left;
            }else{
                temp = temp->right;
            }
        }
        if(temp->data > data){
            temp->left = new TreeNode(data);
        }else{
            temp->right = new TreeNode(data);
        }
        return this->root;
    }

    // BST : Traversals
    // BST: BFS: Level Order Traversal of a BST (Breadth First Search) (using queue and print level by level)
    void BFS(){
        TreeNode *temp = this->root;
        queue<TreeNode*> q;
        q.push(temp);
        q.push(NULL);
        while(!q.empty()){
            temp = q.front();
            q.pop();
            if(temp == NULL){
                cout<<endl;
                if(!q.empty()) q.push(NULL);
            }else{
                cout<<temp->data<<" ";
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
            }
        }
    }

    // BST : inorder: Inorder Traversal of a BST (Always a sorted sequence)
    void inorder(TreeNode *root = this->root){
        if(root){
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }
    // BST : postorder: Postorder Traversal of a BST (Always a sorted sequence)
    void postorder(TreeNode *root = this->root){
        if(root){
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<" ";
        }
    }
    // BST : preorder: Postorder Traversal of a BST (Always a sorted sequence)
    void preorder(TreeNode *root = this->root){
        if(root){
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    // BST: Search: Returns the address of the node that constains the given value
    TreeNode* search(int val){
        TreeNode * temp = this->root;
        while(temp->left != NULL and temp->right != NULL){
            if(temp->data == val) return temp;
            if(temp->data > val){
                temp = temp->left;
            }else{
                temp = temp->right;
            }
        }
        return NULL;
    }

    // BST : delete: Delete a node with given data from BST
    // BST : inorderSuccessor
    TreeNode* inorderSuccessor(TreeNode* node) {
        if (node == NULL) return NULL;
        if (node->right != NULL) {
            node = node->right;
            while (node->left != NULL)
                node = node->left;
            return node;
        }
        return NULL; // if nothing to the right of node
    }
    // BST: delete
    TreeNode* delete(int val){
        // Find the node to be deleted
        TreeNode *temp = this->root;
        // Prev is the parent of the node to be deleted
        TreeNode *prev = NULL;
        while(temp->left != NULL and temp->right != NULL){
            if(temp->data == val){
                break;
            }
            prev = temp;
            if(temp->data > val){
                temp = temp->left;
            }else{
                temp = temp->right;
            }
        }
        // If the value is not found
        if(temp->data != val){
            cout<<"Value not found in BST";
            return this->root;
        }
        // If the node to be deleted is a leaf node
        if(temp->left == NULL and temp->right == NULL){
            if(prev->left == temp){
                prev->left = NULL;
            }else{
                prev->right = NULL;
            }
            delete temp;
            return this->root;
        }
        // If the node to be deleted has only one child
        if(temp->left == NULL or temp->right == NULL){
            TreeNode *child = temp->left == NULL ? temp->right : temp->left;
            if(prev->left == temp){
                prev->left = child;
            }else{
                prev->right = child;
            }
            delete temp;
            return this->root;
        }
        // If the node to be deleted has two children
        TreeNode *inorderSucc = inorderSuccessor(temp);
        int inorderSuccData = inorderSucc->data;
        delete(inorderSuccData);
        temp->data = inorderSuccData;
        return this->root;
    }
};


int main(){
    TreeNode root(50);
    // Create a tree
    vector<int> treeData = {30, 70, 20, 40, 60, 80, -1, -1, -1, 45, -1, -1, 75, 90};
    // Insert Data in Tree
    for(int data : treeData){
        root.insert(data);
    }
    // BST
    root.bst()
    return 0;
}