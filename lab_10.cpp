//01

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

class Muqaddas_Mehboob_Lab10{
    treeNode* root;
    public:
        Muqaddas_Mehboob_Lab10() : root(nullptr){}

        void preOrder(treeNode* node){
            if(node == NULL){
                return;
            }
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
        void postOrder(treeNode* node){
            if(node == NULL){
                return;
            }
            preOrder(node->left);
            preOrder(node->right);
            cout << node->data << " ";
        }
        void preOrderTraversal() {
        preOrder(root);
        cout << endl;
        }
        void postOrderTraversal() {
            postOrder(root);
            cout << endl;
        }
        treeNode* searchNode(treeNode* node, int value){
            if(!node || node->data == value){
                return node;
            }
            if(value < node->data){
                return searchNode(node->left, value);
            }
            return searchNode(node->right, value);
        }
        bool search(int value){
            return searchNode(root, value) != nullptr;
        }
        void insert(int value){
            treeNode* newNode = new treeNode(value);
            if(root == NULL){
                root = newNode;
                return;
            }
            treeNode* current = root;
            treeNode* parent = NULL;

            while(current){
                parent = current;
                if(value < current->data){
                    current = current->left;
                }
                else{
                    current = current->right;
                }
            }
            if(value < parent->data){
                parent->left = newNode;
            }
            else{
                parent->right = newNode;
            }
        }
};
int main(){
    Muqaddas_Mehboob_Lab10 tree;

    // Insert nodes
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(13);
    tree.insert(17);

    // Search for a value
    int value = 7;
    if (tree.search(value)) 
        cout << "Node with value " << value << " found in the tree.\n";
    else 
        cout << "Node with value " << value << " not found in the tree.\n";

    // Pre-order traversal
    cout << "Pre-order traversal: ";
    tree.preOrderTraversal();

    // Post-order traversal
    cout << "Post-order traversal: ";
    tree.postOrderTraversal();
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

class Muqaddas_Mehboob_Lab10{
    treeNode* root;
    public:
        Muqaddas_Mehboob_Lab10(): root(NULL){}

        bool isMirror(treeNode* left, treeNode* right){
            if(left == NULL && right == NULL){
                return true;
            }
            if(left == NULL || right == NULL){
                return false;
            }
            if(left->data != right->data){
                return false;
            }
            return isMirror(left->left , right->right) && isMirror(left->right , right->left);
        }
        bool isSymmetric(){
            if(root == NULL){
                return true;
            }
            return isMirror(root->left, root->right);
        }
        void setRoot(treeNode* node){
            root = node;
        }
};
int main(){
    treeNode* root = new treeNode(1);
    root->left = new treeNode(2);
    root->right = new treeNode(2);
    root->left->left = new treeNode(3);
    root->left->right = new treeNode(4);
    root->right->left = new treeNode(4);
    root->right->right = new treeNode(3);

    Muqaddas_Mehboob_Lab10 tree;
    tree.setRoot(root);

    if (tree.isSymmetric())
        cout << "The tree is symmetric." << endl;
    else
        cout << "The tree is not symmetric." << endl;

    return 0;
}