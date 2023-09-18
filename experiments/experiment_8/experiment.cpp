/*
 * Tags: this, struct
 * Testing (optional) : using this inside a struct function, to see, can it take its own data members.
 *
 */

#include <iostream>
using namespace std;

struct test
{
    int data;
    void hello()
    {
        cout << "hello " << this->data << endl;
    }
};

int main()
{
    struct test t;
    t.hello();
    return 0;
}
