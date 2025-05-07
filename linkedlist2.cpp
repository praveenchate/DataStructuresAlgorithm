#include <iostream>
#include <list>

using namespace std;

void printList(list<int> ll)
{
    list<int>::iterator itr;
    for (itr = ll.begin(); itr != ll.end(); itr++)
    {
        cout << (*itr) << "->";
    }
    cout << "NULL" << endl;
}

int main()
{
    list<int> ll;

    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(3);
    ll.push_back(4);

    auto it = ll.begin();
    advance(it, 4);
    ll.insert(it, 5);
    // Iterator for linked list - begin(), end()
    printList(ll);
    cout << ll.size() << endl;
    cout << "Head =" << ll.front() << endl;
    cout << "Tail =" << ll.back() << endl;

    return 0;
}