#ifndef AVL_TREE_H
#define AVL_TREE_H
#include <iostream>
#include "AVLNode.h"
#include "avl_functions.h"

using namespace std;

template <typename T>
class AVL_Tree{
public:
    AVL_Tree();
    ~AVL_Tree();

    void insert_AVL(const T &item);

    //Traverse in order. This will go to left -> root -> right
    void inorder_AVL();

    //Traverse preorder. This will go to root -> left -> right
    void preorder_AVL();

    //Traverse postorder. This will go to left -> right -> root
    void postorder_AVL();

    T search_AVL(T item);

    void delete_item(T item);

    AVLNode<T>*& returnRoot();

    template <typename U>
    friend ostream& operator << (ostream& out, AVL_Tree<U>& AVL);

private:
    AVLNode<T> * root;
};

template <typename T>
AVL_Tree<T>::AVL_Tree(){
    root = NULL;
}

template <typename T>
AVL_Tree<T>::~AVL_Tree(){
    delete root;
}

template <typename T>
void AVL_Tree<T>::insert_AVL(const T& item){
    insert_Tree(root, item);
}

//Traverse in order. This will go to left -> root -> right
template <typename T>
void AVL_Tree<T>::inorder_AVL(){
    inorder(root);
}

//Traverse preorder. This will go to root -> left -> right
template <typename T>
void AVL_Tree<T>::preorder_AVL(){
    preorder(root);
}

//Traverse postorder. This will go to left -> right -> root
template <typename T>
void AVL_Tree<T>::postorder_AVL(){
    postorder(root);
}

template <typename T>
AVLNode<T>*& AVL_Tree<T>::returnRoot(){
    return root;
}

template <typename U>
ostream& operator << (ostream& out, AVL_Tree<U>& AVL){
    print( AVL.returnRoot(),0);
    return out;
}

template <typename T>
void AVL_Tree<T>::delete_item(T item){
    deleteItem(root, item);
}

template <typename T>
T AVL_Tree<T>::search_AVL(T item){
    return search_Tree(root,item);
}

#endif // AVL_TREE_H
