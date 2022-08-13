#include <iostream>
#include <vector>

bool canJump(const std::vector<int> &nums)
{
    int length = static_cast<int>(nums.size());
    if (length == 0)
    {
        return false;
    }
    if (length == 1)
    {
        return true;
    }

    int last = length - 1;      // 记录上一个可到达的位置
    bool isCan = false;
    for (int i = length - 2; i >= 0; --i)
    {
        isCan = false;
        if (nums[i] == 0)
        {
            continue;
        }
        if (nums[i] + i >= last)
        {
            last = i;
            isCan = true;
        }
    }

    return isCan;
}

int main()
{
    /**
     * => 0
     * => 1
     * => 0
     */
    std::cout << canJump({ 0, 2, 3 }) << std::endl;
    std::cout << canJump({ 2, 3, 0, 0, 4 }) << std::endl;
    std::cout << canJump({ 1, 2, 1, 0, 1 }) << std::endl;

    return 0;
}
