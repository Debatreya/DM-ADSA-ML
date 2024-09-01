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

class AVL : public BST {
public:
    // AVL Constructor, initializing an AVL
    AVL(int data = -1) {
        this->root = new TreeNode(data);
    }

    // AVL: height: Returns the height of the AVL
    int height(TreeNode *root) {
        if (root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    // AVL: balanceFactor: Returns the balance factor of the AVL
    int balanceFactor(TreeNode *root) {
        if (root == NULL) return 0;
        return height(root->left) - height(root->right);
    }

    // AVL: leftRotate: Left Rotate the AVL
    TreeNode* leftRotate(TreeNode *root) {
        TreeNode *newRoot = root->right;
        root->right = newRoot->left;
        newRoot->left = root;
        return newRoot;
    }

    // AVL: rightRotate: Right Rotate the AVL
    TreeNode* rightRotate(TreeNode *root) {
        TreeNode *newRoot = root->left;
        root->left = newRoot->right;
        newRoot->right = root;
        return newRoot;
    }

    // AVL: insert: Insert a data in AVL
    TreeNode* insert(int data) {
        this->root = BST::insert(data);
        return insertUtil(this->root, data);
    }

    // AVL: insertUtil: 
    // Utility function for insert
    // Finds the node where imbalance occurs and mark it as `z`
    // Finds its children `y` and `x` going towards the newly inserted node
    // Performs rotations to balance the AVL depending on the (L)eft or (R)ight case

    TreeNode* insertUtil(TreeNode *root, int data) {
        if(root == NULL) return new TreeNode(data);

        if (root->data > data) {
            root->left = insertUtil(root->left, data);
        } else {
            root->right = insertUtil(root->right, data);
        }

        int bf = balanceFactor(root);

        // Left Case
        if (bf > 1) {
            if (data < root->left->data) {
                return rightRotate(root);
            } else {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }

        // Right Case
        if (bf < -1) {
            if (data > root->right->data) {
                return leftRotate(root);
            } else {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }

        return root;
    }
    
    // AVL: deleteNode: Delete a node with given data from AVL
    TreeNode* deleteNode(int val) {
        this->root = BST::deleteNode(val);
        return deleteUtil(this->root, val);
    }

    // AVL: deleteUtil: Utility function for delete
    TreeNode* deleteUtil(TreeNode *root, int val) {
        if (root == NULL) return root;

        int bf = balanceFactor(root);

        // Left Case
        if (bf > 1) {
            if (balanceFactor(root->left) >= 0) {
                return rightRotate(root);
            } else {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }

        // Right Case
        if (bf < -1) {
            if (balanceFactor(root->right) <= 0) {
                return leftRotate(root);
            } else {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }

        return root;
    }
};

int main(){
    AVL avl(10);
    cout<<"Initial AVL"<<endl;
    avl.BFS();
    cout<<endl;
    vector<int> v = {5, 15, 2, 7, 12, 20, 1, 3, 6, 8, 11, 13, 18, 22};
    // Inserting elements in AVL
    for (int i = 0; i < v.size(); i++) {
        cout<<"Inserting "<<v[i]<<endl;
        avl.insert(v[i]);
        // Level Order Traversal of AVL
        avl.BFS();
        cout<<endl;
    }
    // Deleting elements from AVL
    for (int i = 0; i < v.size(); i++) {
        cout<<"Deleting "<<v[i]<<endl;
        avl.deleteNode(v[i]);
        // Level Order Traversal of AVL
        avl.BFS();
        cout<<endl;
    }
    return 0;
}