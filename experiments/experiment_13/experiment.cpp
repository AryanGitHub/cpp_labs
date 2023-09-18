/*
 * Tags: ostream, operator << overloading
 * Testing (optional) : ostream operator << overloading for user defiend classes
 *
 */

#include <iostream>
using namespace std;
class obj
{
  public:
    int data;
    obj(int i) : data(i)
    {
    }

    friend std::ostream &operator<<(std::ostream &stream, obj &o);
};

std::ostream &operator<<(std::ostream &stream, obj &o)
{
    stream << o.data;
    return stream;
}

int main()
{
    obj a = 10;
    std::cout << a << endl;
    return 0;
}
