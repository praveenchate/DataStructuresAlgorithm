#include <iostream>
using namespace std;

class Node
{
public: // Change access specifier to public for simplicity
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
    // After deleting the head now we have to delete the all the node next value or else the value of the
    // another node will still persists.
    ~Node()
    {
        // cout << "~Node " << data << endl;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

class List
{

public:
    Node *head;
    Node *tail;
    List()
    {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val); // Dynamic memory allocation
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
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

    void print() // Display method
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void insert(int pos, int val)
    {
        Node *newNode = new Node(val);
        // Temp node
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                return;
            }
            temp = temp->next;
        }

        // At the end temp node is pointing towards pos-1 or prev/left node
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Creating newNode ->dynamic memory allocation.Now we have to delete our whole list or free the memory.
    ~List()
    {
        // cout << "~List" << endl;
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
    }
    // Another way of using destructor.
    //  ~List() // Destructor to free memory
    //  {
    //      Node *current = head;
    //      while (current != NULL)
    //      {
    //          Node *nextNode = current->next;
    //          delete current;
    //          current = nextNode;
    //      }
    //  }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << "Linked list is empty.\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    void pop_back()
    {
        if (head == NULL)
        {
            cout << "Linked list is empty.\n";
            return;
        }
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        // Now we got the N-1 element position stored in temp variable;
        temp->next = NULL;
        delete tail;
        tail = temp; // tail will be pointing towards the last element again
    }

    int iterativeSearch(int key)
    {
        Node *temp = head;
        int idx = 0;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return idx;
            }

            temp = temp->next;
            idx++;
        }
        return -1;
    }
};

bool detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

void removeCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    bool isCycle = false;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            cout << "Cycle detected\n";
            isCycle = true;
            break;
        }
    }

    if (!isCycle)
    {
        cout << "Cycle is not detected.\n";
        return;
    }

    slow = head;

    // when slow and fast are at the same point or head.
    if (slow == fast)
    {
        while (fast->next != slow)
        {
            fast = fast->next;
        }
        fast->next = NULL;
    }
    else
    {
        Node *prev = fast;
        while (slow != fast)
        {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL;
    }
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}

int main()
{
    // List ll; // Correct object creation
    // ll.push_front(30);
    // ll.push_front(20);
    // ll.push_front(10);
    // ll.push_back(40);
    // ll.push_back(50);
    // ll.push_back(60);
    // ll.print(); // Print the list
    // ll.insert(2, 100);
    // ll.pop_front();
    // ll.pop_front();
    // ll.pop_back();
    // ll.pop_back();
    // ll.print(); // Print the list
    // cout << ll.iterativeSearch(1) << endl;

    // cout << "Linked List: ";

    List ll;

    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    // Create a cycle
    if (ll.head != NULL && ll.tail != NULL)
    {
        ll.tail->next = ll.head;
    }

    // // Check for a cycle
    // if (detectCycle(ll.head))
    // {
    //     cout << "Cycle detected!" << endl;
    // }
    // else
    // {
    //     cout << "No cycle detected." << endl;
    // }
    removeCycle(ll.head);
    printList(ll.head);
    return 0;
}
