#ifndef BST_H
#define BST_H
#include <iostream>
#include <fstream>

using namespace std;

template <class K, class T>
class TreeNode{
    public:
        TreeNode();
        TreeNode(K key, T data); //key is value
        virtual ~TreeNode(); //if you inherit from this, you can overwrite your own destructor

        K key;
        T data;
        TreeNode<K, T> *left;
        TreeNode<K, T> *right;
};

template <class K, class T>
TreeNode<K, T>::TreeNode(){
    left = NULL;
    right = NULL;
    //key = NULL;
    //data = NULL;
}

template <class K, class T>
TreeNode<K, T>::TreeNode(K key, T data){
    left = NULL;
    right = NULL;
    this->key = key;
    this->data = data;
}

template <class K, class T>
TreeNode<K, T>::~TreeNode(){
    left = NULL;
    right = NULL;
}

template <class K, class T>
class BST{
    public:
        BST();
        virtual ~BST();
        void insert(K key, T value);
        bool contains(K key);
        bool deleteNode(K key);
        bool isEmpty();
        bool find(K key, T& value);
        bool update(K key, T& value);
        void writeToFile(string output);
        T* getMin();
        T* getMax();
        TreeNode<K, T> *getSuccessor(TreeNode<K, T> *d); //d represents the node we are going to delete
        void printNodes();
        void recPrint(TreeNode<K, T> *node);
    private:
        TreeNode<K, T> *root; //only exists in the context of BST, which is why its private
        void filePrint(TreeNode<K, T> *node, ofstream &output);
};

template <class K, class T>
BST<K, T>::BST(){
    root = NULL;

}

template <class K,class T>
BST<K, T>::~BST(){
    
}

template <class K, class T>
void BST<K, T>::filePrint(TreeNode<K, T> *node, ofstream &output){
    //recursive function
    if(node == NULL){ //first need a base case
        return;
    }
    output << node->key << " " << node->data << endl; //actual function of recPrint(): starts at current node, prints out key
    filePrint(node -> left, output); //recursively goes through each node prints left value
    filePrint(node -> right, output); //recursively goes through each node prints right value
}

template <class K, class T>
void BST<K, T>::recPrint(TreeNode<K, T> *node){
    //recursive function
    if(node == NULL){ //first need a base case
        return;
    }
    cout << node->key << " " << node->data << endl; //actual function of recPrint(): starts at current node, prints out key
    recPrint(node -> left); //recursively goes through each node prints left value
    recPrint(node -> right); //recursively goes through each node prints right value
}

template <class K, class T>
void BST<K, T>::printNodes(){
    recPrint(root); //calls recPrint(): prints out each node in the tree starting from root
}

template <class K, class T>
bool BST<K, T>::isEmpty(){
    //checks if root is Null, meaning whole tree is empty
    //comparitive statement checking if root == NULL
    return(root == NULL); 
}

template <class K, class T>
T* BST<K, T>::getMin(){ //getMin() refers to the left side of tree, since everything on left is smaller than root value
    //using TreeNode class, initizaling pointer current to root
    //starting at top of tree, so current has to be root
    TreeNode<K, T> *current = root; 
    if(isEmpty()){
        return NULL;
    }
    //while left child of current is not empty (not at end of tree)
    while(current->left != NULL){ //NULL means the current is at the furthest left-most tree value, with no children
        current = current->left; //move to the left; current is now the left child of previous current 
    }
    return &(current -> key); //return the current value (or pointer address)
}

template <class K, class T>
T* BST<K, T>::getMax(){ //getMin() refers to the right side of tree, since everything on right is bigger than root value
    TreeNode<K, T> *current = root;
    if(isEmpty()){
        return NULL;
    }
    //while right child of current is not empty (not at end of tree)
    while(current->right != NULL){ //NULL means the current is at the furthest right-most tree value, with no children
        current = current->right; //move to the right; current is now the right child of previous current 
    }
    return &(current -> key); //returns pointer of current   
}

template <class K, class T>
void BST<K, T>::insert(K key, T value){
    //setting current node pointer to a new value of type TreeNode<T>
    TreeNode<K, T> *node = new TreeNode<K, T>(key, value); 
    
    if(isEmpty()){
        //if tree is empty, the node that we are currently working with becomes the root
        root = node; 
    }
    else{
        //tree is not empty, need to find insertion point for node
        TreeNode<K, T> *current = root; //current pointer that we are working on, starts with root node
        TreeNode<K, T> *parent = NULL; //parent = NULL, because nothing is above root

        while(true) { //while tree is not empty
            //parent becomes current as we move down the tree
            parent = current;
            //if the value of what we are inserting is LESS THAN the value of our current key (the parent), move left
            if(key < current -> key){
                //current now becomes the left child of previous current
                //reassign current to the left child
                current = current->left;
                //while loops keeps looping through the left side until we arrive to the last left node (NULL)
                //once current = NULL, we found the leaf node to insert our new value
                if(current == NULL){
                    //previous left most node becomes the parent of the new node we are inserting
                    //node we are inserting becomes new left most node
                    parent->left = node;
                    //once we found new location for our left most node, break
                    break;
                }
            }
            else{
                //if the value we are looking for is not less than current value, that means we have to go right
                //current now becomes the right node
                current = current->right;
                if(current == NULL){
                    
                    parent->right = node;
                    break;
                }
            }
        }
    }
}

