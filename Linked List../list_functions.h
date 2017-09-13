#ifndef LIST_FUNCTIONS_H
#define LIST_FUNCTIONS_H
#include <iostream>
//#include "list_functions.h"
#include "assert.h"
#include "node.h"

using namespace std; //Standard namespace

//Initializes the head with NULL
template <typename T>
void init_head(node<T> *&head);

//Insert the item at the head of a list
// - Takes an item to insert to the head
template <typename T>
node<T>* insert_head(node<T> *&head, T item);
// - Takes a node pointer to insert to the head
template <typename T>
node<T>* insert_head(node<T> *&head, node<T> *&insert_me);

//----------------

//Insert the item after the given nodePtr
// - Takes an item to insert after a node
template <typename T>
node<T>* insert_after(node<T> *&afterme, T item);
// - Takes a node pointer to insert after a node
template <typename T>
node<T>* insert_after(node<T> *&afterme, node<T> *&insert_me);

//----------------

//Insert the item before the given nodePtr
// - Takes an item to insert before another nodeptr
template <typename T>
node<T>* insert_before(node<T> *&beforeme, T item);
// - Takes a node pointer to insert before another node pointer
template <typename T>
node<T>* insert_before(node<T> *&beforeme, node<T> *&insert_me);


//----------------
//Inserts an ITEM SORTED into the list
// - Takes an item to insert

template <typename T>
node<T>* insert_sorted(node<T> *&head, T item);

// - Takes a node ptr
template <typename T>
node<T>* insert_sorted(node<T> *&head, node<T> *&insert_me);

//Compares the given item and
// - Takes an item
template <typename T>
node<T>* where_this_goes(node<T> *headPtr, T item);
// - Takes a node ptr
template <typename T>
node<T>* where_this_goes(node<T> *headPtr, node<T> *insert_me);

//Search the list for the given item
template <typename T>
node<T>* search(node<T> *headPtr, T item);

//Creates a copy of the given list
template <typename T>
node<T>* _copy(node<T> *head);

//Removes the node which holds the given item. Returns null if item DNE
template <typename T>
node<T>* remove(node<T> *& headPtr, T item);

//Removes the node and deletes it
template <typename T>
node<T>* _delete (node<T> * headPtr, T item);

//Returns a pointer to the tail of the list
template <typename T>
node<T>* returnTail(node<T> *headPtr);

//Return head node of the list. Used for popping in Stack
template <typename T>
node<T>* returnHead(node<T> *headPtr);

//Displays the entire linkedlist with the given headPtr
template <typename T>
void print(ostream& out, const node<T> *headPtr);

//Deletes the list accessed by the given headPtr
template <typename T>
void clear(node<T> *&headPtr);

//Initializes a node with null
template <typename T>
void init_head(node<T> *&head){
    head = nullptr;
}

//~~~~~~~~~~~~~~~~~~~ INSERT FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template <typename T>
node<T>* insert_head(node<T> *&head, T item){
    node<T> * newNode = new node<T>(item);    //Create new node with item
    return insert_head(head,newNode); //Inserts a node*
}

template <typename T>
node<T>* insert_head(node<T> *&head, node<T> *&insert_me){
    insert_me->next = head;  //newNode.next assigned former head address
    if(head != nullptr){  //There exists a node within the Linked List
        head->prev = insert_me;
    }
    insert_me->prev = nullptr;
    head = insert_me; //Head points to the new head
    return head;
}

template <typename T>
node<T>* insert_after(node<T> *&afterme, T item){
    node<T> * newNode = new node<T>(item); //Create new node for the item
    return insert_after(afterme, newNode);
}

template <typename T>
node<T>* insert_after(node<T> *&afterme, node<T> *&insert_me){

    node<T> *temp = afterme->next;
    if(temp != nullptr){
        insert_me->next = afterme->next;
        afterme->next = insert_me;
        insert_me->prev = afterme;
        temp->prev = insert_me;
    }else{  //if afterme.next is the nullptr...aka it's at the end of the list
        insert_me->next = nullptr;
        insert_me->prev = afterme;
        afterme->next = insert_me;
    }
    return insert_me;
}

template <typename T>
node<T>* insert_before(node<T> *&beforeme, T item){
    node<T> *newNode = new node<T>(item);
    return insert_before(beforeme, newNode);
}

template <typename T>
node<T>* insert_before(node<T> *&beforeme, node<T> *&insert_me){

    if(beforeme->prev == nullptr){ //If beforeme is the head
        insert_head(beforeme, insert_me);
        return insert_me;
    }
    if (beforeme != nullptr){ //If before me isn't the head, and isn't null
        node<T> *tempBefore = beforeme->prev;
        insert_me->prev = tempBefore;
        insert_me->next = beforeme;
        beforeme->prev = insert_me;
        tempBefore->next = insert_me;
    }
    return insert_me;
}

template <typename T>
node<T>* insert_sorted(node<T> *&head, T item){
    cout << "is item" << endl;
    node<T> *newNode = new node<T>(item);    //Create new node with item
    return insert_sorted(head,newNode);
}

