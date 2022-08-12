#include <iostream>
#include <vector>

double findMedianSortedArrays(const std::vector<int> &nums1, const std::vector<int> &nums2)
{
    int m = nums1.size();
    int n = nums2.size();
    int len = m + n;
    int last = 0;
    int current = 0;
    int x = 0;
    int y = 0;

    // 遍历两个数组长度的一半
    for (int i = 0; i <= len / 2; i++)
    {
        last = current;     // 记录上一个值

        // 当数组1未遍历完成且有不大于数组2的元素，则继续遍历数组1，否则遍历数组2
        if (x < m && (y >= n || nums1[x] < nums2[y]))
        {
            current = nums1[x++];
        }
        else
        {
            current = nums2[y++];
        }
    }

    /**
     * 偶数时，用相邻两数相加
     * 基数时，用当前数即可
     */
    if ((len & 1) == 0)
    {
        return (last + current) / 2.0;
    }
    else
    {
        return current;
    }
}

int main()
{
    std::vector<int> nums1 = { 1, 2, 3, 4, 5 };
    std::vector<int> nums2 = { 1, 3, 5, 7, 9 };
    std::vector<int> nums3 = { 0, 2, 4, 6, 8, 10 };

    /**
     * => 3.5
     * => 4
     * => 5
     */
    std::cout << findMedianSortedArrays(nums1, nums2) << std::endl;
    std::cout << findMedianSortedArrays(nums1, nums3) << std::endl;
    std::cout << findMedianSortedArrays(nums2, nums3) << std::endl;

    return 0;
}
