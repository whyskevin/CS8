#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <assert.h>
//#include "../../my CS 8/ListClass/mylist.h"
#include "../../my CS 8/DoubleLinkedList-Mac/list_functions.h"
#include "../../my CS 8/DoubleLinkedList-Mac/node.h"

template <typename T>
class Stack{
public:
    Stack();
    ~Stack();
    void push( T item);
    void pop();

    bool empty();
    unsigned int size();
    T& top();

    node<T>* return_head() const;
    Stack<T>& operator = (const Stack<T>& otherList);

    template <typename U>
    friend ostream& operator << (ostream& out, const Stack<U>& list);

private:
    unsigned int size_of_stack = 0;
    node<T>* head;

};

template <typename T>
Stack<T>::Stack(){
   init_head(head);
}

template <typename T>
Stack<T>::~Stack(){
    delete head;
}

template <typename T>
void Stack<T>::push(T item){
    insert_head(head, item);
    size_of_stack++;
}

template <typename T>
void Stack<T>::pop(){
    assert(!empty());
    remove(head, head->item);
    size_of_stack--;
}

template <typename T>
Stack<T>& Stack<T>::operator = (const Stack<T>& otherList){
    head = _copy(otherList.return_head());
    return *this;
}

template <typename T>
T& Stack<T>::top(){
    return head->item;
}

template <typename T>
bool Stack<T>::empty(){
    if(size_of_stack != 0){
        return true;
    }else{
        return false;
    }
}

template <typename T>
unsigned int Stack<T>::size(){
    return size_of_stack;
}

template <typename T>
node<T>* Stack<T>::return_head() const{
    return head;
}

template <typename U>
ostream& operator << (ostream& out, const Stack<U>& list){
    print(out,list.return_head());
    return out;
}



#endif // STACK_H
