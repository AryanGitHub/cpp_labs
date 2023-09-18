/*
 * Tags: const , pointer const pointer
 * Testing (optional) : trying tp writing to const int using const pointer
 * Additional Info (optional) :
 */

#include <iostream>
using namespace std;

int main()
{
    const int a = 10;
    const int *ptr = &a; // no issue here, in changing type from int pointer to const int pointer
    *ptr = 12;           // error: assignment of read-only location ‘* ptr’
    cout << *ptr << endl;
    return 0;
}
