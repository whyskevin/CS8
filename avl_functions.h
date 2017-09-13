#ifndef AVL_FUNCTIONS_H
#define AVL_FUNCTIONS_H
#include <iostream>
#include <iomanip>
#include "avlnode.h"
#include <assert.h>

using namespace std;

//Inserts for a BST. Checks the value of the entry to the passed "root" and places
template <typename T>
void insert_Tree(AVLNode<T> *&root, T entry);

template <typename T>
void print(AVLNode<T> *&root, unsigned int level);

template <typename T>
void deleteItem(AVLNode<T> *&root, T &deleteMe);

template <typename T>
T& remove_max(AVLNode <T> *&root);

// AVL TREE FUNCTIONS --------

//Returns the height of the given node. If the node is a nullptr, we return the height as 0
//If it is not NULL, we return the private member variable "height".
template <typename T>
int get_height(AVLNode<T>* getHeight);

//Returns the larger of the two integer parameters
template <typename T>
int max(int one, int two);

//One of the move important functions for an AVL Tree, the balanceFactor will take the difference between
//the heights of its left subtree and its right subtree. This will determine if the current node is the
//problematic, unbalanced node.
template <typename T>
int balanceFactor(AVLNode<T>* getMyBF);

//Rotation Methods ----------------
//This function will take the AVLNode moveMeLeft and the related AVLNodes and rotate the moveMeLeft node to the left
//The right node of moveMeLeft becomes the newRoot and the right node of the newRoot is moved into the right subtree
template <typename T>
AVLNode<T>* leftRotate(AVLNode<T> *moveMeLeft);

//This function will take the AVLNode moveMeRight and the related AVLNodes and rotate the given moveMeRight node the right
//The left node of the moveMeRight will become the newRoot and the left node of the newRoot is moved into newRoot->left subtree
template <typename T>
AVLNode<T>* rightRotate(AVLNode<T> *moveMeRight);

// Tree Traversal methods -----------------------

template <typename T>
T search_Tree(AVLNode<T> *&root, T &findMe);

//Prints the Tree values inorder, preorder, postorder
//Traverse in order. This will go to left -> root -> right
template <typename T>
void inorder(AVLNode<T> *&root);

//Traverse preorder. This will go to root -> left -> right
template <typename T>
void preorder(AVLNode<T> *&root);

//Traverse postorder. This will go to left -> right -> root
template <typename T>
void postorder(AVLNode<T> *&root);

//Input: the root ptr of a tree
//Clears the entire tree.
template <typename T>
void tree_clear(AVLNode<T> *& root_ptr);



//Insert a node to a Binary Search Tree. The left item is smaller than the right item
template <typename T>
void insert_Tree(AVLNode<T> *& root, T entry){
    if(root == NULL){
        cout << "Initiating the Tree" << endl;
        AVLNode<T>* newNode = new AVLNode<T>(entry);
        root = newNode;
        return;
    }

    //Normal BST Insertion. Smaller items go to the left while larger ones go to the right
    T root_item = root->item; //Get the item at the passed root AVLNode
    if(entry < root_item){
        //If the entry item is smaller than the root, check the left item from the root.
        //If the left is open, set the item to the left node
        if(root->left == NULL){
            AVLNode<T>* newNode = new AVLNode<T>(entry);
            root->set_left(newNode);
        }else{
            insert_Tree(root->left,entry);
        }
    }else if(entry > root_item){
        //If the entry item is larger than the root item,check the right AVLNode
        if(root->right == NULL){
            AVLNode<T>* newNode = new AVLNode<T>(entry);
            root->set_right(newNode);
        }else{
            insert_Tree(root->right, entry);
        }
    }else if(entry == root_item){
        cout << "No duplicates" << endl;
    }

    //the self-balancing functions are called here. THIS IS WHERE THE AVL TREE WILL BEGIN TO CHECK IF THE CURRENT NODE IS UNBALANCED
    //Update root height
    root->height = (1 + max(get_height(root->left), get_height(root->right)) );

    //Check if the root is unbalanced.
    //There are 4 main cases that occur when the tree violates the AVL Tree Rules

    //Here we take the balance factor of the current node
    int balance = balanceFactor(root);

    //Resulting four cases if the root is unbalanced

    if(balance > 1 && entry < root->left->item){ //Case 1: Left subtree is left deep. Rotate right
        cout << "Case 1 Insert" << endl;
        root = rightRotate(root);
    }else if(balance > 1 && entry > root->left->item){ //Case 2: Left subtree is right deep. Rotate left then rotate right
        cout << "Case 2 Insert" << endl;
        root->left = leftRotate(root->left);
        root = rightRotate(root);
    } else if(balance < -1 && entry > root->right->item){ //Case 3: Right subtree is right deep. Rotate left
        cout << "Case 3 Insert" << endl;
        root = leftRotate(root);
    }else if(balance < -1 && entry < root->right->item){ //Case 4: Right subtree is left deep. Rotate right then rotate left
        cout << "Case 4 Insert" << endl;
        root->right = rightRotate(root->right);
        root = leftRotate(root);
    }
    //        return;
}