template <class K, class T>
bool BST<K, T>::contains(K key){
    if(isEmpty()){
        return false;
    }
    else{
        //its not empty, lets try and find it.
        //default start at root, so set current = root
        TreeNode<K, T> *current = root;
        while(current->key != key){//while the value we are looking for is not the current node
            //if value we are looking for is LESS THAN current key, go left
            if(key < current->key){
                //current is now the left node
                current = current->left;
            }
            else{
                //if the value we are looking for is GREATER THAN current key, go right
                //current is now the right node
                current = current->right;
            }
            //if the node we are currently on is NULL, then the tree does not contain the value
            //so we return false
            if(current == NULL){
                return false;
            }
        }
    }
    //after while loop breaks, that means we have found the value we are looking for
    //so we return true
    return true;
}

template <class K, class T>
bool BST<K, T>::find(K key, T& value){
    if(!contains(key)){
        return false;
    }
    //if we get here we need to find it and set our pointers
    TreeNode<K, T> *current = root;
    TreeNode<K, T> *parent = root;
    bool isLeft = true;

    while(current->key != key){
        parent = current;

        if(key < current->key){
            isLeft = true;
            current = current ->left;
        }
        else{
            isLeft = false;
            current = current->right;
        }
        if(current == NULL){
            return false;
        }
    }
    value = current->data;
    return true;
}

template <class K, class T>
bool BST<K, T>::update(K key, T& value){
    if(!contains(key)){
        return false;
    }
    //if we get here we need to find it and set our pointers
    TreeNode<K, T> *current = root;
    TreeNode<K, T> *parent = root;
    bool isLeft = true;

    while(current->key != key){
        parent = current;

        if(key < current->key){
            isLeft = true;
            current = current ->left;
        }
        else{
            isLeft = false;
            current = current->right;
        }
        if(current == NULL){
            return false;
        }
    }
    current->data = value;
    return true;
}

template <class K, class T>
bool BST<K, T>::deleteNode(K key){
    if(!contains(key)){
        return false;
    }
    //if we get here we need to find it and set our pointers
    TreeNode<K, T> *current = root;
    TreeNode<K, T> *parent = root;
    bool isLeft = true;

    while(current->key != key){
        parent = current;

        if(key < current->key){
            isLeft = true;
            current = current ->left;
        }
        else{
            isLeft = false;
            current = current->right;
        }
        if(current == NULL){
            return false;
        }
    }
    //if we make it here, we found the node, now let's proceed to delete

    /*no children, node to be delted is a leaf*/
    if(current->left == NULL && current->right == NULL){
        if(current == root){
            root = NULL;
        }
        else if(isLeft){
            parent->left = NULL;
        }
        else{
            parent->right = NULL;
        }
    }
    else if(current->right == NULL){
        //has one child an it's a left child (no right child)
        if(current == root){
            root = current->left;
        }
        else if(isLeft){
            parent->left = current->left;
        }
        else{
            parent->right = current->left;
        }

    }
    else if(current->left == NULL){
        //has one child an it's a right (no left child)
         if(current == root){
            root = current->right;
        }
        else if(isLeft){
            parent->left = current->right;
        }
        else{
            parent->right = current->right;
        }

    }
    else{
        //node to be deleted has two children
        TreeNode<K, T> *successor = getSuccessor(current);

        if(current == root){
            root = successor;
        }
        else if(isLeft){
            parent->left = successor;
        }
        else{
            parent->right = successor;
        }
        successor->left = current->left;
        current->left = NULL;
        current->right = NULL; 
    }
    return true;
}
template <class K, class T>
//d represents node to be deleted
//getSuccessor(): refers to find new child once a node has been deleted and assign it as the successor
TreeNode<K, T>* BST<K, T>::getSuccessor(TreeNode<K, T> *d){
    //default set successor and successor parent to node d
    TreeNode<K, T> *sp = d; //successor parent
    TreeNode<K, T> *successor = d; //successor also equals d
    TreeNode<K, T> *current = d->right; //current node we are looking at is right child of d (node being deleted)

    while(current != NULL){
        sp = successor; //reassign pointer sp to successor
        successor = current; //successor is now the current node we are working on
        current = current->left; //move current value to left child
    }
    //all pointers should be in the correct locations

    //check if successor is descendent of the right child (d->right)
    if(successor != d->right){
        sp->left = successor->right;
        successor->right = d->right;
    }
    return successor;
}

template <class K, class T>
void BST<K, T>::writeToFile(string output){
    //creation of file object(output)
    ofstream outputFile(output);
    //if statement checks if the file can open
    //if file cannot be opened, an error message is printed to the screen(output)
    if(!outputFile.is_open()){
        cout << "Could not open the file." << output << endl;
        exit(1);
    }
    filePrint(root, outputFile);
    outputFile.close();
}
#endif