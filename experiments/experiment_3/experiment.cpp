/*
 * Tags: const , pointer, type casting
 * Testing (optional) : writing data to const using pointer
 * Additional Info : to stop compiler error, using type casting
 */

#include <iostream>
using namespace std;

int main()
{
    const int a = 10;
    int *ptr = (int *)&a; // to silent the compiler from error
    *ptr = 12;            // value cheanged
    cout << *ptr << endl;
    return 0;
}
