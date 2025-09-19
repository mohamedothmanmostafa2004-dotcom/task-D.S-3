#include <iostream>
#include "DoublyLinkedList.h"

using std::cin;
using std::cout;
using std::endl;

void printMenu()
{
    cout << "\n========= Doubly Linked List =========\n";
    cout << "1. Insert Left\n";
    cout << "2. Insert Right\n";
    cout << "3. Insert at Position\n";
    cout << "4. Remove Left\n";
    cout << "5. Remove Right\n";
    cout << "6. Remove at Position\n";
    cout << "7. Search\n";
    cout << "8. Edit at Position\n";
    cout << "9. Print List\n";
    cout << "10. Print Reverse\n";
    cout << "0. Exit\n";
    cout << "--------------------------------------\n";
    cout << "Enter your choice: ";
}

int main()
{
    DoublyLinkedList dll;
    int choice = -1;

    while (true)
    {
        printMenu();
        if (!(cin >> choice))
        {
            cout << "Invalid input.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 0)
        {
            cout << "Exiting program.\n";
            break;
        }

        int val, pos;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            dll.insertLeft(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            dll.insertRight(val);
            break;
        case 3:
            cout << "Enter position and value: ";
            cin >> pos >> val;
            dll.insertAtPosition(pos, val);
            break;
        case 4:
            dll.removeLeft();
            break;
        case 5:
            dll.removeRight();
            break;
        case 6:
            cout << "Enter position: ";
            cin >> pos;
            dll.removeAtPosition(pos);
            break;
        case 7:
            cout << "Enter value: ";
            cin >> val;
            dll.search(val);
            break;
        case 8:
            cout << "Enter position and new value: ";
            cin >> pos >> val;
            dll.editAtPosition(pos, val);
            break;
        case 9:
            dll.print();
            break;
        case 10:
            dll.printReverse();
            break;
        default:
            cout << "Unknown choice.\n";
            break;
        }
    }

    return 0;
}
