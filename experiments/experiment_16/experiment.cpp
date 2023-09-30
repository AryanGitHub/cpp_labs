/*
 * Tags : std::hash
 * Aim : using std::hash on predefined data-types
 * Other Tags (optional) : int, std::string
 * Additional Information (optional) : a serise of experiments on std::hash
 *
 */

#include <iostream>
using namespace std;

int main()
{
    int data1 = 314;
    std::string data2 = "Hello, World!";
    bool data3 = true;
    std::size_t hash1 = std::hash<int>()(314);
    std::size_t hash2 = std::hash<std::string>()("Hello,World!");
    std::size_t hash3 = std::hash<bool>()(data3);
    cout << "Data 1 = " << data1 << ", Hash = " << hash1 << endl;
    cout << "Data 2 = " << data2 << ", Hash = " << hash2 << endl;
    cout << "Data 3 = " << data3 << ", Hash = " << hash3 << endl;

    return 0;
}
