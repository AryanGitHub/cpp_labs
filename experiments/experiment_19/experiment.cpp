/*
 * Tags : std::hash, unordered_map
 * Aim : unordered_map on user defined data-types
 * Other Tags (optional) : object , struct , equlity , operator== , operator<<
 * Additional Information (optional) : a serise of experiments on std::hash
 *
 */

#include <iostream>
#include <string>
#include <unordered_map>

struct obj
{
  public:
    int i;
    std::string s;

    bool operator==(const obj &o) const
    {
        return this->i == o.i && this->s == o.s;
    }
};

std::ostream &operator<<(std::ostream &os, const obj &o)
{
    os << std::string("{ int i  = ") + std::to_string(o.i) + std::string(", std::string s = ") + o.s + std::string("}");
    return os;
}

template <> struct std::hash<obj>
{
    std::size_t operator()(const obj &o) const
    {
        return std::hash<int>()(o.i) ^ std::hash<std::string>()(o.s);
    }
};

int main()
{
    obj data1 = {314, "Hello, World!"};
    obj data2 = data1;
    obj data3 = {300, "Hello, C++!"};

    std::unordered_map<obj, int, std::hash<obj>> u_map;
    u_map[data1] = 1;
    u_map[data2] = 2;
    u_map[data3] = 3;

    for (auto &a : u_map)
    {
        std::cout << "key = " << a.first << " value = " << a.second << std::endl;
    }
    return 0;
}
