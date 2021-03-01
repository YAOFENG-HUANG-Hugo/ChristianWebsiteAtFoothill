#include "BST.h"
#include <vector>
#include <iostream>
using namespace std;

/**
 * Implement the BST constructor
 */
BST::BST() {
    /* YOUR CODE HERE */
    root = NULL;
    numElements = 0;
}

/**
 * Implement the BST destructor
 */
BST::~BST() {
    /* YOUR CODE HERE */
    clear();
}

/**
 * Implement size() correctly
 */
unsigned int BST::size() const {
    /* YOUR CODE HERE */
    return numElements;
}

void delhelper(BST::Node *&root){
    if(root == NULL) {
        return;
    }else{
        delhelper(root->leftChild);
        delhelper(root->rightChild);
    }
    delete root;
    root = NULL;
} 

/**
 * Implement clear() correctly without memory leaks
 */
void BST::clear() {
    /* YOUR CODE HERE */
    delhelper(root);
    numElements = 0;
}

bool inhelper(BST::Node *&root, BST::Node *&new_Node, BST::Node *pa){
    if(root == NULL ){
        root = new_Node;
        root->parent = pa;
        return true;
    }else if(root->data > new_Node->data){
        return inhelper(root->leftChild, new_Node, root);
    }else if(root->data < new_Node->data){
        return inhelper(root->rightChild, new_Node, root);
    }
} 

/**
 * Implement insert() correctly
 */
bool BST::insert(int element) {
    /* YOUR CODE HERE */
    if(find(element) == true){
        return false;
    }else{
        Node* new_Node = new Node(element);
        if(root == NULL){
            root = new_Node;
        }else{
            inhelper(root, new_Node, root->parent);
        }
        numElements ++ ;
        return true;
    }
}

bool findhelper(BST::Node *root, int query){
    if(root == NULL){
        return false;
    }else if (query < root->data ) {
        return findhelper(root->leftChild, query);
    }else if (query > root->data ) {
         return findhelper (root->rightChild, query);
    }else {
        return true;
    }
}

/**
 * Implement find() correctly
 */
bool BST::find(const int & query) const {
    /* YOUR CODE HERE */
    return findhelper(root, query);
}

/**
 * Implement the getLeftMostNode() function correctly
 */
BST::Node* BST::getLeftMostNode() {
    /* YOUR CODE HERE */
    if(root == NULL)
        return NULL;
    else{
        Node* tmp = root;
        while(tmp != NULL){
            if(tmp->leftChild == NULL){//leftChild is empty
                return tmp;
            }else{//leftChild is not empty
                tmp = tmp->leftChild;
                if(tmp->leftChild == NULL)
                    return tmp;
            }
        }
    }
}



/**
 * Implement the BST::Node successor function correctly
 */
BST::Node* BST::Node::successor() {
    /* YOUR CODE HERE */
    Node* cur = NULL;
    if(this->rightChild != NULL){
        cur = this->rightChild;
        while(cur->leftChild != NULL){
            cur = cur->leftChild;
        }
        return cur;
    }else{
        cur = this;
        if(this->parent != NULL){
            while(cur != (cur->parent)->leftChild){
                cur = cur->parent;
                if(cur->parent == NULL){
                    return NULL;
                }
            }
            return cur->parent;
        }else{
            return cur;
        }
    }
}