template <typename T>
node<T>* insert_sorted(node<T> *&head, node<T> *&insert_me){
    //Check if the head is pointing to nothing. This means the list is empty and we must insert at the head
    if(head == nullptr){
//        cout << "Inserted to head" << endl;
        return insert_head(head,insert_me);
    }
    //Else, finds the location of where to insert this node
    node<T> *where = where_this_goes(head,insert_me);
    //If all elements in the list are larger than the node, insert the new node at the head
    if(where == nullptr){
//        cout << "Inserted to head because where == nullptr" << endl;
        return insert_head(head,insert_me);
    }else if (where != nullptr){ //If anything returned isn't null, we insert the new node after this returned node
        return insert_after(where,insert_me);
    }
}

template <typename T>
node<T>* where_this_goes(node<T> *headPtr, T item){
    cout << "Where this goes item" << endl;
    node<T> * newNode = new node<T>(item);    //Create new node with item
    return where_this_goes(headPtr,newNode);
}

template <typename T>
node<T>* where_this_goes(node<T> *headPtr, node<T> *insert_me){

    if(headPtr == nullptr){ //List is empty
        //        cout << "headPtr is nullptr" << endl;
        return nullptr;
    }
    if(headPtr->item > insert_me->item){
        return nullptr;
    }
    while(headPtr->next != NULL){ //Let's iterate through the list from the head
        if(headPtr->item <= insert_me->item){
            if(headPtr->next->item > insert_me->item){ //Check if the next is larger
                return headPtr;
            }
        }
        headPtr = headPtr->next;
    }
    if(headPtr->next == nullptr){
        if(headPtr->item > insert_me->item){ //The head is biggerthan what we have
            return nullptr;
        }else if(headPtr->item <= insert_me->item){
            return headPtr;
        }
    }
    cout << "END OF WHERE THIS GOES REACHED" << endl;
    return nullptr;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~ END OF INSERT FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~


template <typename T>
node<T>* search(node<T> *headPtr, T item){
    //    cout << "Search begins" << endl;
    node<T> *temp = headPtr;
    while(temp->next != NULL){
        if(temp->item == item){ //If the item is found, return the node which holds the item
            return temp;
        }
        temp = temp->next; //Moves the walker to the next node
    }
    if(temp->next ==  NULL){   //HeadPtr is null; list is empty or temp is at the last node.
        if(temp->item == item){ //Item does exist
            return temp;    //Return the node
        }else{  //Item doesn't exist
            cout << "Item doesn't exist" << endl;
            return nullptr;
        }
    }
    return nullptr;
}

template <typename T>
node<T>* remove(node<T> *& headPtr, T item)
{
    node<T> *whatToRemove = search(headPtr,item);
    //    cout << "whatToRemove: " << whatToRemove << ":" << whatToRemove->item << endl;
    if(whatToRemove == nullptr){
        cout << "Item does not exist in the linked list." << endl;
        return nullptr;
    }
    //Pointer to previous node is the node previous to whatToRemove
    node<T> *prevNode = whatToRemove->prev;
    //    cout << "After prevNode \n";
    node<T> *nextNode = whatToRemove->next;
    if(whatToRemove == headPtr){
        headPtr = nextNode; //Reassigns the headptr to the following node
    }
    //    cout << "After nextNode \n";
    if(prevNode != nullptr){
        prevNode->next = whatToRemove->next;
    }
    //    cout << "After prevNode->next \n";
    if(nextNode != nullptr){
        nextNode->prev = whatToRemove->prev;
    }
    //When whatToRemove is finished
    whatToRemove->next = nullptr;
    whatToRemove->prev = nullptr;
    //    cout << "End \n";
    return whatToRemove;
}

template <typename T>
void print(ostream& out, const node<T> *headPtr){
    out << "H->";
    while(headPtr != NULL){
        //                out << "(" << headPtr << "," << headPtr->item << ") -> ";
        out << "(" << headPtr->item << ") ->";
        headPtr = headPtr->next;
    }
    out << "|||"<< endl;
}

template <typename T>
node<T>* _delete (node<T> * headPtr, T item){
    node<T>* nodeToRemove = search(headPtr, item);
    node<T>* whereCursor = NULL;
    if(nodeToRemove->next == NULL){
        whereCursor = nodeToRemove->prev;
    }else{
        whereCursor = nodeToRemove->next;
    }
    delete (remove(headPtr, item));
    return whereCursor;
}

template <typename T>
node<T>* _copy(node<T>* head){
    node<T>* newHead;
    init_head(newHead);
    node<T>* tail = head;
    while (tail->next != NULL){
        tail = tail->next;  //Find tail of the list
    }
    //    cout << "Tail is " << tail << " , " <<  tail->item << endl;
    while(tail->prev != NULL){
        insert_head(newHead, tail->item);
        tail = tail->prev;
    }
    insert_head(newHead, tail->item);
    return newHead;
}

template <typename T>
void clear(node<T> *&headPtr){
    //    cout << "Clearing list..." << endl;
    node<T> *tempNext = NULL;
    while(headPtr != NULL){ //Will crash if tempNext removed
        tempNext = headPtr->next;
        _delete(headPtr, headPtr->item);
        headPtr = tempNext;
    }
    //    cout << "List cleared!" << endl;
}

template <typename T>
node<T>* returnTail(node<T> *headPtr){

    if(headPtr == NULL){
        cout << "Headptr is tail ptr" << endl;
        return headPtr;
    }
    while(headPtr->next != NULL){
        headPtr = headPtr->next;
        if(headPtr->next == nullptr){   //Returns the tail node
            return headPtr;
        }
    }
    return headPtr;
}

#endif // LIST_FUNCTIONS_H
