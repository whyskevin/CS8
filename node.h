#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

template <typename T>
struct node
{
public:
    node();
    node(T new_item);
    T& getItem();

    template <typename U>
    friend ostream& operator << (ostream& out, const node<U>& printme);
    node *next, *prev;
    T item;

};

template <typename T>
node<T>::node() //Default
{
   next = nullptr;
   prev = nullptr;
   item = 0;
}

template <typename T>
node<T>::node(T new_item)
{
    item = new_item;
    next = nullptr;
    prev = nullptr;
}

template <typename T>
T& node<T>::getItem(){
    return item;
}

template <typename U>
ostream& operator << (ostream& out, const node<U>& printme){
    out << printme.item;
    return out;
}

#endif // NODE_H
