#include <iostream>
#include <vector>

void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
{
    int mIndex = m - 1;
    int nIndex = n - 1;
    int index = m + n - 1;

    // 从数组尾部开始，将最大的元素依次防止于nums1中，从后向前不会导致nums1前部分元素被覆盖
    while (mIndex > 0 || nIndex >= 0)
    {
        if (mIndex < 0)
        {
            nums1[index] = nums2[nIndex];
            --nIndex;
        }
        else if (nIndex < 0)
        {
            nums1[index] = nums1[mIndex];
            --mIndex;
        }
        else
        {
            if (nums1[mIndex] > nums2[nIndex])
            {
                nums1[index] = nums1[mIndex];
                --mIndex;
            }
            else
            {
                nums1[index] = nums2[nIndex];
                --nIndex;
            }
        }
        --index;
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
    std::vector<int> nums1 = { 1, 2, 3, 4, 5, 6, 7, 0, 0, 0 };
    std::vector<int> nums2 = { 3, 4, 5 };

    merge(nums1, nums1.size() - nums2.size(), nums2, nums2.size());

    /**
     * => { 1, 2, 3, 3, 4, 4, 5, 5, 6, 7 }
     */
    std::cout << nums1 << std::endl;

    return 0;
}
