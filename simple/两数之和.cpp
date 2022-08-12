#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    std::unordered_map<int, int> mapValueToIndex; // 记录值和索引
    size_t size = nums.size();

    for (int i = 0; i < size; i++)
    {
        // 查询是否存在于当前值相加等于target的数
        auto it = mapValueToIndex.find(target - nums[i]);

        // 查到则直接返回，否则将当前值及索引存入map
        if (it != mapValueToIndex.end())
        {
            return {it->second, i};
        }
        mapValueToIndex.insert(std::make_pair(nums[i], i));
    }

    return {};
}

int main()
{
    const int target = 9;
    std::vector<int> v1 = {1, 3, 5, 7, 9};
    std::vector<int> v2 = {2, 4, 5, 6, 8};
    std::vector<int> v3 = {2, 7, 4, 5, 3, 6};

    auto vr1 = twoSum(v1, target);
    auto vr2 = twoSum(v2, target);
    auto vr3 = twoSum(v3, target);

    auto func = [](const std::vector<int> &vi)
    {
        std::cout << vi.size() << " ";
        std::for_each(vi.begin(), vi.end(), [](auto &element)
                      { std::cout << element << " "; });
        std::cout << std::endl;
    };

    /**
     * => 0
     * => 2 1 2
     * => 2 0 1
     */
    func(vr1);
    func(vr2);
    func(vr3);

    return 0;
}
