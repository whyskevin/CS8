#include <iostream>
#include "list_functions.h"
#include "node.h"

using namespace std;

int main(int argc, char *argv[])
{

    node<char> *headPtr;
    init_head(headPtr);
    cout << endl << endl;
    insert_head(headPtr, 'C');
    print(std::cout, headPtr);
    insert_head(headPtr, 'A');
    print(std::cout, headPtr);
    node<char> *afterme = search(headPtr, 'C');
    insert_after(afterme, 'D');
    print(std::cout, headPtr);
    node<char> *beforeme = search(headPtr, 'C');
    insert_before(beforeme, 'B');
    print(std::cout, headPtr);
    clear(headPtr);
//    node<char>* newHead = _copy(headPtr);
//    print(std::cout, newHead); Doesn't copy the original head
      print(std::cout, headPtr);

    return 0;
}
