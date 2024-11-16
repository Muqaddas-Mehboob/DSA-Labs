//01
#include <iostream>
using namespace std;

class treeNode{
    public:
    int val;
    treeNode* left;
    treeNode* right;
    
    treeNode(int val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Muqaddas_Mehboob_Lab11{
    treeNode* root;
    public:
        Muqaddas_Mehboob_Lab11() : root(NULL){}

     treeNode* insertRec(treeNode* node, int key) {
        if (node == NULL)
            return new treeNode(key);

        if (key < node->val)
            node->left = insertRec(node->left, key);
        else if (key > node->val)
            node->right = insertRec(node->right, key);

        return node;
    }

    // Recursive function to delete a node
    treeNode* deleteRec(treeNode* node, int key) {
        if (node == NULL)
            return node;

        if (key < node->val)
            node->left = deleteRec(node->left, key);
        else if (key > node->val)
            node->right = deleteRec(node->right, key);
        else {
            // Node with only one child or no child
            if (node->left == NULL) {
                treeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                treeNode* temp = node->left;
                delete node;
                return temp;
            }
            // Node with two children
            treeNode* temp = minValueNode(node->right);
            node->val = temp->val;
            node->right = deleteRec(node->right, temp->val);
        }
        return node;
    }

    // Find the node with the minimum value
    treeNode* minValueNode(treeNode* node) {
        treeNode* current = node;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }

    // Recursive function for inorder traversal
    void inorderRec(treeNode* root) {
        if (root != NULL) {
            inorderRec(root->left);
            cout << root->val << " ";
            inorderRec(root->right);
        }
    }

    // Recursive function for preorder traversal
    void preorderRec(treeNode* root) {
        if (root != NULL) {
            cout << root->val << " ";
            preorderRec(root->left);
            preorderRec(root->right);
        }
    }

    // Recursive function for postorder traversal
    void postorderRec(treeNode* root) {
        if (root != NULL) {
            postorderRec(root->left);
            postorderRec(root->right);
            cout << root->val << " ";
        }
    }

    void insert(int key) {
        root = insertRec(root, key);
    }
    void deleteNode(int key) {
        root = deleteRec(root, key);
    }
    void inorder() {
        inorderRec(root);
        cout << endl;
    }
    void preorder() {
        preorderRec(root);
        cout << endl;
    }
    void postorder() {
        postorderRec(root);
        cout << endl;
    }
};
int main(){
    Muqaddas_Mehboob_Lab11 bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder traversal of the tree: ";
    bst.inorder();

    cout << "Preorder traversal of the tree: ";
    bst.preorder();

    cout << "Postorder traversal of the tree: ";
    bst.postorder();

    cout << "Deleting 20\n";
    bst.deleteNode(20);

    cout << "Inorder traversal after deleting 20: ";
    bst.inorder();

    cout << "Preorder traversal after deleting 20: ";
    bst.preorder();

    cout << "Postorder traversal after deleting 20: ";
    bst.postorder();
    return 0;
}

//02
#include <iostream>
using namespace std;

class treeNode{
    public:
    int data;
    treeNode* left;
    treeNode* right;
    
    treeNode(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Muqaddas_Mehboob_Lab11{
    treeNode* root;
    public:
        Muqaddas_Mehboob_Lab11() : root(NULL){}

        treeNode* insert(treeNode* node, int key) {
        if (node == NULL)
            return new treeNode(key);
        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);
        return node;
        }
        void insertHelper(int key) {
            root = insert(root, key);
        }

        treeNode* findLCARec(treeNode* node, int n1, int n2) {
        if (!node) return NULL;
        if (n1 < node->data && n2 < node->data)
            return findLCARec(node->left, n1, n2);
        if (n1 > node->data && n2 > node->data)
            return findLCARec(node->right, n1, n2);
        return node;
        }

        treeNode* findLCA(int n1, int n2) {
        return findLCARec(root, n1, n2);
        }
};

int main(){
    Muqaddas_Mehboob_Lab11 bst;
    bst.insertHelper(20);
    bst.insertHelper(8);
    bst.insertHelper(22);
    bst.insertHelper(4);
    bst.insertHelper(12);
    bst.insertHelper(10);
    bst.insertHelper(14);
    int n1 = 22, n2 = 14;
    treeNode* lca = bst.findLCA(n1, n2);

    if (lca)
        cout << "LCA of " << n1 << " and " << n2 << " is: " << lca->data << endl;
    else
        cout << "LCA not found!" << endl;

    return 0;
}

//03
#include <iostream>
using namespace std;

class treeNode{
    public:
    int data;
    treeNode* left;
    treeNode* right;
    
    treeNode(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
class Muqaddas_Mehboob_Lab11{
    treeNode* root;
    public:
        Muqaddas_Mehboob_Lab11() : root(NULL){}

        treeNode* insert(treeNode* node, int key) {
        if (node == NULL)
            return new treeNode(key);
        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);
        return node;
        }
        void insertHelper(int key) {
            root = insert(root, key);
        }
        int sumNodesRec(treeNode* node) {
        if (!node)
            return 0;
        return node->data + sumNodesRec(node->left) + sumNodesRec(node->right);
    }
        int sumOfNodes() {
        return sumNodesRec(root);
    }
};
int main(){
    Muqaddas_Mehboob_Lab11 bst;

    bst.insertHelper(10);
    bst.insertHelper(20);
    bst.insertHelper(5);
    bst.insertHelper(15);
    cout << "Sum of all nodes: " << bst.sumOfNodes() << endl;

    return 0;
}