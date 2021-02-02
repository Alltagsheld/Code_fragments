#include<iostream>

#include "avltree.h"
#include "test.h"
#include "benchmark.h"

using namespace std;

void menu(AVLTree avl)
{
    int c;
    int key;
    string value;

    while (true) {
        cout << "1. Insert Element" << endl;
        cout << "2. Show Balanced AVL Tree" << endl;
        cout << "3. Traverse in-order" << endl;
        cout << "4. Traverse pre-order" << endl;
        cout << "5. Traverse post-order" << endl;
        cout << "6. Remove a value"<<endl;
        cout << "7. Start testing"<<endl;
        cout << "8. Check for Member in tree"<<endl;
        cout << "9. Save to File" << endl;
        cout << "10. Benchmark" << endl;
        cout << "Enter your Choice: ";
        cin >> c;
        switch (c) {
        case 1:
            cout << "Enter key to be inserted (int): ";
            cin >> key;
            cout << "Enter value to be inserted (string): ";
            cin >> value;
            avl.checkInsert(key, value);
            break;
        case 2:
            if (avl.empty()) {
                cout << "Tree is Empty" << endl;
                continue;
            }
            cout << "Balanced AVL Tree:" << endl;
            avl.show();
            cout<<endl;
            break;
        case 3:
            cout << "Inorder Traversal:" << endl;
            avl.inorder();
            cout << endl;
            break;
        case 4:
            cout << "Preorder Traversal:" << endl;
            avl.preorder();
            cout << endl;
            break;
        case 5:
            cout << "Postorder Traversal:" << endl;
            avl.postorder();
            cout << endl;
            break;
        case 6:
        {
            cout <<"gimme a key" << endl;
            cin >>key;
            avl.remove(key);
            break;
        }
        case 7:
            cout <<"bigInsertionTest: "<<endl;
            bigInsertionTest(avl);
            avl.show();
            system("PAUSE");
            cout <<"removeTest: "<<endl;
            removeTest(avl);
            avl.show();
            system("PAUSE");
            cout <<"findTest: "<<endl;
            findTest(avl);
            break;
        case 8:
        {
            cout <<"give me a value to confirm its in the tree"<<endl;
            cin>> key;
            if(avl.member(key))
            {
                cout <<"its in the tree\n"<<endl;
            }
            else
                cout <<"its not in the tree\n"<<endl;
            break;
        }
        case 9:
            avl.writeDot("demo.dot");
            break;
        case 10:
            return;
        default:
            cout << "Not understood. Enter a number between 1 and 8." << endl;
        }
    }
}

int main() {

    AVLTree avl;

    //    bigInsertionTest(avl);
    //    removeTest(avl);
    //    findTest(avl);

    //    benchmark();
    //    return 0;

    menu(avl);
    return 0;
}
