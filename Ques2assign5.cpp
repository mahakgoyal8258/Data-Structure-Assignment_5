
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

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int n, x, key, count = 0;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> x;

        Node* newNode = new Node(x);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Enter key: ";
    cin >> key;

    // Delete matching nodes, including at the beginning
    while (head != NULL && head->data == key)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    // Delete matching nodes after the head
    Node* temp = head;

    while (temp != NULL && temp->next != NULL)
    {
        if (temp->next->data == key)
        {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
            count++;
        }
        else
        {
            temp = temp->next;
        }
    }

    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";

    temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";

    // Free remaining nodes
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

