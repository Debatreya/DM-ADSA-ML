#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left, *right;

    TreeNode(int x = -1) {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {
public:
    TreeNode* root;

    BST(int data = -1) {
        this->root = (data == -1) ? NULL : new TreeNode(data);
    }

    TreeNode* insert(TreeNode* root, int data) {
        if (root == NULL) {
            return new TreeNode(data);
        }
        if (data < root->data) {
            root->left = insert(root->left, data);
        } else if (data > root->data) {
            root->right = insert(root->right, data);
        } else {
            // Value already exists in BST
            cout << "BST already has this value" << endl;
            return root;
        }
        return root;
    }

    void BFS() {
        if (this->root == NULL) {
            cout << "Tree is empty" << endl;
            return;
        }
        queue<TreeNode*> q;
        q.push(this->root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode *temp = q.front();
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

    TreeNode* inorderSuccessor(TreeNode* node) {
        if (node == NULL) return NULL;
        node = node->right;
        while (node && node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int val) {
        if (root == NULL) {
            return root;
        }
        if (val < root->data) {
            root->left = deleteNode(root->left, val);
        } else if (val > root->data) {
            root->right = deleteNode(root->right, val);
        } else {
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else {
                TreeNode* temp = inorderSuccessor(root);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
        return root;
    }
};

class AVL : public BST {
public:
    AVL(int data = -1) {
        this->root = (data == -1) ? NULL : new TreeNode(data);
    }

    int height(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    int balanceFactor(TreeNode* root) {
        if (root == NULL) return 0;
        return height(root->left) - height(root->right);
    }

    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;
        y->left = x;
        x->right = T2;
        return y;
    }

    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;
        x->right = y;
        y->left = T2;
        return x;
    }

    TreeNode* insert(TreeNode* root, int data) {
        if (root == NULL) return new TreeNode(data);

        if (data < root->data) {
            root->left = insert(root->left, data);
        } else if (data > root->data) {
            root->right = insert(root->right, data);
        } else {
            return root;
        }

        int bf = balanceFactor(root);

        // Left Left Case
        if (bf > 1 && data < root->left->data) {
            return rightRotate(root);
        }

        // Right Right Case
        if (bf < -1 && data > root->right->data) {
            return leftRotate(root);
        }

        // Left Right Case
        if (bf > 1 && data > root->left->data) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Left Case
        if (bf < -1 && data < root->right->data) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    TreeNode* insert(int data) {
        this->root = insert(this->root, data);
        return this->root;
    }

    TreeNode* deleteNode(TreeNode* root, int val) {
        root = BST::deleteNode(root, val);

        if (root == NULL) return root;

        int bf = balanceFactor(root);

        // Left heavy
        if (bf > 1 && balanceFactor(root->left) >= 0) {
            return rightRotate(root);
        }
        if (bf > 1 && balanceFactor(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right heavy
        if (bf < -1 && balanceFactor(root->right) <= 0) {
            return leftRotate(root);
        }
        if (bf < -1 && balanceFactor(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    TreeNode* deleteNode(int val) {
        this->root = deleteNode(this->root, val);
        return this->root;
    }
};


int main(){
    AVL avl(10);
    cout<<"Initial AVL"<<endl;
    avl.BFS();
    cout<<endl;
    vector<int> v = {1, 2, 3, 5, 6, 7, 8, 11, 12, 13, 15, 18, 20, 22};
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