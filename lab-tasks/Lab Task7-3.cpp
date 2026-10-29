#include <iostream>
using namespace std;

class LinkedList
{
    struct Node
    {
        int data;
        Node* next;
    };

    Node* head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insert(int value)
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    void sort()
    {
        Node* i = head;

        while (i != NULL)
        {
            Node* j = i->next;

            while (j != NULL)
            {
                if (i->data > j->data)
                {
                    int temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }

                j = j->next;
            }

            i = i->next;
        }
    }

    void display()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    Node* middle(Node* start, Node* last)
    {
        if (start == NULL)
            return NULL;

        Node* slow = start;
        Node* fast = start->next;

        while (fast != last)
        {
            fast = fast->next;

            if (fast != last)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        return slow;
    }

    void binarySearch(int key)
    {
        Node* start = head;
        Node* last = NULL;

        while (start != last)
        {
            Node* mid = middle(start, last);

            if (mid == NULL)
                break;

            if (mid->data == key)
            {
                cout << "Number found!" << endl;
                return;
            }

            if (mid->data < key)
            {
                start = mid->next;
            }
            else
            {
                last = mid;
            }
        }

        cout << "Number not found!" << endl;
    }
};

int main()
{
    LinkedList list;
    int n, value, key;

    cout << "Enter size: ";
    cin >> n;

    if (n < 1)
    {
        cout << "Invalid size!" << endl;
        return 0;
    }

    cout << "Enter numbers: ";

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        list.insert(value);
    }

    list.sort();
    #Hasnain Qazi
    cout << "Sorted Linked List: ";
    list.display();

    cout << "Enter number to search: ";
    cin >> key;

    list.binarySearch(key);

    return 0;
}