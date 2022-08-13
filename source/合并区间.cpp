#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
{
    int length = static_cast<int>(intervals.size());
    if (length < 2)
    {
        return intervals;
    }

    std::sort(intervals.begin(), intervals.end());

    std::vector<std::vector<int>> result;
    int pos = 0;    // 记录当前区间

    while (pos < length)
    {
        int left = intervals[pos][0];   // 区间的左值
        int right = intervals[pos][1];  // 区间的右值
        int next = pos + 1;             // 记录待合并区间

        // 若下一个区间的左值不大于当前区间的右值，则两个区间可以合并
        while (next < length && intervals[next][0] <= right)
        {
            right = std::max(right, intervals[next][1]);
            ++next;
        }
        pos = next;
        result.emplace_back(std::vector<int>{ left, right });
    }

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
    std::vector<std::vector<int>> intervals = {
        {2, 3},
        {2, 2},
        {3, 3},
        {1, 3},
        {5, 7},
        {2, 2},
        {4, 6}
    };

    /**
     * => { { 1, 3 }, { 4, 7 } }
     */
    std::cout << merge(intervals) << std::endl;

    return 0;
}
