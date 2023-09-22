/*
 * Tags: constexpr stl data-structure
 * Testing (optional) : my aim was to accept a vector defined in main to a consexpr function!
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr int getSmallest(const vector<int> &nums)
{
    vector<int> copy(nums);
    sort(copy.begin(), copy.end());
    int smallest = copy[0];
    return smallest;
}
constexpr int getSmallest2(vector<int> &&copy)
{
    sort(copy.begin(), copy.end());
    int smallest = copy[0];
    return smallest;
}

int main()
{
    // constexpr vector <int> nums = {3,8,5,7,3,1,9,2};
    constexpr int smallest = getSmallest2({3, 8, 5, 7, 3, 1, 9, 2});
    cout << "smallest = " << smallest << endl;
    return 0;
}
