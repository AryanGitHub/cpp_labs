/*
 * Tags: const
 * Testing (optional) : understand const 
 *
 */

#include <iostream>
using namespace std;

int main() {
    const int a = 10;
    a =5;  // error!
    cout << a << endl; 
    return 0;
}
