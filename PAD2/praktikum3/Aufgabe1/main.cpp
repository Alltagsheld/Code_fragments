#include <iostream>
#include <queue>
#include <stack>
#include <list>

using namespace std;
class myStack
{
public:
    myStack()
    {

    };
    int size() // O(1)
    {
        return stack.size();
    };
    bool empty() // O(1)
    {
        return stack.empty();
    };
    void push(int a) // O(1)
    {
        stack.push_front(a);
    };
    void pop() // O(1)
    {
        stack.pop_front();
    };
    int top() // O(1)
    {
        return stack.front();
    };
private:
    list <int> stack;
};

class myQueue
{
public:
    myQueue()
    {

    };
    bool empty() // O(1)
    {
        return stackOne.empty();
    };
    int size() // O(1)
    {
        return stackOne.size();
    };
    void enqueue(int a) // O(n)
    {
        while(!stackOne.empty())
        {
            int b = stackOne.top();
            stackTwo.push(b);
            stackOne.pop();
        }
        stackOne.push(a);

        while(!stackTwo.empty())
        {
            int b = stackTwo.top();
            stackOne.push(b);
            stackTwo.pop();
        }
    };
    void dequeue() // O(1)
    {
        stackOne.pop();
    };
    int front () // O(1)
    {
        return stackOne.top();
    };
private:
    myStack stackOne;
    myStack stackTwo;
};

void testMyQueue()
{
    myQueue a;

    for(int i=0; i<10; i++)
    {
        a.enqueue(i);
        cout <<"enqueueing "<<i<<endl;
    }

    for(int i=a.size(); i>5; i--)
    {
        cout <<"size of queue = "<<a.size()<<endl;
        cout <<"dequeueing "<< a.front() <<endl;
        a.dequeue();
    }

    for(int i=0; i<10; i++)
    {
        a.enqueue(i);
        cout <<"enqueueing "<<i<<endl;
    }
    for(int i=a.size(); i>0; i--)
    {
        cout <<"size of queue = "<<a.size()<<endl;
        cout <<"dequeueing "<< a.front() <<endl;
        a.dequeue();
    }

    if (a.empty())
    {
        cout << "queue is now empty "<< endl;
    }
    else
    {
        cout << "queue is not empty, it has the size "<<a.size() << endl;
        cout <<"top element of queue "<< a.front()<<endl;
    }
}

void testMyStack()
{
    myStack a;
    try
    {
        for(int i=0; i<10; i++)
        {
            a.push(i);
            cout <<"pushing "<<i<<endl;
        }
    } catch (...)
    {
        cout <<"an error occured during pushing" << endl;
    }


    try
    {
        for(int i=a.size(); i>0; i--)
        {
            cout <<"size of stack = "<<a.size()<<endl;
            cout <<"popping "<< a.top() <<endl;
            a.pop();
        }
    } catch (...)
    {
        cout <<"an error occured during popping" << endl;
    }

}

int main()
{
    cout <<"initialize test stack\n" << endl;
    testMyStack();
    cout <<"\nfinished test\nNo errors occured. Press a button to start testing the queue" <<endl;
    system("PAUSE");
    system("cls");
    cout <<"initialize test queue\n" <<endl;
    testMyQueue();
    cout <<"finished test." <<endl;
}
