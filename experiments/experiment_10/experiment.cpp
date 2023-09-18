/*
 * Tags: construstor initializer list, changing order of initilisation of the member
 * Testing (optional) : using constructor initaliser and chainging order of initilization
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
    A() : s("NO_DATA"), a(0) // will get a warning! with Wall flag
    {
        std::cout << "init empty constructor" << std::endl;
    }

    A(int a, const std::string &s) : s(s), a(a) // will get a warning! with Wall flag
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
