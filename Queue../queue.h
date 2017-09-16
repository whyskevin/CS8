#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <assert.h>
#include "../../my CS 8/DoubleLinkedList-Mac/list_functions.h"
#include "../../my CS 8/DoubleLinkedList-Mac/node.h"

template <typename T>
class Queue{
public:
    Queue();
//    ~Queue();
    void pop();
    void push(const T& item);
    bool empty();
    T& front();
    T& next(const T& item);
    T& back();
    int size() const;
    node<T>* return_head() const;

    template <typename U>
    friend ostream& operator << (ostream& out, const Queue<U> queue);

private:
    node<T>* head;
    node<T>* tail;
    int count = 0;
};

template <typename T>
Queue<T>::Queue(){
    head = nullptr;
    tail = nullptr;
}

//template <typename T>
//Queue<T>::~Queue(){
//    delete head;
//    delete tail;
//}

template <typename T>
void Queue<T>::push(const T &item){
    if(head == nullptr){
        insert_head(head, item);
//        cout << "Insert at head" << endl;
    }else{
        tail = returnTail(head);
        insert_after(tail,item);
//        cout << "Inserted to the tail" << endl;
    }
    count ++;
}

template <typename T>
void Queue<T>::pop(){
    assert(!empty());
    remove(head,head->item);
    count --;
}

template <typename T>
bool Queue<T>::empty(){
    if(count == 0){
        return true;
    }else if(count != 0){
        return false;
    }
    return false;
}

template <typename T>
T& Queue<T>::front(){
    return head->item;
}

template <typename T>
T& Queue<T>::back(){
    tail = returnTail(head);
    return tail->item;
}

template <typename T>
T& Queue<T>::next(const T& item){
    return item.next;
}

template <typename T>
int Queue<T>::size() const{
    return count;
}

template <typename T>
node<T>* Queue<T>::return_head() const{
    return head;
}

template <typename U>
ostream& operator << (ostream& out, const Queue<U> queue){
    print(out, queue.return_head());
    return out;
}


#endif // QUEUE_H
