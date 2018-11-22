#include <iostream>
#include <math.h>
using namespace std;

template <class T>
struct Node {
    T value;
    int key;
    Node *left;
    Node *right;

    Node(T val,int k) {
        this->value = val;
        this->key = k;
    }

    Node(T val,int k, Node<T> left, Node<T> right) {
        this->value = val;
        this->key = k;
        this->left = left;
        this->right = right;
    }
};

template <class T>
class BST {

    private:
    Node<T> *root;

    void addHelper(Node<T> *root, T val,int k) {
        if (root->value > val) {
            if (root->left == NULL) 
			{
                root->left = new Node<T>(val,k);
				root->left->right = NULL;
				root->left->left = NULL;
            } 
			else 
			{
                addHelper(root->left, val, k);
            }
        } else {
            if (root->right == NULL) {
                root->right = new Node<T>(val,k);
				root->right->left = NULL;
				root->right->right = NULL;
            } else {
                addHelper(root->right, val,k);
            }
        }
    }
    
    bool containshelper(Node<T> *root,string check)
    {
        if (!root)
            {return false;}
        else if(check < root->value)
            { return containshelper(root->left, check);}
        else if (check > root->value)
            { return containshelper(root->right, check);}
        else
            return true;
    }

    int nodesCountHelper(Node<T> *root) {
        if (!root) return 0;
        else return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
    }

    int heightHelper(Node<T> *root) {
        if (!root) return 0;
        else return 1 + max(heightHelper(root->left), heightHelper(root->right));
    }

    void printMaxPathHelper(Node<T> *root) {
        if (!root) return;
        cout<<root->value<<' ';
        if (heightHelper(root->left) > heightHelper(root->right)) {
            printMaxPathHelper(root->left);
        } else {
            printMaxPathHelper(root->right);
        }
    }

    bool deleteValueHelper(Node<T>* parent, Node<T>* current, T value) {
        if (!current) return false;
        if (current->value == value) {
            if (current->left == NULL || current->right == NULL) {
                Node<T>* temp = current->left;
                if (current->right) temp = current->right;
                if (parent) {
                    if (parent->left == current) {
                        parent->left = temp;
                    } else {
                        parent->right = temp;
                    }
                } else {
                    this->root = temp;
                }
            } else {
                Node<T>* validSubs = current->right;
                while (validSubs->left) {
                    validSubs = validSubs->left;
                }
                T temp = current->value;
                current->value = validSubs->value;
                validSubs->value = temp;
                return deleteValueHelper(current, current->right, temp);
            }
            delete current;
            return true;
        }
        return deleteValueHelper(current, current->left, value) ||
               deleteValueHelper(current, current->right, value);
    }
    
    
    Node<T>* fetch(Node<T>*root,T val)
    {
        if(root==NULL)
        {
            
            return NULL;
        }
       
        
        else if(val<root->value)
        {
            
            return fetch(root->left,val);
        }
        else if(val>root->value)
        {
            
            return fetch(root->right,val);
        }
        else
        {
            
            return root;
        }
    }
    public:
    void add(T val,int k) {
        if (root) {
            this->addHelper(root, val, k);
        } else {
            root = new Node<T>(val, k);
			root->left = NULL;
			root->right = NULL;
        }
    }

    bool contains(string check) {
         return containshelper(this->root, check);
    }

    int nodesCount() {
        return nodesCountHelper(root);
    }

    int height() {
        return heightHelper(this->root);
    }
    
    Node<T>* fetch(T val){
        return fetch(this->root, val);
    }

    void printMaxPath() {
        printMaxPathHelper(this->root);
    }

    bool deleteValue(T value) {
        return this->deleteValueHelper(NULL, this->root, value);
    }
    
};
