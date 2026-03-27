#include <vector>
#include <map>
#include <iostream>

std::vector<int> two_sum(std::vector<int> &vec, int target);
void compareAndPrint(int idx, std::vector<int> &a, const std::vector<int> &b);

int main(void)
{
    int target;
    std::vector<int> nums;
    std::vector<int> expected;

    nums = {2, 7, 11, 15};
    target = 9;
    expected = {0, 1};
    compareAndPrint(1, expected, two_sum(nums, target));

    nums = {3, 2, 4};
    target = 6;
    expected = {1, 2};
    compareAndPrint(2, expected, two_sum(nums, target));
    
    nums = {3, 3};
    target = 6;
    expected = {0, 1};

    nums = {-1, -2, -3, -4, -5};
    target = -8;
    expected = {2, 4};
    compareAndPrint(3, expected, two_sum(nums, target));

    nums = {0, 4, 3, 0};
    target = 0;
    expected = {0, 3};
    compareAndPrint(4, expected, two_sum(nums, target));
    
    return 0;
}

std::vector<int> two_sum(std::vector<int> &vec, int target)
{
    std::map<int, int> hasher = {};
    int idx = 0;
    for (const auto &i : vec)
    {
        auto it = hasher.find(i);
        if (it != hasher.end())
        {
            return {it->second, idx};
        }
        hasher[target - i] = idx;
        ++idx;
    }

    return {};
}

void compareAndPrint(int idx, std::vector<int> &a, const std::vector<int> &b)
{
    std::cout << idx << ": " << (a == b ? "Correto" : "Incorreto") << std::endl;
}