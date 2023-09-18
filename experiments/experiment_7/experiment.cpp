/*
 * Tags: implementing stack and queue using a linkedList
 * Testing (optional) :
 *
 */

#include <cassert>
#include <climits>
#include <iostream>
using namespace std;

class Node
{
  public:
    Node *next;
    int data;

    Node()
    {
        next = nullptr;
        data = 0;
    }
    Node(int a)
    {
        next = nullptr;
        data = a;
    }
    Node(int a, Node *next)
    {
        this->next = next;
        data = a;
    }

    static Node *insertAtHead(int data, Node **head)
    {
        Node *newNode = new Node(data, *head);
        *head = newNode;
        return newNode;
    }

    static Node *insertAtLast(int data, Node **lastNode)
    {
        if (*lastNode)
        {
            (*lastNode)->next = new Node(data);
            *lastNode = (*lastNode)->next;
            return *lastNode;
        }
        else
        {
            *lastNode = Node::insertAtHead(data, lastNode);
            return *lastNode;
        }
    }

    static Node *removeAtHead(Node **node)
    {
        if (node)
        {
            Node *toBeDeleted = *node;
            *node = (*node)->next;
            delete toBeDeleted;
            return *node;
        }
        else
            return nullptr;
    }
};

class stack
{
  public:
    Node *head;

    stack()
    {
        head = nullptr;
    }

    void push(int data)
    {
        head = Node::insertAtHead(data, &head);
    }

    int pop()
    {
        if (!head)
        {
            cout << "stack is empty\n";
            return INT_MIN;
        }
        int ret = head->data;
        head = Node::removeAtHead(&head);
        return ret;
    }
    int top()
    {
        if (!head)
        {
            cout << "stack is empty\n";
            return INT_MIN;
        }
        return head->data;
    }
};

void testingStack()
{
    stack myStack;

    // Test case 1: Push one element and check the top
    myStack.push(42);
    assert(myStack.top() == 42);

    // Test case 2: Push multiple elements and pop them
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    assert(myStack.pop() == 30);
    assert(myStack.pop() == 20);
    assert(myStack.pop() == 10);

    // Test case 3: Push and pop elements to make the stack empty
    myStack.pop();
    myStack.push(5);
    myStack.pop();
    assert(myStack.pop() == INT_MIN);

    // Test case 4: Attempt to pop from an empty stack
    assert(myStack.pop() == INT_MIN);

    // Test case 5: Attempt to get the top of an empty stack
    assert(myStack.top() == INT_MIN);

    // Test case 6: Push and pop elements alternately
    myStack.push(1);
    assert(myStack.pop() == 1);
    myStack.push(2);
    assert(myStack.pop() == 2);
    myStack.push(3);
    assert(myStack.pop() == 3);

    // Test case 7: Push and pop the same element multiple times
    myStack.push(7);
    myStack.pop();
    myStack.push(7);
    myStack.pop();
    myStack.push(7);
    assert(myStack.pop() == 7);
}

class Queue
{
  public:
    Node *head;
    Node *tail;

    Queue()
    {
        head = nullptr;
        tail = nullptr;
    }
    void push(int data)
    {
        tail = Node::insertAtLast(data, &tail);
        if (head == nullptr)
            head = tail;
    }

    int pop()
    {
        if (!head)
        {
            cout << "queue is empty\n";
            return INT_MIN;
        }
        int ret = head->data;
        head = Node::removeAtHead(&head);
        if (head == nullptr)
            tail = nullptr;
        return ret;
    }
    int front()
    {
        if (!head)
        {
            cout << "queue is empty\n";
            return INT_MIN;
        }
        return head->data;
    }
};

void testQueue()
{
    Queue q;

    // Test 1: Pop from an empty queue should return INT_MIN
    assert(q.pop() == INT_MIN);

    // Test 2: Front of an empty queue should return INT_MIN
    assert(q.front() == INT_MIN);

    // Test 3: Push one element and check if it's at the front
    q.push(42);
    assert(q.front() == 42);

    // Test 4: Pop the element and check if the queue is empty
    q.pop();
    // assert(q.isEmpty());

    // Test 5: Push multiple elements and check front
    q.push(1);
    q.push(2);
    q.push(3);
    assert(q.front() == 1);

    // Test 6: Pop elements and check front
    q.pop();
    assert(q.front() == 2);
    q.pop();
    assert(q.front() == 3);

    std::cout << "All tests passed!" << std::endl;
}

int main()
{

    testQueue();
    return 0;
}
