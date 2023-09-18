/*
 * Tags: construstor initializer list, to initilize objects!
 * Testing (optional) : comparing normal constructor initilsation and constructor initaliser list for objects
 *
 */

#include <iostream>
#include <string>

using namespace std;

class A
{
  public:
    int value;
    A() : value(0)
    {
        std::cout << "default constructor of A" << std::endl;
    }
    A(int value) : value(value)
    {
        std::cout << "paramiterised constructor of A" << std::endl;
    }
};
class B
{
    int data;
    A obj;

  public:
    B(int data, int value) : data(data), obj(value) // it can also be obj(A(value))
    {
        std::cout << "constructor 1 of B" << std::endl;
    }

    B(int data, int value, bool val)
    {
        this->data = data;
        obj = A(value);
        std::cout << "constructor 2 of B" << std::endl;
    }
};

int main()
{
    B obj1 = B(1, 2);
    std::cout << "------------------" << std::endl;
    B obj2 = B(1, 2, true); // it runs constructor of A twice!

    return 0;
}
