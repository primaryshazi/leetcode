#include <iostream>
#include <vector>
#include <queue>

#define SOLUTION_ONE

#ifdef SOLUTION_ONE

std::vector<int> maxSlidingWindow(const std::vector<int> &nums, int k)
{
    if (k == 0 || nums.empty())
    {
        return {};
    }

    std::priority_queue<std::pair<int, int>> windows;   // 记录每个数的数值及其在数组中的位置

    // 储存第一个窗口的最大值
    for (int i = 0; i < k; i++)
    {
        windows.emplace(std::make_pair(nums[i], i));
    }

    std::vector<int> result = { windows.top().first };
    int length = static_cast<int>(nums.size());
    for (int i = k; i < length; i++)
    {
        windows.emplace(std::make_pair(nums[i], i));
        // 若当前的最大值在窗口的左边则将其移除队列
        while (windows.top().second <= i - k)
        {
            windows.pop();
        }
        result.emplace_back(windows.top().first);
    }

    return result;
}

#else

std::vector<int> maxSlidingWindow(const std::vector<int> &nums, int k)
{
    if (k == 0 || nums.empty())
    {
        return {};
    }

    std::deque<int> windows;   // 记录位置值，位置对应的数值均单调递减，从而保证队首元素为最大值

    for (int i = 0; i < k; i++)
    {
        // 若新元素大于队尾元素则将队尾元素移除，将新元素插入，保证数值单调递减
        while (!windows.empty() && nums[i] >= nums[windows.back()])
        {
            windows.pop_back();
        }

        windows.emplace_back(i);
    }

    std::vector<int> result = { nums[windows.front()] };
    int length = static_cast<int>(nums.size());
    for (int i = k; i < length; i++)
    {
        while (!windows.empty() && nums[i] >= nums[windows.back()])
        {
            windows.pop_back();
        }
        windows.emplace_back(i);

        // 当前最大值在窗口左边则移除
        while (windows.front() <= i - k)
        {
            windows.pop_front();
        }
        // 此时队首则是窗口中最大的值
        result.emplace_back(nums[windows.front()]);
    }

    return result;
}

#endif

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
    std::vector<int> nums = { 1, -2, 3, -4, 5, -6, 3, 2, 1 };

    /**
     * => { 1, -2, 3, -4, 5, -6, 3, 2, 1 }
     * => { 1, 3, 3, 5, 5, 3, 3, 2 }
     * => { 3, 3, 5, 5, 5, 3, 3 }
     */
    std::cout << maxSlidingWindow(nums, 1) << std::endl;
    std::cout << maxSlidingWindow(nums, 2) << std::endl;
    std::cout << maxSlidingWindow(nums, 3) << std::endl;

    return 0;
}
