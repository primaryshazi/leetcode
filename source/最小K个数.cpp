#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define SOLUTION_ONE

#ifdef SOLUTION_ONE

std::vector<int> smallestK(std::vector<int> &arr, int k)
{
    if (k <= 0)
    {
        return {};
    }

    std::vector<int> result(k, 0);
    std::priority_queue<int, std::vector<int>, std::greater<int>> minQue;
    for (auto i : arr)
    {
        minQue.emplace(i);
    }

    for (int i = 0; i < k; i++)
    {
        result[i] = minQue.top();
        minQue.pop();
    }

    return result;
}

#else

int partition(std::vector<int> &arr, int low, int high)
{
    // 类似于快排，将小于基准元素的值均放置于基准元素的左边
    int index = low;
    int standard = arr[high];
    for (int i = low; i < high; i++)
    {
        if (arr[i] < standard)
        {
            std::swap(arr[index], arr[i]);
            ++index;
        }
    }
    std::swap(arr[high], arr[index]);

    return index;
}

std::vector<int> smallestK(std::vector<int> &arr, int k)
{
    if (k <= 0)
    {
        return {};
    }

    std::vector<int> result(k, 0);

    if (arr.empty())
    {
        return result;
    }

    int low = 0;
    int high = arr.size() - 1;
    int index = partition(arr, low, high);

    // 当基准元素及其左边元素数量等于k时，则找到所有元素
    while (index + 1 != k)
    {
        /**
         * 数量大于所需数量时，将右边界减一
         * 数量不大于所需数量时，将左边界加一
         */
        if (index + 1 > k)
        {
            high = index - 1;
            index = partition(arr, low, high);
        }
        else
        {
            low = index + 1;
            index = partition(arr, low, high);
        }
    }

    for (int i = 0; i < k; i++)
    {
        result[i] = arr[i];
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
    std::vector<int> arr = { 7, 5, 3, 9, 1, 8, 2, 6, 4 };

    /**
     * => {  }
     * => { 1 }
     * => { 1, 2 }
     * => { 1, 2, 3 }
     * => { 1, 2, 3, 4 }
     * => { 1, 2, 3, 4, 5 }
     * => { 1, 2, 3, 4, 5, 6 }
     * => { 1, 2, 3, 4, 5, 6, 7 }
     * => { 1, 2, 3, 4, 5, 6, 7, 8 }
     * => { 1, 2, 3, 4, 5, 6, 7, 8, 9 }
     */
    for (int i = 0; i < 10; i++)
    {
        std::cout << smallestK(arr, i) << std::endl;
    }

    return 0;
}
