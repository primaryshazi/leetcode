#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> result;

void permuteUniqueCore(const std::vector<int> &nums, size_t index, size_t length, std::vector<int> &perm, std::vector<bool> &visitor)
{
    if (index == length)
    {
        result.emplace_back(perm);
        return;
    }

    for (size_t i = 0; i < length; ++i)
    {
        /**
         * 已经访问过的不再使用
         * 连续相同字符，前者未使用则后者亦不使用，保证顺序
         */
        if (visitor[i] || (i > 0 && nums[i] == nums[i - 1] && !visitor[i - 1]))
        {
            continue;
        }

        perm.emplace_back(nums[i]);
        visitor[i] = true;
        permuteUniqueCore(nums, index + 1, length, perm, visitor);
        visitor[i] = false;
        perm.pop_back();
    }
}

std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums)
{
    if (nums.empty())
    {
        return {};
    }
    result.clear();
    std::sort(nums.begin(), nums.end());

    size_t length = nums.size();
    std::vector<bool> visitor(length, false);
    std::vector<int> perm;

    permuteUniqueCore(nums, 0, length, perm, visitor);
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
    std::vector<int> nums = { 1, 3, 2, 3 };

    /**
     * => { { 1, 2, 3, 3 }, { 1, 3, 2, 3 }, { 1, 3, 3, 2 }, { 2, 1, 3, 3 }, { 2, 3, 1, 3 }, { 2, 3, 3, 1 },
     *      { 3, 1, 2, 3 }, { 3, 1, 3, 2 }, { 3, 2, 1, 3 }, { 3, 2, 3, 1 }, { 3, 3, 1, 2 }, { 3, 3, 2, 1 } }
     */
    std::cout << permuteUnique(nums) << std::endl;

    return 0;
}
