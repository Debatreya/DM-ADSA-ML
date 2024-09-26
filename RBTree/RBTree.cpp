#include <iostream>
#include <queue>

using namespace std;

// Node colors
enum Color { RED, BLACK };

class Node {
public:
    int data;
    Color color;
    Node* left, *right, *parent;

    Node(int data) {
        this->data = data;
        left = right = parent = nullptr;
        color = RED; // New nodes are always red
    }
};

class RedBlackTree {
private:
    Node* root;

    // Helper functions
    void rotateLeft(Node* &root, Node* &x) {
        Node* y = x->right;
        x->right = y->left;

        if (y->left != nullptr)
            y->left->parent = x;

        y->parent = x->parent;

        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node* &root, Node* &x) {
        Node* y = x->left;
        x->left = y->right;

        if (y->right != nullptr)
            y->right->parent = x;

        y->parent = x->parent;

        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;

        y->right = x;
        x->parent = y;
    }

    void fixInsert(Node* &root, Node* &pt) {
        Node* parent_pt = nullptr;
        Node* grand_parent_pt = nullptr;

        while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED)) {
            parent_pt = pt->parent;
            grand_parent_pt = pt->parent->parent;

            // Parent is left child of grandparent
            if (parent_pt == grand_parent_pt->left) {
                Node* uncle_pt = grand_parent_pt->right;

                // Uncle is RED (Case 1)
                if (uncle_pt != nullptr && uncle_pt->color == RED) {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                }
                else {
                    // pt is right child of parent (Case 2)
                    if (pt == parent_pt->right) {
                        rotateLeft(root, parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }

                    // pt is left child of parent (Case 3)
                    rotateRight(root, grand_parent_pt);
                    swap(parent_pt->color, grand_parent_pt->color);
                    pt = parent_pt;
                }
            }
            // Parent is right child of grandparent
            else {
                Node* uncle_pt = grand_parent_pt->left;

                // Uncle is RED (Case 1)
                if (uncle_pt != nullptr && uncle_pt->color == RED) {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                }
                else {
                    // pt is left child of parent (Case 2)
                    if (pt == parent_pt->left) {
                        rotateRight(root, parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }

                    // pt is right child of parent (Case 3)
                    rotateLeft(root, grand_parent_pt);
                    swap(parent_pt->color, grand_parent_pt->color);
                    pt = parent_pt;
                }
            }
        }

        root->color = BLACK;
    }

    void levelOrderHelper(Node* root) {
        if (root == nullptr)
            return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            cout << temp->data << "(" << (temp->color == RED ? "R" : "B") << ") ";
            q.pop();

            if (temp->left != nullptr)
                q.push(temp->left);

            if (temp->right != nullptr)
                q.push(temp->right);
        }
    }

    void inorderHelper(Node* root) {
        if (root == nullptr)
            return;

        inorderHelper(root->left);
        cout << root->data << "(" << (root->color == RED ? "R" : "B") << ") ";
        inorderHelper(root->right);
    }

    void preorderHelper(Node* root) {
        if (root == nullptr)
            return;

        cout << root->data << "(" << (root->color == RED ? "R" : "B") << ") ";
        preorderHelper(root->left);
        preorderHelper(root->right);
    }

    void postorderHelper(Node* root) {
        if (root == nullptr)
            return;

        postorderHelper(root->left);
        postorderHelper(root->right);
        cout << root->data << "(" << (root->color == RED ? "R" : "B") << ") ";
    }

public:
    RedBlackTree() { root = nullptr; }

    // Insert function
    void insert(const int &data) {
        Node* pt = new Node(data);

        root = bstInsert(root, pt);

        fixInsert(root, pt);
    }

    // Utility function to insert in BST
    Node* bstInsert(Node* root, Node* pt) {
        if (root == nullptr)
            return pt;

        if (pt->data < root->data) {
            root->left = bstInsert(root->left, pt);
            root->left->parent = root;
        }
        else if (pt->data > root->data) {
            root->right = bstInsert(root->right, pt);
            root->right->parent = root;
        }

        return root;
    }

    // Traversal functions
    void levelOrder() { levelOrderHelper(root); }
    void inorder() { inorderHelper(root); }
    void preorder() { preorderHelper(root); }
    void postorder() { postorderHelper(root); }
};

int main() {
    RedBlackTree tree;
    char command;
    int value;

    while (true) {
        cout << "\nEnter command (I/i: Insert, D/d: Delete, T/t: Traverse, E/e: Exit): ";
        cin >> command;

        if (command == 'I' || command == 'i') {
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insert(value);
        }
        else if (command == 'D' || command == 'd') {
            cout << "Deletion not implemented in this version.\n";
        }
        else if (command == 'T' || command == 't') {
            char traversalType;
            cout << "Enter traversal type (l: Level Order, p: Preorder, o: Postorder, i: Inorder): ";
            cin >> traversalType;

            switch (traversalType) {
            case 'l':
                cout << "Level Order Traversal:\n";
                tree.levelOrder();
                break;
            case 'p':
                cout << "Preorder Traversal:\n";
                tree.preorder();
                break;
            case 'o':
                cout << "Postorder Traversal:\n";
                tree.postorder();
                break;
            case 'i':
                cout << "Inorder Traversal:\n";
                tree.inorder();
                break;
            default:
                cout << "Invalid traversal type\n";
                break;
            }
        }
        else if (command == 'E' || command == 'e') {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid command. Try again.\n";
        }
    }

    return 0;
}