//delete function for a BST. If the item is not found, the function will return nothing
//

template <typename T>
void deleteItem(AVLNode<T> *&root, T &deleteMe){
    if(root == NULL){   //Case 1: The tree is empty
        cout << "Tree is empty, nothing to return" << endl;
        return;
        //        return NULL; //The tree is empty
    }
    if (deleteMe < root->item){ //Case 2: If deleteMe is smaller than the item at the root
        if(root->left != NULL){
            deleteItem(root->left, deleteMe); //If the left node is free, proceeed with recursion to the left
            //                    return
        }else{
            //            return NULL; //Item was not found
            return;
        }
    }else if(deleteMe > root->item){ //Case 3: If deleteMe is larger than the item at the root
        if(root->right != NULL){
            deleteItem(root->right, deleteMe);//If the right node is free, proceeed with recursion to the right
            //                    return
        }else{
            //            return NULL; //Item was not found
            return;
        }

    }else if(root->item == deleteMe){
        //If the item is found
        //Now we much check if there are any children

        if(root->right == NULL && root->left == NULL){ //Case 4: The item AVLNode has no children
            delete root;
            root = NULL;
            //            return root;
            return;
        }

        if(root->left == NULL){ //There is no left child
            AVLNode <T>* old_root_ptr = root;
            root = root->right_node();
            delete old_root_ptr;
        } else if(root->left != NULL){ //If there is left child
            root->item = remove_max(root->left);
            //            return root;
            return;
        }
    }

    //---------------------------------------------
    //The self-balancing functions are called here. THIS IS WHERE THE AVL TREE WILL BEGIN TO CHECK IF THE CURRENT NODE IS UNBALANCED
    //Update the height of the current node
    root->height = 1 + max(get_height(root->left), get_height(root->right));

    //Get the balance value. We will check if the AVL Tree is unbalanced and needs balancing under these 4 cases
    int balance =  balanceFactor(root);
    //Resulting four cases if the root is unbalanced
    if(balance > 1 && balanceFactor(root->left) >= 0){ //Case 1: Rotate right
        cout << "Case 1 Remove" << endl;
        root = rightRotate(root);
    }else if(balance > 1 && balanceFactor(root->left) < 0){ //Case 2: Rotate left, then right
        cout << "Case 2 Remove" << endl;
        root->left = leftRotate(root->left);
        root = rightRotate(root);
    } else if(balance < -1 && balanceFactor(root->right) <= 0){ //Case 3: Rotate left
        cout << "Case 3 Remove" << endl;
        root = leftRotate(root);
    }else if(balance < -1 && balanceFactor(root->right) > 0){ //Case 4: Rotate right, then left
        root->right = rightRotate(root->right);
        root = leftRotate(root);
    }
    return;
    //    return root;
}

