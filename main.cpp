#include <iostream>
#include "LinkedList_string.h"

using namespace std;

int printMenu()
{
    int choice;
    cout << "Menu:" << endl;
    cout << "1. Add an element" << endl;
    cout << "2. Remove an element by value" << endl;
    cout << "3. Access an element at index" << endl;
    cout << "4. Insert an element at index" << endl;
    cout << "5. Insert an element after index" << endl;
    cout << "6. Remove an element at index" << endl;
    cout << "7. Print the linked list" << endl;
    cout << "8. Print the size of the linked list" << endl;
    cout << "9. Check if the linked list is empty" << endl;
    cout << "10. Clear the linked list" << endl;
    cout << "11. Find middle node" << endl; //Task 3
    cout << "12. Exit" << endl;
    cout << "Choose: ";
    cin >> choice;
    return choice;
}

int main()
{
    cout << "Welcome to the Linked List Program!" << endl;

    int choice;
    bool loop = true;

    do
    {
        choice = printMenu();
        if (choice == 1)
        {

        }
        else if (choice == 2)
        {

        }
        else if (choice == 3)
        {

        }
        else if (choice == 4)
        {

        }
        else if (choice == 5)
        {

        }
        else if (choice == 6)
        {

        }
        else if (choice == 7)
        {

        }
        else if (choice == 8)
        {

        }
        else if (choice == 9)
        {

        }
        else if (choice == 10)
        {

        }
        else if (choice == 11)
        {

        }
        else if (choice == 12)
        {
            cout << "Bye!";
            loop = false;
        }
    } while (loop);


    return 0;
}