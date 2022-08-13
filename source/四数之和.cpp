#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
{
    int length = static_cast<int>(nums.size());
    std::vector<std::vector<int>> vResult;

    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < length - 3; ++i)
    {
        // 跳过重复值
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        // 此轮最小值大于目标值则直接结束
        if (static_cast<int64_t>(nums[i]) + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
        {
            break;
        }

        // 此轮最大值小于目标值则直接跳过
        if (static_cast<int64_t>(nums[i]) + nums[length - 3] + nums[length - 2] + nums[length - 1] < target)
        {
            continue;
        }

        for (int j = i + 1; j < length - 2; ++j)
        {
            // 跳过重复值
            if (j > i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }

            // 此轮最小值大于目标值则直接结束
            if (static_cast<int64_t>(nums[i]) + nums[j] + nums[j + 1] + nums[j + 2] > target)
            {
                break;
            }

            // 此轮最大值小于目标值则直接跳过
            if (static_cast<int64_t>(nums[i]) + nums[j] + nums[length - 2] + nums[length - 1] < target)
            {
                continue;
            }

            int left = j + 1;
            int right = length - 1;
            while (left < right)
            {
                int64_t sum = static_cast<int64_t>(nums[i]) + nums[j] + nums[left] + nums[right];

                /**
                 * 相等则记录
                 * 小于则移动左指针
                 * 大于则移动右指针
                 */
                if (sum > target)
                {
                    --right;
                }
                else if (sum < target)
                {
                    ++left;
                }
                else
                {
                    vResult.emplace_back(std::vector<int>{ nums[i], nums[j], nums[left], nums[right] });

                    // 找到下一个不与当前值相同的左值
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        ++left;
                    }
                    ++left;

                    // 找到下一个不与当前值相同的左值
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        --right;
                    }
                    --right;
                }
            }
        }
    }

    return vResult;
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
    std::vector<int> v1 = { -5, -4, -4, 0, 2, 2, 3, 3 };
    std::vector<int> v2 = { -5, -3, -1, 0, 2, 4 };
    std::vector<int> v3 = { -4, -2, 0, 1, 3, 5 };

    /**
     * => { { -5, 0, 2, 3 }, { -4, 0, 2, 2 } }
     * => { { -5, -1, 2, 4 }, { -3, -1, 0, 4 } }
     * => { { -4, -2, 1, 5 }, { -4, 0, 1, 3 } }
     */
    std::cout << fourSum(v1, 0) << std::endl;
    std::cout << fourSum(v2, 0) << std::endl;
    std::cout << fourSum(v3, 0) << std::endl;

    return 0;
}
