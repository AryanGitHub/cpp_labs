/*
 * Tags: mutable, const , class
 * Testing (optional) : learning mutable keywork uses.
 * Additional Info (optional) :
 */

#include <iostream>
using namespace std;

class Obj
{
  private:
    string data;

  public:
    mutable int debugInt = 0; // it can be changed even if obj is const!!

    Obj(string d)
    {
        data = d;
    }
    string getData() const
    {
        debugInt++; // we can do this!
        return data;
    }
};
int main()
{
    Obj o = Obj("Hello");
    cout << o.getData() << endl;
    cout << o.debugInt << endl;

    const Obj o2 = Obj("Hello2");
    cout << o2.getData() << endl;
    cout << o2.debugInt << endl;
    return 0;
}
