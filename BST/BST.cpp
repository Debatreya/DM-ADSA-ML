#include<bits/stdc++.h>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left, *right;

    TreeNode(int x = -1) {
        // If x is provided then data = x, otherwise data = -1
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {
public:
    TreeNode* root;

    // BST Constructor, initializing a BST
    BST(int data = -1) {
        this->root = new TreeNode(data);
    }

    // BST: Insert: Insert a data in BST
    TreeNode* insert(int data) {
        TreeNode *temp = this->root;
        TreeNode *prev = NULL;

        while (temp != NULL) {
            prev = temp;
            if (temp->data == data) {
                cout << "BST already has this value" << endl;
                return this->root;
            }
            if (temp->data > data) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }

        if (prev->data > data) {
            prev->left = new TreeNode(data);
        } else {
            prev->right = new TreeNode(data);
        }
        return this->root;
    }

    // BST: BFS: Level Order Traversal of a BST (Breadth First Search) (using queue and print level by level)
    void BFS() {
        TreeNode *temp = this->root;
        queue<TreeNode*> q;
        q.push(temp);
        q.push(NULL);
        while (!q.empty()) {
            temp = q.front();
            q.pop();
            if (temp == NULL) {
                cout << endl;
                if (!q.empty()) q.push(NULL);
            } else {
                cout << temp->data << " ";
                if (temp->left != NULL) q.push(temp->left);
                if (temp->right != NULL) q.push(temp->right);
            }
        }
    }

    // BST: inorder: Inorder Traversal of a BST (Always a sorted sequence)
    void inorder(TreeNode *root) {
        if (root) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    // BST: postorder: Postorder Traversal of a BST
    void postorder(TreeNode *root) {
        if (root) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }

    // BST: preorder: Preorder Traversal of a BST
    void preorder(TreeNode *root) {
        if (root) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    // BST: Search: Returns the address of the node that contains the given value
    TreeNode* search(int val) {
        TreeNode *temp = this->root;
        while (temp != NULL) {
            if (temp->data == val) return temp;
            if (temp->data > val) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        return NULL;
    }

    // BST: inorderSuccessor: Find the inorder successor of a given node
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

    // BST: deleteNode: Delete a node with given data from BST
    TreeNode* deleteNode(int val) {
        // Find the node to be deleted
        TreeNode *temp = this->root;
        TreeNode *prev = NULL;

        while (temp != NULL && temp->data != val) {
            prev = temp;
            if (temp->data > val) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }

        // If the value is not found
        if (temp == NULL || temp->data != val) {
            cout << "Value not found in BST" << endl;
            return this->root;
        }

        // If the node to be deleted is a leaf node
        if (temp->left == NULL && temp->right == NULL) {
            if (prev->left == temp) {
                prev->left = NULL;
            } else {
                prev->right = NULL;
            }
            delete temp;
            return this->root;
        }

        // If the node to be deleted has only one child
        if (temp->left == NULL || temp->right == NULL) {
            TreeNode *child = temp->left == NULL ? temp->right : temp->left;
            if (prev->left == temp) {
                prev->left = child;
            } else {
                prev->right = child;
            }
            delete temp;
            return this->root;
        }

        // If the node to be deleted has two children
        TreeNode *inorderSucc = inorderSuccessor(temp);
        int inorderSuccData = inorderSucc->data;
        deleteNode(inorderSuccData);
        temp->data = inorderSuccData;
        return this->root;
    }
};

int main() {
    BST tree(50);
    // Create a tree
    vector<int> treeData = {30, 70, 20, 40, 60, 80, 45, 75, 90};
    // Insert Data in Tree
    for (int data : treeData) {
        tree.insert(data);
    }
    // BFS Traversal
    cout<<"BST : BFS Traversal: "<<endl;
    tree.BFS();
    // Inorder Traversal
    cout<<"BST : Inorder Traversal: "<<endl;
    tree.inorder(tree.root);
    cout << endl;
    // Postorder Traversal
    cout<<"BST : Postorder Traversal: "<<endl;
    tree.postorder(tree.root);
    cout << endl;
    // Preorder Traversal
    cout<<"BST : Preorder Traversal: "<<endl;
    tree.preorder(tree.root);
    cout << endl;
    // Search for a value
    cout<<"Search for a value: 40"<<endl;
    TreeNode *searchedNode = tree.search(40);
    if (searchedNode != NULL) {
        cout << "Value found: " << searchedNode->data << endl;
    } else {
        cout << "Value not found" << endl;
    }
    // Delete a node
    // Case 1: Node to be deleted is a leaf node
    cout<<"Delete a node: 45 (leaf node)"<<endl;
    tree.deleteNode(45);
    tree.BFS();
    // Case 2: Node to be deleted has only one child
    cout<<"Delete a node: 40 (node with one child)"<<endl;
    tree.deleteNode(40);
    tree.BFS();
    // Case 3: Node to be deleted has two children
    cout<<"Delete a node: 70 (node with two children)"<<endl;
    tree.deleteNode(70);
    tree.BFS();
    // Search for a value
    cout<<"Search for a value: 70"<<endl;
    searchedNode = tree.search(70);
    if (searchedNode != NULL) {
        cout << "Value found: " << searchedNode->data << endl;
    } else {
        cout << "Value not found" << endl;
    }
    // Inorder Traversal
    cout<<"BST : Final Inorder Traversal: "<<endl;
    tree.inorder(tree.root);
    cout << endl;
    // Postorder Traversal
    cout<<"BST : Final Postorder Traversal: "<<endl;
    tree.postorder(tree.root);
    cout << endl;
    // Preorder Traversal
    cout<<"BST : Final Preorder Traversal: "<<endl;
    tree.preorder(tree.root);
    cout << endl;
    return 0;
}
