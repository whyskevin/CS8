#ifndef AVL_TEST_H
#define AVL_TEST_H
#include <iostream>
#include "avl_functions.h"
#include "avl_tree.h"
#include "avlnode.h"

using namespace std;

void test_AVL();

void test_AVL(){
    AVL_Tree<int> one;
    AVL_Tree<int> two;
    //Normal insert to test the AVL rules
    cout << "---------------Inserting--------------" << endl;
    one.insert_AVL(30);
    one.insert_AVL(20);
    one.insert_AVL(10); //Inserting this will result in a left subtree, left-deep. Rotate right. Case 1
    cout << one << endl;
    one.insert_AVL(1);
    one.insert_AVL(2); //Left subtree is right deep. Case 2. Rotate left then right
    cout << one << endl;


    two.insert_AVL(10);
    two.insert_AVL(20);
    two.insert_AVL(30);//Right subtree is right deep. Case 3. Rotate left
    cout << two << endl;

    two.insert_AVL(35);
    two.insert_AVL(19);
    two.insert_AVL(18);
    cout << two << endl;//Right subtree is left deep. Case 4. Rotate right then left

    cout << "----------- Deleting ----------" << endl;
    two.delete_item(35); //Delete an item off a leaf. Tree is still balanced
    cout << two << endl;

    two.delete_item(30);//After deletion, the tree will be unbalanced. 18 will become the new root to be a balanced AVL Tree
    cout << two << endl;
}


#endif // AVL_TEST_H
