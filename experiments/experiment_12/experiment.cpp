/*
 * Tags:
 * Testing (optional) :
 *
 */

#include <iostream>

using namespace std;
class obj
{
  public:
    int data;
    obj(int d) : data(d)
    {
        std::cout << "Constructor made for obj" << endl;
    }
    obj(const obj &other)
    {
        std::cout << "obj(const obj&) called, no changes made" << endl;
    }
    obj &operator=(const obj &other)
    {
        std::cout << "obj& operator=(const obj&) called, no changes made" << endl;
        return *this;
    }
    ~obj()
    {
        std::cout << "Destructor made for obj. data = " << data << endl;
    }
};

int main()
{
    obj o1(25);
    // o1 = obj(10);
    obj o2 = o1;
    return 0;
}