template <typename T>
T& remove_max(AVLNode <T> *&root){ //Find the max value of the left subtree
    if(root == NULL){
        cout << "Root is null" << endl;
    }
    if(root->right == NULL){   //Base case. No right node. The root is now the largest
        T &temp = root->item;
        root = NULL; //Deallocates the largest child
        return temp;
    }else{ //There is a right node. Then progress to the right
        remove_max(root->right);
    }
}

template <typename T>
int get_height(AVLNode<T>* getHeight){
    if(getHeight == NULL){
        return 0;
    }else{
        return getHeight->height;
    }
}

template <typename T>
int max(int one, int two){
    //    cout << "one: "<< one << endl;
    //    cout << "two: " << two << endl;
    if(one > two){
        return one;
    }else{
        return two;
    }
}

template <typename T>
int balanceFactor(AVLNode<T>* getMyBF){
    if(getMyBF == NULL){
        return 0;
    }else{
        //        cout << "left height:" << get_height(getMyBF->left) << endl;
        //        cout << "right height:" << get_height(getMyBF->right) << endl;
        return (get_height(getMyBF->left) - get_height(getMyBF->right));
    }
}

//Rotation for balancing AVL Trees
template <typename T>
AVLNode<T>* leftRotate(AVLNode<T> *moveMeLeft){
    AVLNode<T>* newRoot = moveMeLeft->right_node();
    AVLNode<T>* subtree = newRoot->left_node();
    //Root
    newRoot->left = moveMeLeft;
    moveMeLeft->right = subtree;

    moveMeLeft->height = max(get_height(moveMeLeft->left),get_height(moveMeLeft->right)) + 1;
    newRoot->height = max(get_height(newRoot->left),get_height(newRoot->right)) + 1;
    return newRoot;
}

template <typename T>
AVLNode<T>* rightRotate(AVLNode<T> *moveMeRight){
    AVLNode<T>* newRoot = moveMeRight->left_node();
    AVLNode<T>* subtree = newRoot->right_node();
    //Root
    newRoot->right = moveMeRight;
    moveMeRight->left = subtree;

    moveMeRight->height = max(get_height(moveMeRight->left), get_height(moveMeRight->right)) + 1;
    newRoot->height = max(get_height(newRoot->left), get_height(newRoot->right)) + 1;

    return newRoot;
}

//TREE TRAVERSAL METHODS --------------------------------------


template <typename T>
T search_Tree(AVLNode<T> *&root, T &findMe){
    if(root != NULL){
        if(root->item == findMe){
            cout << "Found: " << *root << endl;
            return root->item;
        }else if(findMe < root->item){
            return search_Tree(root->left, findMe);
        }else if(findMe > root->item){
            return search_Tree(root->right, findMe);
        }else{
            cout << "Item not found" << endl;
        }
    }
}

template <typename T>
void print(AVLNode<T> *&root, unsigned int level){
    //Print function from Savitch book:
    //----------------------------------
    //    cout << setw(4 * level) << "";
    //    if(root == NULL){
    //        cout << "[Empty]" << endl;
    //    }else if(root->is_leaf()){
    //        cout << root->item;
    //        cout << "[Leaf]" << endl;
    //    }else{
    //        cout << root->item << endl;
    //        print(root->right, level +1);
    //        print(root->left , level -1);
    //    }

    //Printing weirdly:
    //----------------------- very aesthetic
    if(root->right != NULL){
        print(root->right, level + 1);
    }
    cout << setw(4 * level) << "";
    cout << root->item << endl;
    if(root->left != NULL){
        print(root->left, level + 1);
    }
}


template <typename T>
void preorder(AVLNode<T> *&root){
    if(root != NULL){
        cout << root->item << endl;
        preorder(root->left_node());
        preorder(root->right_node());
    }
}

template <typename T>
void inorder(AVLNode<T> *&root){
    if(root != NULL){
        inorder(root->left_node());
        cout << root->item << endl;
        inorder(root->right_node());
    }
}

template <typename T>
void postorder(AVLNode<T> *& root){
    if(root != NULL){
        postorder(root->left_node());
        postorder(root->right_node());
        cout << root->item << endl;
    }
}

#endif // AVL_FUNCTIONS_H
