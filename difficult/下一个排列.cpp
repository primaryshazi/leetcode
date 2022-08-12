#include <iostream>
#include <algorithm>
#include <vector>

void nextPermutation(std::vector<int> &nums)
{
    int left = static_cast<int>(nums.size()) - 2;

    // 从后向前找到第一个递减的数字
    while (left >= 0 && nums[left] >= nums[left + 1])
    {
        --left;
    }

    if (left >= 0)
    {
        int right = static_cast<int>(nums.size()) - 1;

        // 从后向前找到第一个比递减数字大的数字
        while (right >= 0 && nums[left] >= nums[right])
        {
            --right;
        }
        // 交互需要替换的两数
        std::swap(nums[left], nums[right]);
    }

    // left右边的序列由降序调整为升序
    std::reverse(nums.begin() + left + 1, nums.end());
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
    std::vector<int> v1 = { 1, 2, 3, 4, 5 };
    std::vector<int> v2 = { 5, 4, 3, 2, 1 };
    std::vector<int> v3 = { 1, 3, 5, 4, 2 };

    /**
     * => { 1, 2, 3, 5, 4 }
     * => { 1, 2, 3, 4, 5 }
     * => { 1, 4, 2, 3, 5 }
     */
    nextPermutation(v1);
    std::cout << v1 << std::endl;
    nextPermutation(v2);
    std::cout << v2 << std::endl;
    nextPermutation(v3);
    std::cout << v3 << std::endl;

    return 0;
}
