/*
 * Tags: const , pointer
 * Testing (optional) : writing data to const using pointer
 * Additional Info : use g++ -fpermissive experiment.cpp
 */

#include <iostream>
using namespace std;

int main()
{
    const int a = 10;
    int *ptr = &a; // using -fpermissive flag, otherwise do not compile
    *ptr = 12;     // value cheanged
    cout << *ptr << endl;
    return 0;
}
