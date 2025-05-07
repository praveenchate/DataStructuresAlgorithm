#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int val, Node *next1, Node *prev1)
    {
        data = val;
        next = next1;
        prev = prev1;
    }
    

public:
    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

Node *convertArrDll(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        prev->next = temp;
        temp->prev = prev;
        prev = temp;
    }
    return head;
}

Node *deleteHead(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *temp = head;
    head = head->next;

    head->prev = NULL;
    temp->next = NULL;

    delete temp;
    return head;
}

Node *deleteTail(Node *head)
{
    // check for empty condition
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *newTail = tail->prev;

    newTail->next = nullptr;
    tail->prev = nullptr;

    delete tail;
    return head;
}

Node *removeKthElement(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *kNode = head;
    int count = 0;
    while (kNode != NULL)
    {
        count++;
        if (count == k)
        {
            break;
        }
        kNode = kNode->next;
    }
    Node *front = kNode->next;
    Node *back = kNode->prev;

    if (back == NULL && front == NULL)
    {
        delete kNode;
        return NULL;
    }
    else if (back == NULL)
    {
        return deleteHead(head);
    }
    else if (front == NULL)
    {
        return deleteTail(head);
    }
    back->next = front;
    front->prev = back;

    kNode->next = NULL;
    kNode->prev = NULL;

    delete kNode;
    return head;
}

void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL";
}

void deleteNode(Node *temp)
{
    Node *prev = temp->prev;
    Node *front = temp->next;

    if (front == NULL)
    {
        prev->next = NULL;
        temp->prev = NULL;
        free(temp);
        return;
    }
    prev->next = front;
    front->prev = prev;

    temp->next = temp->prev = NULL;
    free(temp);
}

Node *insertBeforHead(Node *head, int val)
{
    Node *newHead = new Node(val, head, nullptr);
    head->prev = newHead;

    return newHead;
}

Node *insertBeforTail(Node *head, int val)
{

    if (head == NULL)
    {
        return new Node(val, nullptr, nullptr);
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // Now temp will be pointing towards the last Node
    Node *back = temp->prev;
    Node *newNode = new Node(val, temp, back);

    back->next = temp->prev = newNode;

    return head;
}

Node *reverseDoubleLL(Node *head)
{
    // For one single element present
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    while (curr->next != NULL)
    {
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;

        // traverse to the next element
        curr = curr->prev;
    }

    // Node *newHead = prev->prev;
    return prev->prev;
}
int main()
{
    vector<int> arr = {12, 5, 8, 7};
    Node *head = convertArrDll(arr);
    // head = deleteHead(head);
    // head = removeKthElement(head, 2);
    // head = deleteTail(head);
    // deleteNode(head->next);
    // head = insertBeforHead(head, 10);
    // head = insertBeforTail(head, 10);
    head = reverseDoubleLL(head);

    printLL(head);
    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;
//     Node *prev;

// public:
//     Node(int val, Node *next1, Node *prev1)
//     {
//         data = val;
//         next = next1;
//         prev = prev1;
//     }

// public:
//     Node(int val)
//     {
//         data = val;
//         next = nullptr;
//         prev = nullptr;
//     }
// };

// Node *convertArrDll(vector<int> &arr)
// {
//     // if (arr.empty()) return nullptr;  // Handle empty input

//     Node *head = new Node(arr[0]);
//     Node *prev = head;

//     for (int i = 1; i < arr.size(); i++)  // Start from 1 to avoid creating an extra head node
//     {
//         Node *temp = new Node(arr[i]);
//         prev->next = temp;
//         temp->prev = prev;
//         prev = temp;
//     }
//     return head;
// }

// Node *deleteHead(Node *head)
// {
//     if (head == NULL)  // Check if the list is empty
//     {
//         return NULL;
//     }

//     Node *temp = head;

//     // If there is only one node in the list
//     if (head->next == NULL)
//     {
//         delete temp;
//         return NULL;
//     }

//     // Update head and fix the pointers
//     head = head->next;
//     head->prev = NULL;
//     delete temp;

//     return head;
// }

// void printLL(Node *head)
// {
//     if (head == NULL)
//     {
//         cout << "List is empty" << endl;
//         return;
//     }

//     while (head != NULL)
//     {
//         cout << head->data << "->";
//         head = head->next;
//     }
//     cout << " NULL" << endl;
// }

// int main()
// {
//     vector<int> arr = {12, 5, 8, 7};
//     Node *head = convertArrDll(arr);

//     cout << "Original List: ";
//     printLL(head);

//     head = deleteHead(head);

//     cout << "After deleting the head: ";
//     printLL(head);

//     return 0;
// }
