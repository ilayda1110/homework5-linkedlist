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
    cout << "12. Find smallest node" << endl; //Task 4
    cout << "13. Get smallest node to front" << endl; //Task 5
    cout << "14. Exit" << endl;
    cout << "Choose: ";
    cin >> choice;
    return choice;
}

int main()
{
    cout << "Welcome to the Linked List Program!" << endl;

    LinkedList ll;
    int choice, index;
    bool loop = true;
    string element;

    do
    {
        choice = printMenu();
        if (choice == 1)
        {
            cout << "Enter the string you want to add: ";
            cin >> element;
            ll.push_back(element);
            cout << "Updated list: ";
            cout << ll;
            cout << "\n";
        }
        else if (choice == 2)
        {
            cout << "Enter the string you want to erase: ";
            cin >> element;
            ll.erase(element);
            cout << "Updated list: ";
            cout << ll;
            cout << "\n";
        }
        else if (choice == 3)
        {
            cout << "Enter the index: ";
            cin >> index;
            element = ll.at(index);
            cout << "The element at index " << index << ": " << element << endl;
        }
        else if (choice == 4)
        {
            cout << "Enter the index: ";
            cin >> index;
            cout << "Enter the element you want to insert: ";
            cin >> element;
            ll.insert_at(index, element);
            cout << "Updated list: ";
            cout << ll;
            cout << "\n";
        }
        else if (choice == 5)
        {
            cout << "Enter the index: ";
            cin >> index;
            cout << "Enter the element you want to insert: ";
            cin >> element;
            ll.insert_after(index, element);
            cout << "Updated list: ";
            cout << ll;
            cout << "\n";
        }
        else if (choice == 6)
        {
            cout << "Enter the index: ";
            cin >> index;
            ll.erase_at(index);
            cout << "Updated list: ";
            cout << ll;
            cout << "\n";
        }
        else if (choice == 7)
        {
            cout << ll;
        }
        else if (choice == 8)
        {
            cout << "Size of linked list: " << ll.size() << endl;
        }
        else if (choice == 9)
        {
            if(ll.empty())
            {
                cout << "Linked list is empty" << endl;
            }
            else
            {
                cout << "Linked list is not empty" << endl;
            }
        }
        else if (choice == 10)
        {
            ll.clear();
            cout << "Updated list: ";
            cout << ll;
            cout << "\n";
        }
        else if (choice == 11)
        {
            Node *middleNode = ll.findMiddleNode();
            if(middleNode == nullptr)
            {
                cout << "List is empty" << endl;
            }
            else
            {
                cout << "Middle node: " << middleNode->data << endl;
            }
        }
        else if(choice == 12)
        {
            Node *smallestNode = ll.getSmallestNode();
            if(smallestNode == nullptr)
            {
                cout << "List is empty" << endl;
            }
            else
            {
                cout << "Smallest node: " << smallestNode->data << endl;
            }
        }
        else if(choice == 13)
        {
            ll.moveSmallestToFront();
            cout << ll;
        }
        else if (choice == 14)
        {
            cout << "Bye!";
            loop = false;
        }
    } while (loop);


    return 0;
}