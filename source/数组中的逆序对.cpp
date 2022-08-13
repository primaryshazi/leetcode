#include <iostream>
#include <vector>
#include <functional>

int count = 0;

void merge(std::vector<int> &array, int left, int mid, int right, std::vector<int> &tmp)
{
    int lIdx = left;
    int rIdx = mid + 1;
    int index = 0;

    // 将数组分为两组，按大小归并入原数组
    while (lIdx <= mid && rIdx <= right)
    {
        if (array[lIdx] <= array[rIdx])
        {
            tmp[index++] = array[lIdx++];
        }
        else
        {
            count += mid - lIdx + 1;
            tmp[index++] = array[rIdx++];
        }
    }

    while (lIdx <= mid)
    {
        tmp[index++] = array[lIdx++];
    }

    while (rIdx <= right)
    {
        tmp[index++] = array[rIdx++];
    }

    index = 0;
    while (left <= right)
    {
        array[left++] = tmp[index++];
    }
};

void mg_sort(std::vector<int> &array, int left, int right, std::vector<int> &tmp) {
    if (left < right)
    {
        int mid = (right + left) >> 1;
        mg_sort(array, left, mid, tmp);
        mg_sort(array, mid + 1, right, tmp);
        merge(array, left, mid, right, tmp);
    }
};


void merge_sort(std::vector<int> &array)
{
    int length = static_cast<int>(array.size());
    if (length < 2)
    {
        return;
    }

    std::vector<int> tmp(length);

    mg_sort(array, 0, length - 1, tmp);
}

int reversePairs(std::vector<int> &nums)
{
    count = 0;
    merge_sort(nums);

    return count;
}

int main()
{
    std::vector<int> vi = { 1, 4, 7, 2, 3, 5, 6 };

    /**
     * => 6
     */
    std::cout << reversePairs(vi) << std::endl;

    return 0;
}
