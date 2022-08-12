#include <iostream>
#include <vector>

std::vector<std::vector<int>> insert(std::vector<std::vector<int>> &intervals, std::vector<int> &newInterval)
{
    if (intervals.empty())
    {
        return { newInterval };
    }

    // 将新加入的插入到合适的位置
    auto it = intervals.begin();
    while (it != intervals.end() && newInterval[0] >= (*it)[0])
    {
        ++it;
    }
    intervals.emplace(it, newInterval);

    std::vector<std::vector<int>> result;
    int pos = 0;    // 记录当前区间
    int length = static_cast<int>(intervals.size());

    while (pos < length)
    {
        int left = intervals[pos][0];   // 区间的左值
        int right = intervals[pos][1];  // 区间的右值
        int next = pos + 1;             // 记录带合并区间

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
    std::vector<std::vector<int>> intervals = { { 1, 2}, { 3, 5 }, { 6, 7 }, { 8, 10 }, { 12, 16 } };
    std::vector<int> newVal = { 4, 8 };

    /**
     * => { { 1, 2 }, { 3, 10 }, { 12, 16 } }
     */
    std::cout << insert(intervals, newVal) << std::endl;

    return 0;
}
