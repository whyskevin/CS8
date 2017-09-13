#ifndef AVLNODE_H
#define AVLNODE_H
#include <iostream>
#include <ostream>

using namespace std;

template <typename T>
struct AVLNode{
    AVLNode();
    AVLNode(T new_item);
    AVLNode(const AVLNode<T> &other);
    AVLNode<T>*& left_node();
    AVLNode<T>*& right_node();

    bool is_leaf() const;
    void set_left(AVLNode<T>* newLeft);
    void set_right(AVLNode<T>* newRight);

    T item;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode<T>& operator = (const AVLNode<T> &otherNode);

    //    AVLNode<T>& operator [](int i);
    template <typename U>
    friend bool operator == (const AVLNode<U> &first, const AVLNode<U> &second);

    template <typename U>
    friend bool operator <= (const AVLNode<U> &first, const AVLNode<U> &second);

    template <typename U>
    friend ostream& operator << (ostream &out, const AVLNode<U> &printMe);
};

template <typename T>
AVLNode<T>::AVLNode(){
    left = NULL;
    right = NULL;
    item = 0;
    height = 1;
}

template <typename T>
AVLNode<T>::AVLNode(T new_item){
    item = new_item;
    left = NULL;
    right = NULL;
    height = 1;
}

template <typename T>
AVLNode<T>::AVLNode(const AVLNode<T> &other){
    *this = other;
}

template <typename T>
bool AVLNode<T>::is_leaf() const{
    return ((left == NULL) && (right == NULL));
}

template <typename T>
void AVLNode<T>::set_left(AVLNode<T>* newLeft){
    left = newLeft;
}

template <typename T>
void AVLNode<T>::set_right(AVLNode<T>* newRight){
    right = newRight;
}

template <typename T>
AVLNode<T>*& AVLNode<T>::left_node(){
    return left;
}

template <typename T>
AVLNode<T>*& AVLNode<T>::right_node(){
    return right;
}


//Operator overloading
template <typename U>
ostream & operator << (ostream &out, const AVLNode<U> &printMe){
    out << "(" << printMe.item << ")";
    return out;
}

template<typename T>
AVLNode<T>& AVLNode<T>::operator = (const AVLNode<T> &otherNode){
    if(this != &otherNode){
        *this = otherNode;
        return *this;
    }
}

template <typename U>
bool operator <= (const AVLNode<U> &first, const AVLNode<U> &second){
    return (first.item <= second.item);
}

template <typename U>
bool operator == (const AVLNode<U> &first, const AVLNode<U> &second){
    return (first.item == second.item);
}

#endif // AVLNODE_H
