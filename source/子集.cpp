#include <iostream>
#include <algorithm>
#include <vector>

void subsetsCore(const std::vector<int> &nums, int length, int index, std::vector<std::vector<int>> &result, std::vector<int> &ns)
{
    if (index >= length)
    {
        return;
    }

    for (int i = index; i < length; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        ns.emplace_back(nums[i]);
        result.emplace_back(ns);
        subsetsCore(nums, length, i + 1, result, ns);
        ns.pop_back();
    }
}

std::vector<std::vector<int>> subsets(std::vector<int> &nums)
{
    int length = static_cast<int>(nums.size());
    std::vector<int> ns;
    std::vector<std::vector<int>> result = { {} };

    std::sort(nums.begin(), nums.end());
    subsetsCore(nums, length, 0, result, ns);

    return result;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    os << "{ ";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if (it != v.begin())
        {
            os << ", ";
        }
        os << *it;
    }
    os << " }";

    return os;
}

int main()
{
    std::vector<int> nums = { 1, 2, 3, 2 };

    /**
     * => { {  }, { 1 }, { 1, 2 }, { 1, 2, 3 }, { 1, 3 }, { 2 }, { 2, 3 }, { 3 } }
     */
    std::cout << subsets(nums) << std::endl;

    return 0;
}
