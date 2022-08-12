#include <iostream>
#include <vector>
#include <ctime>

int partition(std::vector<int> &nums, int low, int high)
{
    int standard = nums[high];
    int index = low;
    for (int i = low; i < high; ++i)
    {
        if (nums[i] <= standard)
        {
            std::swap(nums[index], nums[i]);
            ++index;
        }
    }
    std::swap(nums[index], nums[high]);
    return index;
}

int randomPartition(std::vector<int> &nums, int low, int high)
{
    // 随机挑选基准元素并将其放置于末尾
    int i = rand() % (high - low + 1) + low;
    std::swap(nums[i], nums[high]);
    return partition(nums, low, high);
}

int quickSelect(std::vector<int> &nums, int low, int high, int index)
{
    int r = randomPartition(nums, low, high);
    if (r == index)
    {
        return nums[r];
    }
    else
    {
        return r < index ? quickSelect(nums, r + 1, high, index) : quickSelect(nums, low, r - 1, index);
    }
}

int findKthLargest(std::vector<int> &nums, int k)
{
    int n = static_cast<int>(nums.size());
    if (n == 0)
    {
        return INT_MIN;
    }
    if (k > n)
    {
        k = n;
    }
    else if (k <= 0)
    {
        k = 1;
    }

    srand(time(0));
    return quickSelect(nums, 0, n - 1, n - k);
}

int main()
{
    std::vector<int> v = { 6, 1, 4, 7, 8, 2, 5, 3 };

    /**
     * => 8
     * => 8
     * => 7
     * => 6
     * => 5
     * => 4
     * => 3
     * => 2
     * => 1
     * => 1
     */
    for (int i = 0; i < 10; i++)
    {
        std::cout << findKthLargest(v, i) << std::endl;
    }

    return 0;
}
