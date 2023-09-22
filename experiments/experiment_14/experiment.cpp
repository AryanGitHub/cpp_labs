/*
 * Tags: constexpr
 * Testing (optional) : seeing how constexpr working on debugger.
 * it has already computed the expression result at compile-time, but it reserves the memory location and initilises it
 * with that result at runtime only
 */

#include <iostream>
using namespace std;
constexpr int myadd(const int &a, const int &b)
{
    return a + b;
}

int main()
{
    constexpr int a1 = 4 + 7;
    constexpr int b = 5;
    int c = 4;
    constexpr int a = myadd(a1, b); // if u try to step-into this, using debugger, it do not goto the program inside.
    std::cout << a << std::endl;
    return 0;
}
