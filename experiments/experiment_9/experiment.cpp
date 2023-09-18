/*
 * Tags: construstor initializer list
 * Testing (optional) : using constructor initaliser to make an object
 *
 */

#include <iostream>
#include <string>

using namespace std;

class A
{
    int a;
    std::string s;

  public:
    A() : a(0), s("NO_DATA")
    {
        std::cout << "init empty constructor" << std::endl;
    }

    A(int a, const std::string &s) : a(a), s(s)
    {
        std::cout << "parameterised empty constructor" << std::endl;
    }

    void print()
    {
        std::cout << "a = " << a << endl;
        std::cout << "s = " << s << endl;
    }
};

int main()
{
    A obj1 = A();
    A obj2 = A(1, "hello");

    obj1.print();
    obj2.print();

    return 0;
}
