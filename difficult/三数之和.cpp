#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    int length = static_cast<int>(nums.size());
    std::vector<std::vector<int>> vResult;

    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < length - 2; ++i)
    {
        // 相同之数直接跳过
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int k = length - 1;
        for (int j = i + 1; j < length - 1; ++j)
        {
            // 相同之数直接跳过
            if (j > i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }

            // 当三数之和大于0时则可以递减
            while (j < k && nums[i] + nums[j] + nums[k] > 0)
            {
                --k;
            }

            if (j == k)
            {
                break;
            }

            if (nums[i] + nums[j] + nums[k] == 0)
            {
                vResult.emplace_back(std::vector<int>{ nums[i], nums[j], nums[k] });
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
    std::vector<int> vec1 = { -3, -2, -1, 0, 1, 2, 3 };
    std::vector<int> vec2 = { -3, -3, -2, -2, -1, -1 , 0, 0, 1, 1, 2, 2 ,3, 3 };
    std::vector<int> vec3 = { -1, 0, 1, -2, -3, 4, 5 };

    /**
     * => { { -3, 0, 3 }, { -3, 1, 2 }, { -2, -1, 3 }, { -2, 0, 2 }, { -1, 0, 1 } }
     * => { { -3, 0, 3 }, { -3, 1, 2 }, { -2, -1, 3 }, { -2, 0, 2 }, { -2, 1, 1 }, { -1, -1, 2 }, { -1, 0, 1 } }
     * => { { -3, -2, 5 }, { -3, -1, 4 }, { -1, 0, 1 } }
     */
    std::cout << threeSum(vec1) << std::endl;
    std::cout << threeSum(vec2) << std::endl;
    std::cout << threeSum(vec3) << std::endl;

    return 0;
}
