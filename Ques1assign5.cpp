
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class LinkedList
{
    Node* head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insertBeginning(int x)
    {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    void insertEnd(int x)
    {
        Node* newNode = new Node(x);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    void insertBefore(int key, int x)
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        if (head->data == key)
        {
            insertBeginning(x);
            return;
        }

        Node* temp = head;

        while (temp->next != NULL &&
               temp->next->data != key)
        {
            temp = temp->next;
        }

        if (temp->next == NULL)
        {
            cout << "Value not found\n";
            return;
        }

        Node* newNode = new Node(x);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertAfter(int key, int x)
    {
        Node* temp = head;

        while (temp != NULL && temp->data != key)
            temp = temp->next;

        if (temp == NULL)
        {
            cout << "Value not found\n";
            return;
        }

        Node* newNode = new Node(x);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteBeginning()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;

        while (temp->next->next != NULL)
            temp = temp->next;

        delete temp->next;
        temp->next = NULL;
    }

    void deleteSpecific(int key)
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        if (head->data == key)
        {
            deleteBeginning();
            return;
        }

        Node* temp = head;

        while (temp->next != NULL &&
               temp->next->data != key)
        {
            temp = temp->next;
        }

        if (temp->next == NULL)
        {
            cout << "Value not found\n";
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    void search(int key)
    {
        Node* temp = head;
        int position = 1;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << "Found at position "
                     << position << endl;
                return;
            }

            temp = temp->next;
            position++;
        }

        cout << "Value not found\n";
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    ~LinkedList()
    {
        while (head != NULL)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    LinkedList list;
    int choice, x, key, type;

    do
    {
        cout << "\n--- Singly Linked List ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before a value\n";
        cout << "4. Insert after a value\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete a specific value\n";
        cout << "8. Search a value\n";
        cout << "9. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> x;
            list.insertBeginning(x);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> x;
            list.insertEnd(x);
            break;

        case 3:
            cout << "Enter existing value: ";
            cin >> key;
            cout << "Enter new value: ";
            cin >> x;
            list.insertBefore(key, x);
            break;

        case 4:
            cout << "Enter existing value: ";
            cin >> key;
            cout << "Enter new value: ";
            cin >> x;
            list.insertAfter(key, x);
            break;

        case 5:
            list.deleteBeginning();
            break;

        case 6:
            list.deleteEnd();
            break;

        case 7:
            cout << "Enter value to delete: ";
            cin >> key;
            list.deleteSpecific(key);
            break;

        case 8:
            cout << "Enter value to search: ";
            cin >> key;
            list.search(key);
            break;

        case 9:
            list.display();
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}

