/*
 * Tags : std::hash
 * Aim : using std::hash on user defined data-types
 * Other Tags (optional) : object , struct , equlity
 * Additional Information (optional) : a serise of experiments on std::hash
 *
 */

#include <iostream>
#include <string>

struct obj
{
  public:
    int i;
    std::string s;
};

std::ostream &operator<<(std::ostream &os, const obj &o)
{
    os << std::string("{ int i  = ") + std::to_string(o.i) + std::string(", std::string s = ") + o.s + std::string("}");
    return os;
}

template <> struct std::hash<obj>
{
    std::size_t operator()(const obj &o)
    {
        return std::hash<int>()(o.i) ^ std::hash<std::string>()(o.s);
    }
};

int main()
{
    obj data1 = {314, "Hello, World!"};
    obj data2 = data1;
    obj data3 = {300, "Hello, C++!"};
    std::size_t hash1 = std::hash<obj>()(data1);

    std::hash<obj> hashMakerStruct;
    // its a struct of type std::hash<obj> whose "()" operator is overloaded to return a hash

    std::size_t hash2 = hashMakerStruct(data2);
    std::size_t hash3 = hashMakerStruct(data3);
    std::cout << "Data 1 = " << data1 << ", Hash = " << hash1 << std::endl;
    std::cout << "Data 2 = " << data2 << ", Hash = " << hash2 << std::endl;
    std::cout << "Data 3 = " << data3 << ", Hash = " << hash3 << std::endl;
    std::cout << "Data1 == Data2 ?? "
              << " Boolean value = " << (hash1 == hash2) << std::endl;
    std::cout << "Data1 == Data3 ?? "
              << " Boolean value = " << (hash1 == hash3) << std::endl;

    return 0;
}
