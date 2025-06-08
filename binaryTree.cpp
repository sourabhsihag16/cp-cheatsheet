#include <iostream>
#include <queue>
using namespace std;

// Binary Tree Node structure
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    // Constructor
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;
    
    // Helper function for inorder traversal
    void inorderHelper(TreeNode* node) {
        if (node == nullptr) return;
        inorderHelper(node->left);
        cout << node->data << " ";
        inorderHelper(node->right);
    }
    
    // Helper function for preorder traversal
    void preorderHelper(TreeNode* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }
    
    // Helper function for postorder traversal
    void postorderHelper(TreeNode* node) {
        if (node == nullptr) return;
        postorderHelper(node->left);
        postorderHelper(node->right);
        cout << node->data << " ";
    }
    
    // Helper function to calculate height
    int heightHelper(TreeNode* node) {
        if (node == nullptr) return -1;
        return 1 + max(heightHelper(node->left), heightHelper(node->right));
    }
    
    // Helper function to count nodes
    int countNodesHelper(TreeNode* node) {
        if (node == nullptr) return 0;
        return 1 + countNodesHelper(node->left) + countNodesHelper(node->right);
    }
    
    // Helper function to search for a value
    bool searchHelper(TreeNode* node, int val) {
        if (node == nullptr) return false;
        if (node->data == val) return true;
        return searchHelper(node->left, val) || searchHelper(node->right, val);
    }
    
    // Helper function to delete the tree (cleanup)
    void deleteTreeHelper(TreeNode* node) {
        if (node == nullptr) return;
        deleteTreeHelper(node->left);
        deleteTreeHelper(node->right);
        delete node;
    }

public:
    // Constructor
    BinaryTree() : root(nullptr) {}
    
    // Destructor
    ~BinaryTree() {
        deleteTreeHelper(root);
    }
    
    // Insert a new node (simple insertion - not BST rules)
    void insert(int val) {
        if (root == nullptr) {
            root = new TreeNode(val);
            return;
        }
        
        // Level-order insertion using queue
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            
            if (temp->left == nullptr) {
                temp->left = new TreeNode(val);
                return;
            } else {
                q.push(temp->left);
            }
            
            if (temp->right == nullptr) {
                temp->right = new TreeNode(val);
                return;
            } else {
                q.push(temp->right);
            }
        }
    }
    
    // Traversal methods
    void inorderTraversal() {
        cout << "Inorder: ";
        inorderHelper(root);
        cout << endl;
    }
    
    void preorderTraversal() {
        cout << "Preorder: ";
        preorderHelper(root);
        cout << endl;
    }
    
    void postorderTraversal() {
        cout << "Postorder: ";
        postorderHelper(root);
        cout << endl;
    }
    
    // Level-order traversal (Breadth-First Search)
    void levelOrderTraversal() {
        if (root == nullptr) return;
        
        cout << "Level-order: ";
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            cout << temp->data << " ";
            
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << endl;
    }
    
    // Get height of the tree
    int getHeight() {
        return heightHelper(root);
    }
    
    // Count total nodes
    int countNodes() {
        return countNodesHelper(root);
    }
    
    // Search for a value
    bool search(int val) {
        return searchHelper(root, val);
    }
    
    // Check if tree is empty
    bool isEmpty() {
        return root == nullptr;
    }
    
    // Get root data (if exists)
    int getRootData() {
        if (root) return root->data;
        throw runtime_error("Tree is empty");
    }
};

// Example usage and demonstration
int main() {
    BinaryTree tree;
    
    cout << "=== Binary Tree Operations Demo ===" << endl;
    
    // Insert some values
    cout << "\nInserting values: 1, 2, 3, 4, 5, 6, 7" << endl;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    
    // Display tree structure through traversals
    cout << "\nTree Traversals:" << endl;
    tree.inorderTraversal();     // Left, Root, Right
    tree.preorderTraversal();    // Root, Left, Right
    tree.postorderTraversal();   // Left, Right, Root
    tree.levelOrderTraversal();  // Level by level
    
    // Tree properties
    cout << "\nTree Properties:" << endl;
    cout << "Height: " << tree.getHeight() << endl;
    cout << "Total nodes: " << tree.countNodes() << endl;
    cout << "Root data: " << tree.getRootData() << endl;
    
    // Search operations
    cout << "\nSearch Operations:" << endl;
    cout << "Search for 5: " << (tree.search(5) ? "Found" : "Not found") << endl;
    cout << "Search for 10: " << (tree.search(10) ? "Found" : "Not found") << endl;
    
    // Tree structure visualization (for the inserted values):
    cout << "\nTree Structure:" << endl;
    cout << "       1       " << endl;
    cout << "      / \\      " << endl;
    cout << "     2   3     " << endl;
    cout << "    / \\ / \\    " << endl;
    cout << "   4  5 6  7   " << endl;
    
    return 0;
}
