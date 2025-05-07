#include <iostream>
using namespace std;

class stackImplementation
{
public:
    int topIndex = -1;
    int st[10];

    void push(int val)
    {
        if (topIndex >= 10)
        {
            cout << "Stack is full.\n";
            return;
        }
        topIndex = topIndex + 1;
        st[topIndex] = val;
    }

    int top()
    {
        if (topIndex == -1)
        {
            cout << "Stack is Empty.\n";
            return -1;
        }
        return st[topIndex];
    }

    void pop()
    {
        // check for empty condition
        if (topIndex == -1)
        {
            cout << "Stack is Empty.\n";
            return;
        }
        topIndex = topIndex - 1;
    }

    int size()
    {
        return topIndex + 1;
    }

    void print()
    {
        int tempTop = topIndex;
        while (tempTop != -1)
        {
            cout << st[tempTop] << "\n";
            tempTop = tempTop - 1;
        }
    }
};

int main()
{
    stackImplementation st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    st.print();
}
