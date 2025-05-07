#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
    Node(int val, Node *next1)
    {
        data = val;
        next = next1;
    }
    ~Node()
    {
        if (next != NULL)
        {
            // cout << "Node Desctructor of data =" << data << endl;
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

    ~List()
    {
        if (head != NULL)
        {

            delete head;
            head = NULL;
        }
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);

        // check if ll is empty or not
        if (head == NULL)
        {
            head = tail = newNode;
        }
        // if ll in not empty
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

    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << " NULL";
        cout << endl;
    }

    void insert(int val, int pos)
    {
        Node *newNode = new Node(val);
        Node *temp = head;

        // First find the position
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << "LL is empty.\n";
            return;
        }
        Node *temp = head;

        // Update the head value
        head = head->next;

        // break the connection
        temp->next = NULL;
        delete temp;
    }
    void pop_back()
    {
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    int searchItr(int key)
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

    int helper(Node *temp, int key)
    {
        // Base Case
        if (temp->next == NULL)
        {
            return -1;
        }
        // check if data == key
        if (temp->data == key)
        {
            return 0;
        }

        int idx = helper(temp->next, key);

        if (idx == -1)
        {
            return -1;
        }
        return idx + 1;
    }
    int searchRecur(int key)
    {
        return helper(head, key);
    }

    void reverse()
    {
        Node *curr = head;
        Node *prev = NULL;

        while (curr != NULL)
        {
            Node *next = curr->next;
            curr->next = prev;

            // Updation
            prev = curr;
            curr = next;
        }
        // at last new head=prev
        head = prev;
    }
    int getSize()
    {
        int size = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            size++;
        }

        return size;
    }

    void removeLastN(int n)
    {
        int size = getSize();
        Node *prev = head;

        for (int i = 1; i < (size - n); i++)
        {
            prev = prev->next;
        }

        // which node is going to be deleted
        Node *deletedNode = prev->next;
        cout << deletedNode->data << endl;
        // To break the connection
        prev->next = prev->next->next;
    }
};

Node *splitAtMid(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    // Now cut the linked list into half into 2
    if (prev != NULL)
    {
        prev->next = NULL;
    }
    return slow;
}

Node *merge(Node *left, Node *right)
{
    Node *t1 = left;
    Node *t2 = right;

    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;

    while (t1 != NULL && t2 != NULL)
    {
        if (t1->data < t2->data)
        {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }

    if (t1)
        temp->next = t1;
    else
        temp->next = t2;

    return dummyNode->next;
}

Node *mergeSort(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *rightHead = splitAtMid(head);

    Node *left = mergeSort(head);
    Node *right = mergeSort(rightHead);

    return merge(left, right);
}

Node *reverseLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    // Breaking of the linked list
    Node *newHead = reverseLinkedList(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}

Node *zigZag(Node *head)
{

    if (head == NULL || head->next == NULL)
        return head;

    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;

    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL && fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *newHead = reverseLinkedList(slow->next);
    slow->next = NULL;

    Node *first = head;
    Node *second = newHead;

    while (second != NULL)
    {
        if (first)
        {
            temp->next = first;
            temp = first;
            first = first->next;
        }
        if (second)
        {
            temp->next = second;
            temp = second;
            second = second->next;
        }
    }

    // if (first != NULL)
    //     temp->next = first;
    // else if (second != NULL)
    //     temp->next = second;
    if (first)
    {
        temp->next = first;
    }
    else if (second)
    {
        temp->next = second;
    }

    return dummyNode->next;
}

int main()
{
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    // ll.printList();
    // ll.insert(100, 2);
    // ll.pop_front();
    // ll.pop_back();
    ll.printList();
    zigZag(ll.head);
    ll.printList();
    // cout << ll.searchItr(3) << "\n";
    // cout << ll.searchItr(3) << "\n";
    // ll.reverse();

    // ll.head = mergeSort(ll.head);
    // ll.printList();
    return 0;
}

// void merge()[
// List result;

// if (left->data <= right->data)
// {
//     result = left;
//     result->next = merge(left->next, right);
// }
// else
// {
//     result = right;
//     result->next = merge(left, right->next);
// }
// ]