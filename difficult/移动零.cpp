#include <iostream>
#include <vector>

void moveZeroes(std::vector<int> &nums)
{
    int slow = 0;   // 指向当前不为零元素的位置
    int fast = 0;   // 指向当前比较的元素的位置
    int length = static_cast<int>(nums.size());

    while (fast < length)
    {
        if (nums[fast] != 0)
        {
            std::swap(nums[slow], nums[fast]);
            ++slow;
        }
        ++fast;
    }
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
    std::vector<int> vi = { 0, 1, 0, 0, 2, 3, 0, 4, 5, 0 };

    moveZeroes(vi);

    /**
     * => { 1, 2, 3, 4, 5, 0, 0, 0, 0, 0 }
     */
    std::cout << vi << std::endl;

    return 0;
}
